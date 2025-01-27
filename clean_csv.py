import pandas as pd
import re

def contains_non_latin(text):
    # Verifica se o texto contém caracteres não latinos (japonês, hebraico, etc.)
    # A expressão regular cobre:
    # - Hiragana, Katakana e Kanji (Japonês)
    # - Alfabeto Hebraico
    return bool(re.search(r'[^\x00-\x7F]+', text))  # Detecta qualquer caractere não latino (fora do intervalo ASCII básico)

def clean_csv(file_path, output_path):
    # Ler o arquivo CSV com verificação rigorosa do número de colunas
    with open(file_path, 'r', encoding='utf-8') as f:
        header = f.readline().strip().split(',')

    # Carregar o CSV novamente com as colunas corretas
    df = pd.read_csv(file_path, usecols=header, dtype=str)

    # Remover linhas onde 'bathrooms' ou 'bedrooms' estão vazias ou nulas
    df_cleaned = df.dropna(subset=['bathrooms', 'bedrooms'])

    # Remover espaços em branco e converter as colunas para numérico (tratando erros)
    df_cleaned['bathrooms'] = pd.to_numeric(df_cleaned['bathrooms'].str.strip(), errors='coerce').fillna(0).astype(int)
    df_cleaned['bedrooms'] = pd.to_numeric(df_cleaned['bedrooms'].str.strip(), errors='coerce')

    # Remover as linhas onde 'bathrooms' ou 'bedrooms' são 0 ou NaN (valores inválidos)
    df_cleaned = df_cleaned[(df_cleaned['bathrooms'] > 0) & (df_cleaned['bedrooms'] > 0)]

    # Remover linhas que contêm caracteres não latinos (japonês, hebraico, etc.)
    df_cleaned = df_cleaned[~df_cleaned.apply(lambda row: row.astype(str).apply(contains_non_latin).any(), axis=1)]

    # Salvar o novo arquivo sem as linhas inválidas
    df_cleaned.to_csv(output_path, index=False)

    print(f"Arquivo limpo salvo em: {output_path}")

# Exemplo de uso
input_file = "dados_limpos.csv"  # Substitua pelo caminho do seu arquivo
output_file = "dados_limpos1.csv"  # Nome do arquivo de saída
clean_csv(input_file, output_file)
