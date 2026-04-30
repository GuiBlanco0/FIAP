import pandas as pd

dados = {
    'Produto': ['A', 'B', 'C', 'D', 'E', 'F'],
    'Preço': [50, 200, 150, 3000, 80, 5000],
    'Quantidade': [2, 1, 3, 1, 10, 1]
}

df = pd.DataFrame(dados)
df['Valor Total'] = df['Preço'] * df['Quantidade']
df['Alerta'] = df['Valor Total'].apply(lambda x: 'Suspeita' if x > 2000 else 'Normal')

resumo = pd.DataFrame({
    'Indicador': ['Média', 'Máximo', 'Mínimo'],
    'Valor Total (R$)': [
        df['Valor Total'].mean(),
        df['Valor Total'].max(),
        df['Valor Total'].min()
    ]
})

print("=== RESUMO DE INDICADORES ===")
print(resumo.to_string(index=False))

with pd.ExcelWriter('relatorio_vendas.xlsx', engine='openpyxl') as writer:
    df.to_excel(writer, sheet_name='Dados Completos', index=False)
    resumo.to_excel(writer, sheet_name='Resumo', index=False)

print("\nArquivo 'relatorio_vendas.xlsx' exportado com sucesso!")
print("  - Aba 1: Dados Completos")
print("  - Aba 2: Resumo")