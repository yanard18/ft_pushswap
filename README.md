```mermaid
graph TD
    Start([Start]) --> Parser{Validate & Parse}
    Parser -- "invalid" --> Fail
    Parser --> CalculateDisorder["calculate_disorder()"]
    CalculateDisorder --> IsSorted{"disorder == 0"} 
    IsSorted -- "false" --> SelectMode
    IsSorted -- "true" --> End2(["return 0"])
    SelectMode -- "--simple" --> Simple
    SelectMode -- "--medium" --> Medium
    SelectMode -- "--complex" --> Complex
    SelectMode -- "--adaptive" --> CalculatedDisorder{"disorder value"}
    Simple --> HasBench
    Medium --> HasBench
    Complex --> HasBench{HasBench}
    HasBench -- "true" --> PrintBench
    HasBench -- "false" --> End(["return 0"])
    PrintBench["Print Performance Benchmark"] --> End
    CalculatedDisorder -- "disorder < 0.2" --> Simple
    CalculatedDisorder -- "0.2 <= disorder < 0.5" --> Medium
    CalculatedDisorder -- "disorder >= 0.5" --> Complex
    Fail([return 1])
```
