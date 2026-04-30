import pandas as pd

# Dados das máquinas
dados = {
    'Máquina': [1, 2, 3, 4, 5],
    'Consumo Total (KWh)': [120, 450, 300, 800, 150],
    'Horas de Operação': [10, 20, 15, 40, 8]
}

df = pd.DataFrame(dados)

# Calcular consumo por hora
df['Consumo/Hora (KWh/h)'] = df['Consumo Total (KWh)'] / df['Horas de Operação']

# Classificar eficiência
def classificar(consumo_hora):
    if consumo_hora < 20:
        return 'Eficiente'
    elif consumo_hora <= 40:
        return 'Moderado'
    else:
        return 'Ineficiente'

df['Eficiência'] = df['Consumo/Hora (KWh/h)'].apply(classificar)

# Exportar para Excel
with pd.ExcelWriter('eficiencia_maquinas.xlsx', engine='openpyxl') as writer:
    df.to_excel(writer, sheet_name='Eficiência das Máquinas', index=False)

print("=== EFICIÊNCIA ENERGÉTICA DAS MÁQUINAS ===")
print(df.to_string(index=False))

# Indicadores no terminal
maquina_mais_ineficiente = df.loc[df['Consumo/Hora (KWh/h)'].idxmax(), 'Máquina']
maquina_menos_ineficiente = df.loc[df['Consumo/Hora (KWh/h)'].idxmin(), 'Máquina']
consumo_medio = df['Consumo/Hora (KWh/h)'].mean()
consumo_total_diario = df['Consumo Total (KWh)'].sum()

print(f"\nMáquina MAIS ineficiente: Máquina {maquina_mais_ineficiente}")
print(f"Máquina MENOS ineficiente (mais eficiente): Máquina {maquina_menos_ineficiente}")
print(f"Consumo médio por hora: {consumo_medio:.2f} KWh/h")
print(f"Consumo total diário: {consumo_total_diario} KWh")

print("\nArquivo 'eficiencia_maquinas.xlsx' exportado com sucesso!")