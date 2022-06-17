# C - Simple Monty ByteCode Interpreter

## Description

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language.

There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```

push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$

```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```

push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$

```

## Compilation

The program is compiled using the following command:  

`gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`

## Usage

`./monty file`

where `file` is the path to the file containing Monty byte code

### Supported Operations

The Simple Monty ByteCode Interpreter supports the following operations:

| Operation  | Description |
| ---------- | ----------- |
| `push <n>` | Pushes an integer `n` to the stack |
| `pall` | Prints all the values in the stack |
| `pint` | Prints the value at the top of the stack |
| `pop` | Removes the top element of the stack |
| `swap` | Swaps the top two elements of the stack |
| `add` | Adds the top two elements of the stack |
| `nop` | Does nothing |
| `sub` | Subtracts the top element of the stack from the second top element of the stack |
| `div` | Divides the second top element of the stack by the top element of the stack |
| `mul` | Multiplies the second top element of the stack with the top element of the stack |
| `mod` | Computes the remainder of the division of the second top element of the stack by the top element of the stack |
| `pchar` | Prints the char at the top of the stack |
| `pstr` | Prints the the string starting at the top of the stack |

### Examples

push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall

3
2
1
2
1
1

```

```

push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 108
push 111
push 111
push 104
push 99
push 83
pstr

School

```

```

push 1
push 2
push 3
pall
add
pall

3
2
1
5
1

```

## Credits

Written by
- [Githinji Kingori](https://github.com/GMercury)
