'''
printlog.py

Pretty printing the logging JSON file
'''
import sys
import json
# pylint: disable=import-error
import click

@click.command()
@click.option('--path', prompt=True, help='path to JSON log file')
def main(path: str) -> None:
    '''
    Print the contents of the JSON log
    file so that the depth of the calls
    are represeted by indentation.
    '''
    indent = '|   '
    with open(path, 'r') as fobj:
        buf = fobj.read()
    if not buf.endswith(']\n'):
        buf += ']\n'
    log = json.loads(buf)
    level = 0
    for entry in log:
        comment = entry['comment']
        if comment.startswith('Entering'):
            print("{0}{1}".format(indent * level, comment))
            level += 1
        elif comment.startswith('Exiting'):
            level -= 1
            print("{0}{1}".format(indent * level, comment))
        else:
            print("{0}{1}".format(indent * level, comment))

if __name__ == '__main__':
    # pylint: disable=no-value-for-parameter
    main()

