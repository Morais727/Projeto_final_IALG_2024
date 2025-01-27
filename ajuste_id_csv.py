import csv

def substituir_primeira_coluna(input_csv, output_csv):
    with open(input_csv, mode='r', encoding='utf-8') as infile:
        reader = csv.reader(infile)
        dados = list(reader)

    # Substituir a primeira coluna pelo índice da linha (ignorando o cabeçalho se existir)
    for i, row in enumerate(dados):
        row[0] = str(i)  # Converte o índice para string

    with open(output_csv, mode='w', encoding='utf-8', newline='') as outfile:
        writer = csv.writer(outfile)
        writer.writerows(dados)

    print(f"Arquivo salvo como {output_csv}")

# Exemplo de uso
input_csv = 'dados_limpos.csv'  # Substitua pelo nome do seu arquivo CSV de entrada
output_csv = 'dados_limpos1.csv'

substituir_primeira_coluna(input_csv, output_csv)
