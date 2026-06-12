# Nome do executável
TARGET = programa_final

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -g -I. -I./Apresentacao -I./Dominios -I./Entidades -I./Servico -I./Interfaces

# Encontra todos os arquivos .cpp em todas as subpastas
SRCS = $(shell find . -name "*.cpp")

# Converte nomes de arquivos para .o
OBJS = $(SRCS:.cpp=.o)

# Regra principal
all: $(TARGET)

# Linkagem final
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Regra de compilação
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza profunda
clean:
	find . -name "*.o" -type f -delete
	rm -f $(TARGET)

.PHONY: all clean