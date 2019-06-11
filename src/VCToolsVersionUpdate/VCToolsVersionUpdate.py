
'''
For updating the value of <VCToolsVersion> in Directory.Build.props
'''
import os
import re
from typing import Iterator
# pylint: disable=import-error
import click

def scantree(root: str) -> Iterator[str]:
  '''
  iterator of all the file paths underneath the root directory
  '''
  with os.scandir(root) as iterator:
    for entry in iterator:
      if entry.is_dir(follow_symlinks=False):
        yield from scantree(entry.path)
      else:
        yield entry

def get_root_dir() -> str:
  '''
  Returns a string containing the path to the root
  of the Microsoft Visual Studio directory
  '''
  root = os.environ['ProgramFiles(x86)']
  return os.path.join(root, 'Microsoft Visual Studio')

def get_versions() -> Iterator[str]:
  '''
  Returns a genertor of all the compiler versions
  '''
  pattern = r".+\\msvc\\(?P<version>[0-9.]+)\\bin\\.+\\cl\.exe"
  compiled_re = re.compile(pattern)
  root = get_root_dir()
  for entry in scantree(root):
    a_match = compiled_re.match(entry.path.lower())
    if a_match:
      yield a_match['version']

def work(path: str, version: str) -> None:
  '''
  Replaces the version number in Directory.Build.props
  '''
  with open(path, 'r') as fobj:
    block = fobj.read()
  pattern = r'<VCToolsVersion>.+</VCToolsVersion>'
  repl = r'<VCToolsVersion>' + version + r'</VCToolsVersion>'
  new_block = re.sub(pattern, repl, block)
  os.rename(path, path + ".old")
  with open(path, 'w') as fobj:
    fobj.write(new_block)

@click.command()
@click.option('--path', help='path to Directory.Build.props', prompt=True)
def main(path: str) -> None:
  '''
Determines the installed version of Visual Studio Tools
then updatess <VCToolsVersion> in Directoy.Build.props

The original version will be stored in Directory.Build.props.old
  '''
  versions = list({v for v in get_versions()})
  count = len(versions)
  if count == 0:
    print("No versions were found")
  elif count == 1:
    version = versions[0]
    work(version=version, path=path)
  else:
    print("multiple versions were found")

if __name__ == '__main__':
  #pylint: disable=no-value-for-parameter
  main()
