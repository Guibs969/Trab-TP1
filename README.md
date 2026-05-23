# Trabalho Prático 1 - Modelagem C++

## Diagramas e Estrutura do Projeto

---

### 1. Diagrama de Classes (Domínios e Entidades)

Mapeamento das 4 entidades principais e suas associações. Os tipos dos atributos (ex: *Email, Nome, Codigo*) correspondem diretamente às **Classes de Domínio**.

```
classDiagram
	class Pessoa {
		-email : Email
		-nome : Nome
		-senha : Senha
		-papel : Papel
	}
	class Projeto {
		-codigo : Codigo
		-nome : Nome
		-inicio : Data
		-termino : Data
	}
	class PlanoDeSprint {
		-codigo : Codigo
		-objetivo : Texto
		-capacidade : Tempo
	}
	class HistoriaDeUsuario {
		-codigo : Codigo
		-titulo : Texto
		-papel : Texto
		-acao : Texto
		-valor : Texto
		-estimativa : Tempo
		-prioridade : Prioridade
		-estado : Estado
	}

	Projeto "1" -- "1" Pessoa : Proprietario de Produto
	Projeto "1" -- "1" Pessoa : Mestre Scrum
	Projeto "1" *-- "*" PlanoDeSprint : possui
	Projeto "1" o-- "*" HistoriaDeUsuario : contem
	PlanoDeSprint "1" o-- "*" HistoriaDeUsuario : contem
	HistoriaDeUsuario "*" -- "0..1" Pessoa : Desenvolvedor
```

---

### 2. Diagrama de Arquitetura (Módulos em Camadas)

O sistema utiliza arquitetura baseada em camadas. A comunicação entre Apresentação e Serviço é feita exclusivamente por **Interfaces (classes abstratas em C++)**.

```
flowchart TD
	subgraph CA [1. Camada de Apresentacao]
		A1[Classes Controladoras]
		A2[Interface do Utilizador]
	end

	subgraph IN [Interfaces C++]
		direction LR
		I1((IServicoAutenticacao))
		I2((IServicoPessoa))
		I3((IServicoProjeto))
	end

	subgraph CS [2. Camada de Servico]
		S1[Logica de Negocio]
		S2[(Contentores / BD)]
	end

	A1 -->|Consome metodos virtuais| IN
	A2 -->|Recolhe e valida dados| A1

	CS -.->|Herda e Implementa| IN
	S1 -->|Acede a dados| S2
```

---

### 3. Estrutura de Pastas do Projeto

Organização recomendada para o projeto em C++. Esta estrutura mapeia diretamente as **Entregas 1 a 6** do trabalho.

```
Projeto_TP1/
├── main.cpp                # Ponto de entrada (Chama a interface de Apresentação)
├── Doxyfile                # Arquivo de configuração do Doxygen
├── Projeto_TP1.cbp         # Arquivo do projeto (Code::Blocks)
│
├── Dominios/               # [ENTREGA 1] Atributos básicos validados
│   ├── Codigo.hpp / .cpp
│   ├── Data.hpp / .cpp
│   └── ... (Nome, Email, Texto, etc.)
│
├── Entidades/              # [ENTREGA 2] Objetos compostos pelos domínios
│   ├── Projeto.hpp / .cpp
│   ├── Pessoa.hpp / .cpp
│   └── ... (PlanoDeSprint, HistoriaDeUsuario)
│
├── Interfaces/             # [ENTREGA 3] Apenas cabeçalhos (Classes Abstratas Puras)
│   ├── IServicoPessoa.hpp
│   ├── IApresentacaoPessoa.hpp
│   └── ... (NÃO VAI .cpp AQUI)
│
├── Apresentacao/           # [ENTREGA 4] Telas, menus e coleta de dados (cin/cout)
│   └── CtrlApresentacaoPessoa.hpp / .cpp
│
├── Servico/                # [ENTREGA 5] Regras de negócio e armazenamento
│   ├── CtrlServicoPessoa.hpp / .cpp   # Implementa IServicoPessoa
│   └── ContainerPessoa.hpp / .cpp     # "Banco de dados" (std::list ou map)
│
├── Documentacao/           # [GERADO PELO DOXYGEN]
│   └── html/
│       └── index.html      # Site com toda a documentação do código
│
└── Entregaveis/            # Para envio do ZIP final
		└── Teste_Fumaca.mp4    # [ENTREGA 6]
```

---

> Gerado para auxiliar no planejamento do projeto TP1 de C++.
