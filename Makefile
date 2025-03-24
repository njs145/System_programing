# 아키텍쳐 정의
ARCH = armv7-a
MCPU = cortex-a8	

# 컴파일러 변수 추가.
CC = /usr/bin/aarch64-linux-gnu-gcc
AS = /usr/bin/aarch64-linux-gnu-as
LD = /usr/bin/aarch64-linux-gnu-gcc
OC = /usr/bin/aarch64-linux-gnu-objcopy
OD = /usr/bin/aarch64-linux-gnu-objdump

# 글로벌 define 선언
C_DEFINE = -D_GNU_SOURCE

# 출력 파일 이름 정의.
output = build
MAP_FILE = build/system_programing.map
ASM_FILE = build/system_programing.asm
system_programing = build/system_programing

# 컴파일 옵션 정의.
CFLAGS = -fdiagnostics-color=always -c -g -O0 -std=c11 -Werror

# 링커 옵션 선언.
LDFLAGS = -static -lgcc

# 컴파일 목록들 정의.
C_SRCS = $(wildcard *.c)
C_SRCS += $(notdir $(wildcard file_basic/*.c))
C_OBJS = $(patsubst %.c, build/%.o, $(C_SRCS))

# 컴파일 경로 정의
INC_DIRS = -I file_basic							\

# Makefile의 검색 경로 설정
VPATH = file_basic 							\


# Makefile 타겟 정의
.PHONY: all clean

# build
all: $(system_programing)

# build 폴더 삭제
clean:
	@rm -fr build

# object파일 링크
$(system_programing): $(C_OBJS)
	$(LD) -o $(system_programing) $(C_OBJS) -Wl,-Map=$(MAP_FILE) $(LDFLAGS)
	$(OD) -d $(system_programing) >> $(ASM_FILE)
	rm $(output)/*.o

# c파일 컴파일
$(output)/%.o: %.c
	mkdir -p $(shell dirname $@)
	@echo $(CC) $(INC_DIRS) $(CFLAGS) -o $@ $<
	$(CC) $(C_DEFINE) $(INC_DIRS) $(CFLAGS) -o $@ $<