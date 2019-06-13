'''
ind2.py

For analyzing the raw calls to the Network Direct Card
by parsing the JSON log file
'''
import os
from typing import Iterator
import click
import ijson

def a_filter(prefix, event, value):
    'Returns true for comments starting with "IND2"'
    return (prefix, event) == ('item.comment', 'string') and value.startswith('IND2')

def isok(path: str) -> bool:
    'checks to see if the file ends with "]\n"'
    with open(path, 'rt') as fobj:
        count = 3
        rc1 = fobj.seek(0, os.SEEK_END)
        fobj.seek(rc1 - count, os.SEEK_SET)
        return fobj.read() == ']\n'

def fix(path: str) -> None:
    'appends "]\n" to the end of the file'
    with open(path, 'at') as fobj:
        fobj.write("]\n")

def get_ind2s(json_path: str) -> Iterator[str]:
    '''
Returns a generator of IND2* function names found in the
comment fields of a JSON file
    '''
    with open(json_path, 'r') as src:
        parser = ijson.parse(src)
        for prefix, event, value in parser:
            if a_filter(prefix, event, value):
                yield value.split()[0]

def summarize(path: str) -> None:
    'summarize the IND2 Api usage counts'
    data = {}
    for ind2 in get_ind2s(path):
        try:
            data[ind2] += 1
        except KeyError:
            data[ind2] = 1
    for (key, value) in data.items():
        print(key, value)

def trace(path: str) -> None:
    'Trace the IND2 API usage'
    for ind2 in get_ind2s(path):
        print(ind2)

@click.command()
@click.option("--path", type=str, help="path to JSON file", prompt=True)
@click.option("--method", type=click.Choice(['trace', 'summarize']), default='summarize', help = "method to apply")
def main(path: str, method: str) -> None:
    '''
Entry Point
    '''
    if method == 'summarize':
        summarize(path)
    else:
        trace(path)

if __name__ == '__main__':
    # pylint: disable=no-value-for-parameter
    main()
