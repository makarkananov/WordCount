# Лабораторная работа. Утилита WordCount

## Задача.	

Реализовать [утилиту](https://ru.wikipedia.org/wiki/%D0%A3%D1%82%D0%B8%D0%BB%D0%B8%D1%82%D0%B0) WordCount подсчитывающую количество строк, слов и байт для указанного файла и выводить эту информацию в поток вывода. 	
Программа должна поддерживать следующие опции:

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

## Примечание.
Для реализации утилиты потребуется воспользоваться стандартной библиотекой вводы\вывода ([описание](https://en.cppreference.com/w/cpp/io/basic_ifstream)).
Пример того, как можно организовать  парсинг аргументов командной строки, можно посмотреть [здесь](http://www.cplusplus.com/articles/DEN36Up4/).
 

**!NB. Задачи с * для первого полупотока**

## Deadline 

1. 25.09.22 24:00 - 0.8
2. 02.10.22 24:00 - 0.65
3. 09.10.22 24:00 - 0.5



