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




 
|U| Less | Pretty 
--- | --- | ---
|%[nb]s<br>%[nb]d|the displayed string must have a minimum lenght of nb, <br>if not, add **spaces** at the **beginning** of the string/number<br>to have the right lenght|
|%[.nb]|nb is the max lenght, if the string is greater than nb, it will be cropped down to nb|
. (With number)| `display space to have the same lenght`| ft_printf("%5d"21);   display[     21]<br><br>ft_printf("%5.", 12345); output : [12345]
 .(With char array)| `display space to have the same lenght`| ft_printf("%5d"21) ;display[     21]<br><br>ft_printf("%5.", 12345); output : [12345]


