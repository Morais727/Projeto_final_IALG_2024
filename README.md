# Sistema de Cadastro em Arquivos com Ordenação

Este é o repositório para o **Projeto Prático de Cadastro em Arquivos com Ordenação**, desenvolvido como parte da disciplina de Introdução à Algoritmos e Estruturas de Dados em C++. O projeto utiliza um conjunto de dados real do **Inside Airbnb**, com informações detalhadas sobre listagens de hospedagens em Los Angeles, Califórnia.

---

## Objetivo do Projeto

O objetivo é implementar um sistema robusto de cadastro e manipulação de dados, utilizando arquivos binários. As principais funcionalidades incluem:

- Importação e exportação de dados no formato CSV.
- Manipulação eficiente de dados utilizando arquivos binários.
- Busca, inserção, alteração e remoção de registros.
- Ordenação e busca binária para otimização de consultas.
- Redimensionamento dinâmico de estruturas para suporte a grandes volumes de dados.

---

## Tema e Dataset

### Tema: **Listagens de Los Angeles Airbnb**

Este projeto utiliza um dataset real do **Inside Airbnb**, atualizado em **4 de setembro de 2024**, que contém informações detalhadas sobre hospedagens em Los Angeles.

- **Fonte:** [Inside Airbnb - Los Angeles](https://insideairbnb.com/get-the-data/)
- **Quantidade de colunas:** 25 (detalhadas no decorrer do projeto).

### Campos Utilizados

Os campos selecionados para este projeto são:

- **id:** Identificador único (long long).
- **nome:** Nome da propriedade (string com espaços).
- **host_id:** Identificador único do anfitrião (long long).
- **host_nome:** Nome do anfitrião (string com espaços).
- **host_desde:** Data de cadastro do anfitrião (string com espaços).
- **host_resposta_tempo:** Tempo médio de resposta do anfitrião (string com espaços).
- **host_resposta_taxa:** Taxa de resposta do anfitrião (float).
- **host_is_superhost:** Indica se o anfitrião é um superhost (char).
- **bairro_limpo:** Bairro onde está localizada a propriedade (string com espaços).
- **acomoda:** Capacidade de acomodação (int).
- **banheiros:** Quantidade de banheiros (int).

---

## Funcionalidades Implementadas

1. **Importação e Exportação de Arquivos**:
   - Importar os dados do dataset inicial no formato CSV.
   - Exportar os dados para um arquivo CSV atualizado.
   - Armazenar e manipular os dados em um arquivo binário.

2. **Cadastro de Novos Registros**:
   - Inserir novos registros no sistema.
   - Inserção ordenada para suportar busca binária eficiente.

3. **Busca de Registros**:
   - Consultar registros com base em dois critérios: nome e bairro.
   - Implementação de busca binária (recursiva e iterativa).

4. **Alteração e Remoção**:
   - Alterar informações de registros existentes.
   - Remoção lógica e física de registros.

5. **Ordenação de Registros**:
   - Ordenar os registros por:
     - Nome da propriedade.
     - Capacidade de acomodação.
   - Ordenação utilizando algoritmos eficientes:
     - Quick Sort
     - Merge Sort
     - Shell Sort

6. **Exibição de Dados**:
   - Exibir todos os registros ou uma faixa específica selecionada pelo usuário.
   - Mostrar os registros na ordem em que estão armazenados.

7. **Gravação de Alterações**:
   - Salvar alterações realizadas (inserções, exclusões e alterações) no arquivo binário.

---

## Estrutura do Projeto

```
Sistema_Cadastro_Airbnb/
│
├── src/                    # Código-fonte do projeto
│   ├── main.cpp            # Arquivo principal da aplicação
│   ├── bin/                # Arquivos binários gerados
│   ├── utils/              # Funções auxiliares
│   │   ├── leitura.cpp     # Manipulação de leitura do arquivo binário
│   │   ├── escrita.cpp     # Manipulação de escrita no arquivo binário
│   │   ├── ordenacao.cpp   # Algoritmos de ordenação
│   │   ├── busca.cpp       # Algoritmos de busca binária
│   │   └── utils.h         # Cabeçalho com declarações
│   └── ...                 
│
├── docs/                   # Documentação do projeto
│   ├── relatorio.pdf       # Relatório do projeto
│   ├── estrutura_dados.md  # Explicação das estruturas
│   ├── requisitos.md       # Requisitos e especificações
│   └── ...                 
│
├── data/                   # Dados de entrada e saída
│   ├── input.csv           # Arquivo CSV de entrada
│   ├── output.csv          # Arquivo CSV gerado
│   └── exemplo.bin         # Arquivo binário de exemplo
│
├── tests/                  # Casos de teste
│   └── test_cases.txt      # Testes planejados e resultados esperados
│
├── README.md               # Documento explicativo
└── LICENSE.md              # Licença do projeto
```

---

## Como Executar

### Pré-requisitos

- Compilador compatível com C++11 ou superior (ex.: GCC).
- Sistema operacional Linux.
- Git para versionamento do código.

### Passos

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/sistema_cadastro_airbnb.git
   ```
2. Navegue para o diretório:
   ```bash
   cd sistema_cadastro_airbnb
   ```
3. Compile o código:
   ```bash
   g++ src/main.cpp -o sistema_cadastro
   ```
4. Execute a aplicação:
   ```bash
   ./sistema_cadastro
   ```

---

## Relatório

O relatório do projeto está disponível no arquivo `docs/relatorio.pdf`. Ele contém:

- Introdução ao projeto e ao tema escolhido.
- Descrição das estruturas de dados utilizadas.
- Explicação da lógica e do fluxo do programa.
- Relato dos acertos e dificuldades enfrentadas.
- Conclusão com os resultados alcançados.

---

## Contribuição

Contribuições são bem-vindas! Para colaborar:

1. Faça um fork do repositório.
2. Crie uma nova branch para suas alterações:
   ```bash
   git checkout -b minha-alteracao
   ```
3. Faça suas alterações e comente:
   ```bash
   git commit -m "Descrição da alteração"
   ```
4. Envie sua branch:
   ```bash
   git push origin minha-alteracao
   ```
5. Abra um Pull Request.

---

## Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo [LICENSE.md](LICENSE.md) para mais detalhes.
