import csv

# Função para verificar se uma string contém apenas números
def is_number(value):
    try:
        float(value)  # Tenta converter para float
        return True
    except ValueError:
        return False

# Função para processar o CSV
def process_csv(input_file, output_file):
    with open(input_file, mode='r', newline='', encoding='utf-8') as infile, open(output_file, mode='w', newline='', encoding='utf-8') as outfile:
        csv_reader = csv.reader(infile)
        csv_writer = csv.writer(outfile)

        for row in csv_reader:
            # Verifica se a linha tem pelo menos 3 colunas
            if len(row) >= 3:
                # Se a terceira coluna não for um número
                if not is_number(row[2]):
                    # Concatenar a segunda e terceira coluna, removendo a vírgula
                    row[1] = row[1] + " " + row[2]  # Junta a coluna 2 e 3 com espaço entre elas
                    del row[2]  # Remove a coluna 3 após concatenar
            # Escreve a linha (modificada ou não) no arquivo de saída
            csv_writer.writerow(row)

# Exemplo de uso:
input_file = 'saida123.csv'
output_file = 'saida1234.csv'
process_csv(input_file, output_file)
