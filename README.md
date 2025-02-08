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

- **Fonte:** [Inside Airbnb - Los Angeles](https://insideairbnb.com/get-the-data/).
- **Quantidade de colunas:** 25, conforme especificado abaixo.

### Campos do Dataset

1. **id:** Identificador único atribuído a cada propriedade.
2. **name:** Nome da propriedade listado pelo anfitrião.
3. **host_id:** Identificador único do anfitrião da propriedade.
4. **host_name:** Nome do anfitrião associado à propriedade.
5. **host_since:** Data em que o anfitrião se juntou ao Airbnb.
6. **host_response_time:** Tempo médio de resposta do anfitrião a consultas de hóspedes.
7. **host_response_rate:** Porcentagem de consultas respondidas pelo anfitrião.
8. **host_is_superhost:** Indica se o anfitrião é um Superhost (True/False).
9. **neighbourhood_cleansed:** Nome do bairro onde a propriedade está localizada.
10. **neighbourhood_group_cleansed:** Grupo ou distrito padronizado onde a propriedade está localizada.
11. **latitude:** Coordenada geográfica de latitude.
12. **longitude:** Coordenada geográfica de longitude.
13. **property_type:** Tipo de propriedade.
14. **room_type:** Tipo de quarto oferecido (ex.: Entire home/apt, Private room, Shared room).
15. **accommodates:** Número máximo de hóspedes que a propriedade pode acomodar.
16. **bathrooms:** Número de banheiros na propriedade.
17. **bedrooms:** Número de quartos na propriedade.
18. **beds:** Número de camas na propriedade.
19. **price:** Preço total com base no número mínimo de noites para reserva.
20. **minimum_nights:** Número mínimo de noites exigido para uma reserva.
21. **availability_365:** Número de dias que a propriedade está disponível para reserva nos próximos 365 dias.
22. **number_of_reviews:** Número total de avaliações recebidas pela propriedade.
23. **review_scores_rating:** Classificação média baseada nas avaliações dos hóspedes (5 é o valor máximo).
24. **license:** Licença, se aplicável.
25. **instant_bookable:** Indica se os hóspedes podem reservar a propriedade instantaneamente (True/False).

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
│   └── exemplo.bin         # Arquivo binário de exemplo
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
