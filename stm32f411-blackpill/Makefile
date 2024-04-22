# Nome do programa executável
PROG = blinky

# Compilador
CC = arm-none-eabi-gcc

# Flags de compilação
CFLAGS = -c -mcpu=cortex-m4 -mthumb -Wall -O0 -MMD -MP

# Linker e opções de link
LD = arm-none-eabi-gcc
LDFLAGS = -nostdlib -T stm32f411-rom.ld

# Conversor para binário
CP = arm-none-eabi-objcopy
CPFLAGS = -O binary

# Arquivos objeto
OBJS = startup.o main.o

# Regra padrão
all: $(PROG).elf $(PROG).bin

# Regra para gerar o arquivo ELF
$(PROG).elf: $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

# Regra para gerar o arquivo binário
$(PROG).bin: $(PROG).elf
	$(CP) $(CPFLAGS) $< $@

# Compilação dos arquivos fonte
%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Incluir automaticamente todas as dependências dos arquivos fonte
-include $(OBJS:.o=.d)

# Limpar arquivos gerados
clean:
	rm -f $(OBJS) $(PROG).elf $(PROG).bin $(OBJS:.o=.d)

