SRC += ridingqwerty.c \
       process_records.c

BOOTMAGIC_ENABLE  = lite
COMBO_ENABLE      = no    # combos suck
COMMAND_ENABLE    = no
CONSOLE_ENABLE    = no
UNICODE_ENABLE    = no    # "yes" in Atreus default keymap, blocking UNICODEMAP_ENABLE
UNICODEMAP_ENABLE = yes
MOUSEKEY_ENABLE   = no
TAP_DANCE_ENABLE  = yes
AUTO_SHIFT_ENABLE = no
LEADER_ENABLE     = yes

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += secrets.c
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
  SRC += combos.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tapdances.c
endif

ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
  SRC += unicode.c
endif

