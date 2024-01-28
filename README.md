# ccwc

A simplified version of the Unix command line tool `wc` written in C++.

`ccwc` is similar to the original `wc` in that it is a command line tool that allows you to count the number of bytes, lines, and words in the file specified by the `File` parameter.

## Usage

`ccwc [-OPTION] [FILE]`

If `OPTION` is not specified, it prints the line, word, and byte count in this same order of the file specified by the `FILE` parameter.

### Example usage
`ccwc test.txt` 

`ccwc` supports the following `Flags` as of this time:

|    Flag     |        Description         |      
| ----------- |:--------------------------:|
|    -c       | print the byte count       |
|    -w       | print the word count       |
|    -l       | print the newline count    |

### Example usage

`ccwc -c test.txt`

The above command prints the number of bytes in `test.txt`
