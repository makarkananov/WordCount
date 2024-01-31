# Утилита WordCount

## Описание	

Реализация [утилиты](https://ru.wikipedia.org/wiki/%D0%A3%D1%82%D0%B8%D0%BB%D0%B8%D1%82%D0%B0) WordCount подсчитывающая количество строк, слов и байт для указанного файла и вывод этой информации в поток вывода. 	
Программа поддерживает следующие опции:

**-l, --lines**    вывод только количества строк

**-c, --bytes**    вывод размера файла в байтах

**-w, --words**    вывод количества слов

**-m, --chars**     вывод количества букв*


Название файла и опции передаются через аргументы командной строки в следующем формате:

_**WordCount.exe [OPTION] filename [filename,.....]***_

Формат вывода (без заданных опций):
  lines words bytes filename
  
### Примеры запуска программы:
_WordCount.exe filename1_
 
_WordCount.exe filename1 filename2_

_WordCount.exe --words --lines filename1_

_WordCount.exe -l -c filename1_
 
_WordCount.exe -lwc filename1 filename2_

_WordCount.exe  filename1 filename2 -lw --bytes_ 



