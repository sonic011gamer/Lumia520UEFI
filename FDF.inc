################################################################################
#
# Rules are use with the [FV] section's module INF type to define
# how an FFS file is created for a given INF file. The following Rule are the default
# rules for the different module type. User can add the customized rules to define the
# content of the FFS file.
#
################################################################################


############################################################################
# Example of a DXE_DRIVER FFS file with a Checksum encapsulation section   #
############################################################################
#
#[Rule.Common.DXE_DRIVER]
#  FILE DRIVER = $(NAMED_GUID) {
#    DXE_DEPEX    DXE_DEPEX Optional      |.depex
#    COMPRESS PI_STD {
#      GUIDED {
#        PE32     PE32                    |.efi
#        UI       STRING="$(MODULE_NAME)" Optional
#        VERSION  STRING="$(INF_VERSION)" Optional BUILD_NUM=$(BUILD_NUMBER)
#      }
#    }
#  }
#
############################################################################

[Rule.Common.SEC]
  FILE SEC = $(NAMED_GUID) RELOCS_STRIPPED {
    TE  TE    Align = 8      |.efi
  }

[Rule.Common.PEI_CORE]
  FILE PEI_CORE = $(NAMED_GUID) {
    TE     TE           |.efi
    UI     STRING ="$(MODULE_NAME)" Optional
  }

[Rule.Common.PEIM]
  FILE PEIM = $(NAMED_GUID) {
     PEI_DEPEX PEI_DEPEX Optional        |.depex
     PE32      PE32                      |.efi
     UI       STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.PEIM.TIANOCOMPRESSED]
  FILE PEIM = $(NAMED_GUID) DEBUG_MYTOOLS_IA32 {
    PEI_DEPEX PEI_DEPEX Optional         |.depex
    GUIDED A31280AD-481E-41B6-95E8-127F4C984779 PROCESSING_REQUIRED = TRUE {
      PE32      PE32                     |.efi
      UI        STRING="$(MODULE_NAME)" Optional
    }
  }

[Rule.Common.DXE_CORE]
  FILE DXE_CORE = $(NAMED_GUID) {
    PE32     PE32           |.efi
    UI       STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.UEFI_DRIVER]
  FILE DRIVER = $(NAMED_GUID) {
    DXE_DEPEX    DXE_DEPEX Optional      |.depex
    PE32         PE32                    |.efi
    UI           STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.DXE_DRIVER]
  FILE DRIVER = $(NAMED_GUID) {
    DXE_DEPEX    DXE_DEPEX Optional      |.depex
    PE32         PE32                    |.efi
    UI           STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.DXE_RUNTIME_DRIVER]
  FILE DRIVER = $(NAMED_GUID) {
    DXE_DEPEX    DXE_DEPEX Optional      |.depex
    PE32         PE32                    |.efi
    UI           STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.UEFI_APPLICATION]
  FILE APPLICATION = $(NAMED_GUID) {
    UI     STRING ="$(MODULE_NAME)" Optional
    PE32   PE32                    |.efi
  }
  
[Rule.Common.DXE_DRIVER.BINARY]
  FILE DRIVER = $(NAMED_GUID) {
    DXE_DEPEX    DXE_DEPEX Optional      |.depex
    PE32         PE32                    |.efi
    UI           STRING="$(MODULE_NAME)" Optional
  }

[Rule.Common.UEFI_APPLICATION.BINARY]
  FILE APPLICATION = $(NAMED_GUID) {
    DXE_DEPEX    DXE_DEPEX Optional      |.depex
    PE32         PE32                    |.efi
    UI           STRING="$(MODULE_NAME)" Optional
  }
