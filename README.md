# CpTemplates

A collection of all the templates and configuration for my competitive programming setup

In future this will be one stop for all the templates which can easily be exported to different IDEs.

## Compilation commands


For printing debug tags 

```g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -DLOCAL```

For not printing debug flags 

```g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result```
