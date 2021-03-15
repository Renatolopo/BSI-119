import pandas as pd
import pymysql
import numpy as np

columns_name = ['Gestor', 'Canal de Origem', 'Região', 'UF', 'Cidade', 'Sexo',  'Faixa Etária',
                'Ano Abertura', 'Mês Abertura', 'Data Abertura', 'Hora Abertura', 'Data Resposta', 'Hora Resposta',
                'Data Análise', 'Hora Análise', 'Data Recusa', 'Hora Recusa', 'Data Finalização', 'Hora Finalização',
                'Prazo Resposta', 'Prazo Analise Gestor', 'Tempo Resposta', 'Nome Fantasia', 'Segmento de Mercado',
                'Área', 'Assunto', 'Grupo Problema', 'Problema', 'Como Comprou Contratou', 'Procurou Empresa', 'Respondida',
                'Situação', 'Avaliação Reclamação', 'Nota do Consumidor', 'Análise da Recusa', 'Edição de Conteúdo',
                'Interação do Gestor', 'Total']


def replace_nan(row):
    for column in columns_name: 
        if type(row[column]) != str and np.isnan(row[column]):
            row[column] = None
    return row


df = pd.read_csv('./dadosgovbr---2017.csv', sep=';', encoding='latin-1')
con = pymysql.connect(host='localhost',
                      user='root',
                      password='',
                      db='dadosgovbr')



cursor = con.cursor()                        

for i in range(len(df)):
    row = replace_nan(df.iloc[i])

    try:
        cursor.execute('INSERT INTO dados_gov (Gestor, Canal_de_Origem,\
            Regiao, UF, Cidade, Sexo, Faixa_Etaria, Ano_Abertura, Mes_Abertura,\
            Data_Abertura, Hora_Abertura, Data_Resposta, Hora_Resposta, Data_Analise,\
            Hora_Analise, Data_Recusa, Hora_Recusa, Data_Finalizacao,\
            Hora_Finalizacao, Prazo_Resposta, Prazo_Analise_Gestor, Tempo_Resposta, Nome_Fantasia,\
            Segmento_de_Mercado, Area, Assunto, Grupo_Problema, Problema, Como_Comprou_Contratou,\
            Procurou_Empresa, Respondida, Situacao, Avaliacao_Reclamacao, Nota_do_Consumidor, \
            Analise_da_Recusa, Edicao_de_Conteudo, Interacao_do_Gestor, Total) \
            VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s,\
                 %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)', 
            (row['Gestor'],
            row['Canal de Origem'],
            row['Região'],
            row['UF'],
            row['Cidade'],
            row['Sexo'],
            row['Faixa Etária'],
            row['Ano Abertura'],
            row['Mês Abertura'],
            row['Data Abertura'],
            row['Hora Abertura'],
            row['Data Resposta'],
            row['Hora Resposta'],
            row['Data Análise'],
            row['Hora Análise'],
            row['Data Recusa'],
            row['Hora Recusa'],
            row['Data Finalização'],
            row['Hora Finalização'],
            row['Prazo Resposta'],
            row['Prazo Analise Gestor'],
            row['Tempo Resposta'],
            row['Nome Fantasia'],
            row['Segmento de Mercado'],
            row['Área'],
            row['Assunto'],
            row['Grupo Problema'],
            row['Problema'],
            row['Como Comprou Contratou'],
            row['Procurou Empresa'],
            row['Respondida'],
            row['Situação'],
            row['Avaliação Reclamação'],
            row['Nota do Consumidor'],
            row['Análise da Recusa'],
            row['Edição de Conteúdo'],
            row['Interação do Gestor'],
            row['Total']))

        print('Adicionado')

    except BaseException as e:
        print(f'Não adicionado ... {e}')
        continue
    con.commit()
con.close()
