import sys
import os
import pandas as pd

# Fix encoding no terminal Windows
if sys.platform == 'win32':
    sys.stdout.reconfigure(encoding='utf-8')

# Dados (reutilizando da questão 1)
dados = {
    'Produto': ['A', 'B', 'C', 'D', 'E', 'F'],
    'Preço': [50, 200, 150, 3000, 80, 5000],
    'Quantidade': [2, 1, 3, 1, 10, 1]
}

df = pd.DataFrame(dados)
df['Valor Total'] = df['Preço'] * df['Quantidade']
df['Alerta'] = df['Valor Total'].apply(lambda x: 'Suspeita' if x > 2000 else 'Normal')

# Criar resumo com Média, Máximo e Mínimo
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

# Exportar para Excel — salva na mesma pasta do script
output_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'relatorio_vendas.xlsx')

with pd.ExcelWriter(output_path, engine='openpyxl') as writer:
    df.to_excel(writer, sheet_name='Dados Completos', index=False)
    resumo.to_excel(writer, sheet_name='Resumo', index=False)

print(f"\nArquivo exportado com sucesso em: {output_path}")
print("  - Aba 1: Dados Completos")
print("  - Aba 2: Resumo")