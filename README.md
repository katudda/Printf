<p align='center'>
<img src="ft_printfn.png">
</p>

# Printf
The aim of this projetc was to recreate the function printf using C language (stdio library)

Those are the format identifier's I needed to recode:

%  | type |
---|------|
%c | a single character				|
%s | a string of characters					|
%p | The void * pointer argument printed in hexadecimal				|
%d | print a decimal (base 10) number	|
%i | an integer in base 10				|
%u | an unsigned decimal (base 10) number		|
%x | a number in hexadecimal (base 16)|
%X | hex integer (uppercase)|
%% | a percent sign				|

And those are the flags:

flag| ? |
----|---|
num	| (number between % and the identifier) minimum field width						|
'-' 	| left justify 																	|
'0' 	| field padded with 0's instead of blanks										|
'.' 	| precision															|
'*' 	| indicates that the maximum or minimum field width will be passed as parameter	|

**For %d and %i, the precision is the minimum number of digits to print.**

**For %s, the precision is the maximum field width.**

## Contributing
Everyone can contribute to printf. Just send me a email, I will add you to contributors.