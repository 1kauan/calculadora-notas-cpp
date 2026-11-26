# Calculadora de notas (C++)

Aplicação de terminal para registrar estudantes e notas, validar valores de 0 a 10 e calcular médias e situação final. Projeto de estudo para praticar funções, vetores, estruturas e validação de entrada.

## Requisitos

- Compilador C++17 (GCC, Clang ou MSVC)

## Compilar e executar

```sh
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o calculadora-notas
./calculadora-notas
```

No Windows, execute `calculadora-notas.exe` depois da compilação.

## Regras

- Cada pessoa recebe duas notas entre 0 e 10.
- A média é a média aritmética simples.
- A situação é “Aprovado” para média igual ou superior a 7; abaixo disso, “Reforço”.

## Próximas melhorias

- Persistir os registros em arquivo CSV.
- Permitir três ou mais avaliações configuráveis.
- Separar a lógica em arquivos `.hpp` e `.cpp`.
