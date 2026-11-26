#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

struct Estudante {
    std::string nome;
    double nota1{};
    double nota2{};

    double media() const {
        return (nota1 + nota2) / 2.0;
    }
};

double lerNota(const std::string& rotulo) {
    double nota{};
    while (true) {
        std::cout << rotulo << " (0 a 10): ";
        if (std::cin >> nota && nota >= 0.0 && nota <= 10.0) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return nota;
        }
        std::cout << "Entrada inválida. Informe um número entre 0 e 10.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    std::vector<Estudante> turma;
    int quantidade{};
    std::cout << "=== Calculadora de notas ===\nQuantidade de estudantes: ";
    while (!(std::cin >> quantidade) || quantidade < 1 || quantidade > 100) {
        std::cout << "Informe uma quantidade de 1 a 100: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < quantidade; ++i) {
        Estudante estudante;
        std::cout << "\nEstudante " << (i + 1) << " — nome: ";
        std::getline(std::cin, estudante.nome);
        while (estudante.nome.empty()) {
            std::cout << "O nome não pode ficar vazio. Digite novamente: ";
            std::getline(std::cin, estudante.nome);
        }
        estudante.nota1 = lerNota("Nota 1");
        estudante.nota2 = lerNota("Nota 2");
        turma.push_back(estudante);
    }

    double somaMedias = 0.0;
    std::cout << "\n=== Resultado ===\n" << std::left << std::setw(28) << "Estudante"
              << std::right << std::setw(8) << "Média" << "  Situação\n";
    std::cout << std::string(48, '-') << '\n';
    for (const auto& estudante : turma) {
        const double media = estudante.media();
        somaMedias += media;
        std::cout << std::left << std::setw(28) << estudante.nome << std::right
                  << std::setw(8) << std::fixed << std::setprecision(2) << media
                  << "  " << (media >= 7.0 ? "Aprovado" : "Reforço") << '\n';
    }
    std::cout << "\nMédia da turma: " << std::fixed << std::setprecision(2)
              << somaMedias / turma.size() << '\n';
}
