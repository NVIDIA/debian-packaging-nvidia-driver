/* Implement conftest.sh function remap_page_range */
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,11)
 #if LINUX_VERSION_CODE < KERNEL_VERSION(2,5,0)
  #define NV_REMAP_PAGE_RANGE_PRESENT
  #define NV_REMAP_PAGE_RANGE_ARGUMENT_COUNT 4
 #else
  #define NV_REMAP_PAGE_RANGE_PRESENT
  #define NV_REMAP_PAGE_RANGE_ARGUMENT_COUNT 5
 #endif
#else
 #undef NV_REMAP_PAGE_RANGE_PRESENT
#endif

/* Implement conftest.sh function set_pages_uc */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)
 #ifdef NV_CHANGE_PAGE_ATTR_PRESENT
  #undef NV_CHANGE_PAGE_ATTR_PRESENT
 #endif
 #define NV_SET_PAGES_UC_PRESENT
#else
 #undef NV_SET_PAGES_UC_PRESENT
#endif

/* Implement conftest.sh function change_page_attr */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,4,20) && \
               LINUX_VERSION_CODE < KERNEL_VERSION(2,6,25)
 #ifndef NV_SET_PAGES_UC_PRESENT
  #define NV_CHANGE_PAGE_ATTR_PRESENT
 #endif
#else
 #undef NV_CHANGE_PAGE_ATTR_PRESENT
#endif

/* Implement conftest.sh function pci_get_class */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,10)
 #define NV_PCI_GET_CLASS_PRESENT
#else
 #undef NV_PCI_GET_CLASS_PRESENT
#endif

/* Implement conftest.sh function remap_pfn_range */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,10)
 #define NV_REMAP_PFN_RANGE_PRESENT
#else
 #undef NV_REMAP_PFN_RANGE_PRESENT
#endif

/* Implement conftest.sh function signal_struct */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,10)
 #define NV_SIGNAL_STRUCT_HAS_RLIM
#else
 #undef NV_SIGNAL_STRUCT_HAS_RLIM
#endif

/* Implement conftest.sh function agp_backend_acquire */
/* Only kernels sometime before 2.4.0 don't have this function, and who */
/* cares anymore */
#define NV_AGP_BACKEND_ACQUIRE_PRESENT
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,12)
 #define NV_AGP_BACKEND_ACQUIRE_ARGUMENT_COUNT 1
#else
 #define NV_AGP_BACKEND_ACQUIRE_ARGUMENT_COUNT 0
#endif

/* Implement conftest.sh function vmap */
/* I can not find any released kernel that uses the 2 argument variant */
/* of vmap */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,4,22)
 #define NV_VMAP_PRESENT
 #define NV_VMAP_ARGUMENT_COUNT 4
#else
 #undef NV_VMAP_PRESENT
#endif

/* Implement conftest.sh function i2c_adapter */
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,5,0)
 #define NV_I2C_ADAPTER_HAS_INC_USE
 #define NV_I2C_ADAPTER_HAS_DEC_USE
 #define NV_I2C_ADAPTER_HAS_CLIENT_REGISTER
#else
 #undef NV_I2C_ADAPTER_HAS_INC_USE
 #undef NV_I2C_ADAPTER_HAS_DEC_USE
 #undef NV_I2C_ADAPTER_HAS_CLIENT_REGISTER
#endif

/* Implement conftest.sh function sysctl_max_map_count */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,5)
 #define NV_SYSCTL_MAX_MAP_COUNT_PRESENT
#else
 #undef NV_SYSCTL_MAX_MAP_COUNT_PRESENT
#endif

/* Implement conftest.sh function pm_message_t */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,11)
 #define NV_PM_MESSAGE_T_PRESENT
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,14)
  #define NV_PM_MESSAGE_T_HAS_EVENT
 #else
  #undef NV_PM_MESSAGE_T_HAS_EVENT
 #endif
#else
 #undef NV_PM_MESSAGE_T_PRESENT
#endif

/* Implement conftest.sh function pci_choose_state */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,11)
 #define NV_PCI_CHOOSE_STATE_PRESENT
#else
 #undef NV_PCI_CHOOSE_STATE_PRESENT
#endif

/* Implement conftest.sh function vm_insert_page */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,15)
 #define NV_VM_INSERT_PAGE_PRESENT
#else
 #undef NV_VM_INSERT_PAGE_PRESENT
#endif

/* Implement conftest.sh function irq_handler_t */
/* I can not find any released kernel that uses the 3 argument variant */
/* of irq_handler_t */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,19)
 #define NV_IRQ_HANDLER_T_PRESENT
 #define NV_IRQ_HANDLER_T_ARGUMENT_COUNT 2
#else
 #undef NV_IRQ_HANDLER_T_PRESENT
#endif

/* Implement conftest.sh function acpi_device_ops */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,10) && \
               LINUX_VERSION_CODE < KERNEL_VERSION(2,6,21)
 #define NV_ACPI_DEVICE_OPS_HAS_MATCH
#else
 #undef NV_ACPI_DEVICE_OPS_HAS_MATCH
#endif

/* Implement conftest.sh function acpi_device_id */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,23)
 #define NV_ACPI_DEVICE_ID_HAS_DRIVER_DATA
#else
 #undef NV_ACPI_DEVICE_ID_HAS_DRIVER_DATA
#endif

/* Implement conftest.sh function acquire_console_sem */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,4,10)
 #define NV_ACQUIRE_CONSOLE_SEM_PRESENT
#else
 #undef NV_ACQUIRE_CONSOLE_SEM_PRESENT
#endif

/* Implement conftest.sh function kmem_cache_create */
/* Only kernels sometime before 2.4.0 don't have this function, and who */
/* cares anymore */
#define NV_KMEM_CACHE_CREATE_PRESENT
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,23)
 #define NV_KMEM_CACHE_CREATE_ARGUMENT_COUNT 5
#else
 #define NV_KMEM_CACHE_CREATE_ARGUMENT_COUNT 6
#endif

/* Implement conftest.sh function smp_call_function */
/* Only kernels sometime before 2.4.0 don't have this function, and who */
/* cares anymore */
#define NV_SMP_CALL_FUNCTION_PRESENT
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
 #define NV_SMP_CALL_FUNCTION_ARGUMENT_COUNT 3
#else
 #define NV_SMP_CALL_FUNCTION_ARGUMENT_COUNT 4
#endif

/* Implement conftest.sh function on_each_cpu */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,5,0)
 #define NV_ON_EACH_CPU_PRESENT
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
  #define NV_ON_EACH_CPU_ARGUMENT_COUNT 3
 #else
  #define NV_ON_EACH_CPU_ARGUMENT_COUNT 4
 #endif
#else
 #undef NV_ON_EACH_CPU_PRESENT
#endif

/* Implement conftest.sh function acpi_evaluate_interger */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,4,19)
 #define NV_ACPI_EVALUATE_INTEGER_PRESENT
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,28)
  typedef unsigned long long nv_acpi_integer_t;
 #else
  typedef unsigned long nv_acpi_integer_t;
 #endif
#else
 #undef NV_ON_EACH_CPU_PRESENT
 typedef unsigned long nv_acpi_integer_t;
#endif

/* Implement conftest.sh function ioremap_wc */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,26)
 #define NV_IOREMAP_WC_PRESENT
#else
 #undef NV_IOREMAP_WC_PRESENT
#endif

/* Implement conftest.sh function proc_dir_entry */
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,30)
 #define NV_PROC_DIR_ENTRY_HAS_OWNER
#else
 #undef NV_PROC_DIR_ENTRY_HAS_OWNER
#endif

/* Implement conftest.sh function agp_memory */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,31)
 #define NV_AGP_MEMORY_HAS_PAGES
#else
 #undef NV_AGP_MEMORY_HAS_PAGES
#endif

/* Check for linux/semaphore.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,26)
 #define NV_LINUX_SEMAPHORE_H_PRESENT
#else
 #undef NV_LINUX_SEMAPHORE_H_PRESENT
#endif

/* Check for linux/cred.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
 #define NV_LINUX_CRED_H_PRESENT
#else
 #undef NV_LINUX_CRED_H_PRESENT
#endif
