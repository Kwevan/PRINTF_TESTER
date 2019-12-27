# ft_printf  (print formated)

* An attempt to recode the printf function
 

Only those flags are handled
* % [cspdiuxX%]
*  [0-.*]

| Type field | Description | Example - kickstarts | 
| ------------- |:-------------:| -----:| 
| %c | display a char [? - ?]| C | 
| %s | display char array | hallo |
| %p | display the adress of a pointer| 0x12a3dd3f |
| %d| display  an **int** | 2
| %i| same as %d | same same
| %x| display an **int** in hexa lowercase | 12a
| %x| display an **int** in hexa uppercase | 12A
| %%| display an %| %

 
|Flag| Description | Example
--- | --- | ---
|%[nb]s<br>%[nb]d|the displayed string must have a minimum lenght of nb, <br>if not, add **spaces** at the **beginning** of the string/number<br>to have the right lenght| printf("%s", "b") -> [b] <br> printf("%5s", "b") -> [&nbsp;&nbsp;&nbsp;&nbsp;b] <br> printf("%d", 7) -> [7]<br> printf("%5d", 7) -> [&nbsp;&nbsp;&nbsp;&nbsp;7] 
|%[nb1.nb2]s|nb1 is the min lenght, nb2 is the max lenght<br>if string's lenght < nb1, it will add **spaces** at the **beginning** of the string, <br> if string's lenght > nb2 it will be cropped down to nb2|
|%[.nb]s|nb is the max lenght, if the string is greater than nb, it will be cropped down to nb|
|%[.nb]d|nb is the min lenght, add 0 ad the beggining of the nb until we have nb lenght|
|%[*]s|exactly like %nbs but the number is an argument of printf|
|%[-nb]s|exactly like %nbs except that the spaces are print on the right of the string- overrides 0|
|%[0nb]d|- still override 0|
. (With number)| `display space to have the same lenght`| ft_printf("%5d"21);   display[     21]<br><br>ft_printf("%5.", 12345); output : [12345]
 .(With char array)| `display space to have the same lenght`| ft_printf("%5d"21) ;display[     21]<br><br>ft_printf("%5.", 12345); output : [12345]

 
| Flag | desc|
| --- | --- |  
| . | works with %s <br> doesn't work with %d |




[1]



