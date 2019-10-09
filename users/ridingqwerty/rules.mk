SRC += ridingqwerty.c \
       process_records.c

CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
UNICODE_ENABLE = no # "yes" in default keymap, blocking UNICODEMAP_ENABLE
UNICODEMAP_ENABLE = yes
MOUSEKEY_ENABLE = no
TAP_DANCE_ENABLE = no
AUTO_SHIFT_ENABLE = no

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += secrets.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tapdances.c
endif

ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
  SRC += unicode.c
endif

