# CpTemplates
Some boring code which i don't want to write again 


## Debug Flags for geany
For printing debug tags 
```g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -DLOCAL```
For not printing debug flags 
```g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result```
