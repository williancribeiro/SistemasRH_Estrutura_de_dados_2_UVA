# 📊 Sistema de Gestão de Funcionários (C - Árvore Binária)

Projeto feito para a matéria de Estrutura de Dados, referente ao curso de Engenharia de Computação, ministrado pelo professor André Oliveira.

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Status](https://img.shields.io/badge/status-em%20desenvolvimento-yellow)
![License](https://img.shields.io/badge/license-MIT-green)

Este projeto implementa um sistema simples de **cadastro, consulta, alteração e exclusão de funcionários** usando uma **árvore binária de busca (BST)** em linguagem **C**. É voltado para fins didáticos, ideal para estudantes que desejam entender estruturas de dados e manipulação dinâmica de memória.

---

## 📚 Funcionalidades

- ✅ Inserção de funcionário  
- 🔍 Consulta de dados por nome  
- 📃 Listagem de todos os funcionários em ordem alfabética  
- 💰 Listagem de funcionários com salário maior que um valor  
- 📝 Alteração de dados de um funcionário  
- ❌ Exclusão de funcionário  
- 🧹 Liberação da memória da árvore  

---

## 🧠 Estrutura de Dados

```c
typedef struct Funcionario {
    char nome[50];
    int idade;
    float salario;
    struct Funcionario* esquerda;
    struct Funcionario* direita;
} Funcionario;
```

O sistema organiza os dados usando uma árvore binária de busca, ordenando os funcionários alfabeticamente pelo nome.

---

## 🖥️ Exemplo de Menu

```
#########################
=-=-=-Sistemas RH:=-=-=-
#########################

1. Incluir funcionario
2. Consultar dados de um funcionario
3. Listar funcionarios com salario maior que um valor
4. Listar todos os funcionarios
5. Excluir funcionario
6. Alterar dados do funcionario
7. Sair
```

---

## 🚀 Como Executar

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/sistema-funcionarios-c.git
   cd sistema-funcionarios-c
   ```

2. Compile o código:
   ```bash
   gcc -o sistema_rh sistema_rh.c
   ```

3. Execute:
   ```bash
   ./sistema_rh
   ```

> 💡 **Dica**: renomeie `sistema_rh.c` se o nome do seu arquivo for diferente.

---

## 📁 Dados Iniciais

O programa já inicia com uma árvore preenchida com os seguintes funcionários:

- Alice  
- Carlos  
- Marcos  
- Willian  
- Rodrigo  
- Marcelo  
- Evellin  
- Helen  
- Mariana  
- Julia  

---

## 🧪 Requisitos

- GCC ou qualquer compilador C compatível
- Terminal para execução

---

## 🤝 Contribuindo

Contribuições são bem-vindas!  
Sinta-se livre para **abrir issues**, propor melhorias ou enviar um **pull request**.

---

## 📄 Licença

Este projeto está licenciado sob a [MIT License](LICENSE).


---
