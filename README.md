# Projeto Final de Introdução à Algoritmos 2024: Manipulação de Dados Binários

Bem-vindo ao repositório do **Projeto Final de Introdução à Algoritmos (IALG) 2024**! Este projeto aborda a **manipulação de dados binários** com base em um dataset real de listagens de hospedagens do Airbnb em Los Angeles.

---

## Objetivo do Projeto

O projeto visa consolidar os conhecimentos de algoritmos e programação aprendidos ao longo do curso, utilizando manipulação de arquivos binários como abordagem central. O objetivo é desenvolver um sistema capaz de:

- Ler, gravar e processar dados binários.
- Realizar consultas e análises de informações armazenadas em formato binário.
- Aplicar conceitos de otimização, estruturação de dados e algoritmos para resolver problemas reais.

---

## Descrição Geral

### Tema: Manipulação de Dados Binários

Este projeto utiliza um dataset real proveniente do **Inside Airbnb**, contendo informações detalhadas sobre listagens de hospedagens em Los Angeles, Califórnia, atualizado em **4 de setembro de 2024**. O objetivo é manipular e processar os dados de maneira eficiente utilizando arquivos binários.

### Dataset

- **Fonte**: [Inside Airbnb - Los Angeles](https://insideairbnb.com/get-the-data/)
- **Estrutura básica dos dados**:
  - **id**: (long long)
  - **nome**: (string com espaços)
  - **host_id**: (long long)
  - **host_nome**: (string com espaços)
  - **host_desde**: (string com espaços)
  - **host_resposta_tempo**: (string com espaços)
  - **host_resposta_taxa**: (float)
  - **host_is_superhost**: (char)
  - **bairro_limpo**: (string com espaços)
  - **acomoda**: (int)
  - **banheiros**: (int)

O dataset contém **25 colunas** no total, que serão detalhadas no decorrer do projeto.

---

## Estrutura do Projeto

O projeto será estruturado para facilitar o desenvolvimento e a compreensão do código, com destaque para a manipulação de arquivos binários.

```
Projeto_Final_IALG_2024/
│
├── src/                    # Código-fonte do projeto
│   ├── main.c              # Arquivo principal do sistema
│   ├── bin/                # Arquivos binários gerados
│   ├── utils/              # Funções auxiliares
│   │   ├── leitura.c       # Manipulação de leitura do arquivo binário
│   │   ├── escrita.c       # Manipulação de escrita no arquivo binário
│   │   └── consultas.c     # Consultas e filtros no dataset
│   └── ...                 
│
├── docs/                   # Documentação do projeto
│   ├── dataset_campos.md   # Descrição detalhada dos 25 campos
│   ├── requisitos.md       # Levantamento de requisitos
│   ├── especificacoes.md   # Especificações técnicas
│   └── ...                 
│
├── tests/                  # Casos de teste
│   └── test_cases.txt      # Testes planejados e resultados esperados
│
├── README.md               # Documento explicativo
└── LICENSE.md              # Licença do projeto
```

---

## Funcionalidades Planejadas

1. **Carregamento e Armazenamento**:
   - Carregar o dataset original e convertê-lo em um arquivo binário.
   - Salvar novas informações diretamente em formato binário.

2. **Consultas**:
   - Consultar registros com base em filtros (ex.: `bairro`, `acomodações`, etc.).
   - Realizar análises simples, como média de avaliações ou contagem de superhosts.

3. **Manipulação e Atualização**:
   - Alterar registros existentes.
   - Excluir registros de forma segura.

4. **Exibição**:
   - Visualizar registros de forma legível para o usuário.
   - Gerar relatórios simples com base nos dados processados.

---

## Tecnologias Utilizadas

- **Linguagem de programação**: C (ênfase em manipulação de arquivos binários).
- **Ambiente de desenvolvimento**: Dev-C++, GCC ou outra IDE compatível.
- **Ferramentas de controle de versão**: Git/GitHub.

---

## Como Executar o Projeto

### Pré-requisitos

Certifique-se de ter:
- Um compilador C (GCC, MinGW, etc.).
- Ferramentas de controle de versão (Git).

### Passos

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/projeto_final_IALG_2024.git
   ```
2. Navegue para o diretório:
   ```bash
   cd Projeto_Final_IALG_2024
   ```
3. Compile o código:
   ```bash
   gcc src/main.c -o manipulacao_binaria
   ```
4. Execute o programa:
   ```bash
   ./manipulacao_binaria
   ```

---

## Testes

Os testes serão realizados com base em casos específicos descritos no arquivo `tests/test_cases.txt`. Cada caso será executado para verificar:
- Leitura correta dos dados do arquivo binário.
- Escrita eficiente e precisa.
- Consultas e filtros de acordo com os critérios especificados.

---

## Contribuição

Contribuições são sempre bem-vindas! Para colaborar:

1. Faça um **fork** do repositório.
2. Crie uma nova branch para suas alterações:
   ```bash
   git checkout -b minha-feature
   ```
3. Faça suas alterações e comente o que foi modificado:
   ```bash
   git commit -m "Descrição da alteração"
   ```
4. Envie sua branch:
   ```bash
   git push origin minha-feature
   ```
5. Abra um **Pull Request** e descreva as alterações.

---

## Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo [LICENSE.md](LICENSE.md) para mais detalhes.
