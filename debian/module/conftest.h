/* synchronized with conftest.sh from 346.47, 343.36, 340.76, 304.125, 173.14.39, 96.43.23, 71.86.15 */

#ifndef LINUX_VERSION_CODE
#include <linux/version.h>
#endif

#if !defined(IS_ENABLED) && LINUX_VERSION_CODE < KERNEL_VERSION(3,1,0)
#define __ARG_PLACEHOLDER_1 0,
#define config_enabled(cfg) _config_enabled(cfg)
#define _config_enabled(value) __config_enabled(__ARG_PLACEHOLDER_##value)
#define __config_enabled(arg1_or_junk) ___config_enabled(arg1_or_junk 1, 0)
#define ___config_enabled(__ignored, val, ...) val
#define IS_ENABLED(option) (config_enabled(option) || config_enabled(option##_MODULE))
#endif

/* Implement conftest.sh function nvidiafb_sanity_check */
#if IS_ENABLED(CONFIG_FB_NVIDIA)
#warning "The nvidia module is incompatible with nvidiafb!"
#endif

/* Implement conftest.sh function xen_sanity_check */
#if IS_ENABLED(CONFIG_XEN) && ! IS_ENABLED(CONFIG_PARAVIRT)
#warning "Xen kernels are not supported!"
#endif

/* Implement conftest.sh function preempt_rt_sanity_check */
#if IS_ENABLED(CONFIG_PREEMPT_RT) || IS_ENABLED(CONFIG_PREEMPT_RT_FULL)
#warning "PREEMPT_RT kernels are not supported!"
#endif

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

/* Implement conftest.sh function set_memory_uc */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25) && IS_ENABLED(CONFIG_X86)
 #define NV_SET_MEMORY_UC_PRESENT
#else
 #undef NV_SET_MEMORY_UC_PRESENT
#endif

/* Implement conftest.sh function set_memory_array_uc */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,28) && IS_ENABLED(CONFIG_X86)
 #define NV_SET_MEMORY_ARRAY_UC_PRESENT
#else
 #undef NV_SET_MEMORY_ARRAY_UC_PRESENT
#endif

/* Implement conftest.sh function set_pages_uc */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25) && IS_ENABLED(CONFIG_X86)
 #define NV_SET_PAGES_UC_PRESENT
#else
 #undef NV_SET_PAGES_UC_PRESENT
#endif

/* Implement conftest.sh function outer_flush_all */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,34) && IS_ENABLED(CONFIG_ARM)
 #define NV_OUTER_FLUSH_ALL_PRESENT
#else
 #undef NV_OUTER_FLUSH_ALL_PRESENT
#endif

/* Implement conftest.sh function change_page_attr */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,4,20) && \
               LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,25)
 #define NV_CHANGE_PAGE_ATTR_PRESENT
#else
 #undef NV_CHANGE_PAGE_ATTR_PRESENT
#endif

/* Implement conftest.sh function pci_get_class */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,10)
 #define NV_PCI_GET_CLASS_PRESENT
#else
 #undef NV_PCI_GET_CLASS_PRESENT
#endif

/* Implement conftest.sh function pci_get_domain_bus_and_slot */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
 #define NV_PCI_GET_DOMAIN_BUS_AND_SLOT_PRESENT
#else
 #undef NV_PCI_GET_DOMAIN_BUS_AND_SLOT_PRESENT
#endif

/* Implement conftest.sh function pci_save_state */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,10)
 #define NV_PCI_SAVE_STATE_ARGUMENT_COUNT 1
#else
 #define NV_PCI_SAVE_STATE_ARGUMENT_COUNT 2
#endif

/* Implement conftest.sh function remap_pfn_range */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,10)
 #define NV_REMAP_PFN_RANGE_PRESENT
#else
 #undef NV_REMAP_PFN_RANGE_PRESENT
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

/* Implement conftest.sh function follow_pfn */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,31)
 #define NV_FOLLOW_PFN_PRESENT
#else
 #undef NV_FOLLOW_PFN_PRESENT
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
 #undef NV_PM_MESSAGE_T_HAS_EVENT
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

/* Implement conftest.sh function acpi_op_remove */
/* All versions since 2.6.0 have this, didn't check earlier kernels */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,9,0)
 #define NV_ACPI_DEVICE_OPS_REMOVE_ARGUMENT_COUNT 1
#else
 #define NV_ACPI_DEVICE_OPS_REMOVE_ARGUMENT_COUNT 2
#endif

/* Implement conftest.sh function acpi_device_id */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,23)
 #define NV_ACPI_DEVICE_ID_HAS_DRIVER_DATA
#else
 #undef NV_ACPI_DEVICE_ID_HAS_DRIVER_DATA
#endif

/* Implement conftest.sh function acquire_console_sem */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,4,10) && \
    LINUX_VERSION_CODE < KERNEL_VERSION(2,6,38)
 #define NV_ACQUIRE_CONSOLE_SEM_PRESENT
#else
 #undef NV_ACQUIRE_CONSOLE_SEM_PRESENT
#endif

/* Implement conftest.sh function console_lock */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38)
 #define NV_CONSOLE_LOCK_PRESENT
#else
 #undef NV_CONSOLE_LOCK_PRESENT
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

/* Implement conftest.sh function vmm_support */
/* nv-xen.h does not exist */
#undef HAVE_NV_XEN

/* Implement conftest.sh function nvmap_support */
/* nv-android.h does not exist */
#undef HAVE_NV_ANDROID

/* Implement conftest.sh function acpi_evaluate_integer */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,4,19)
 #define NV_ACPI_EVALUATE_INTEGER_PRESENT
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,28)
  typedef unsigned long long nv_acpi_integer_t;
 #else
  typedef unsigned long nv_acpi_integer_t;
 #endif
#else
 #undef NV_ACPI_EVALUATE_INTEGER_PRESENT
 typedef unsigned long nv_acpi_integer_t;
#endif

/* Implement conftest.sh function acpi_walk_namespace */
/* Only kernels sometime before 2.4.0 don't have this function, and who */
/* cares anymore */
#define NV_ACPI_WALK_NAMESPACE_PRESENT
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
 #define NV_ACPI_WALK_NAMESPACE_ARGUMENT_COUNT 7
#else
 #define NV_ACPI_WALK_NAMESPACE_ARGUMENT_COUNT 6
#endif

/* Implement conftest.sh function acpi_os_wait_events_complete */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,7)
 #define NV_ACPI_OS_WAIT_EVENTS_COMPLETE_PRESENT
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(3,6,0)
  #define NV_ACPI_OS_WAIT_EVENTS_COMPLETE_ARGUMENT_COUNT 0
 #else
  #define NV_ACPI_OS_WAIT_EVENTS_COMPLETE_ARGUMENT_COUNT 1
 #endif
#else
 #undef NV_ACPI_OS_WAIT_EVENTS_COMPLETE_PRESENT
#endif

/* Implement conftest.sh function ioremap_cache */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25) && IS_ENABLED(CONFIG_X86)
 #define NV_IOREMAP_CACHE_PRESENT
#else
 #undef NV_IOREMAP_CACHE_PRESENT
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

/* Implement conftest.sh function INIT_WORK */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,5,41)
 #define NV_INIT_WORK_PRESENT
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,20)
  #define NV_INIT_WORK_ARGUMENT_COUNT 2
 #else
  #define NV_INIT_WORK_ARGUMENT_COUNT 3
 #endif
#else
 #undef NV_INIT_WORK_PRESENT
#endif

/* Implement conftest.sh function pci_dma_mapping_error */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,5)
 #define NV_PCI_DMA_MAPPING_ERROR_PRESENT
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
  #define NV_PCI_DMA_MAPPING_ERROR_ARGUMENT_COUNT 2
 #else
  #define NV_PCI_DMA_MAPPING_ERROR_ARGUMENT_COUNT 1
 #endif
#else
 #undef NV_PCI_DMA_MAPPING_ERROR_PRESENT
#endif

/* Implement conftest.sh function agp_memory */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,31)
 #define NV_AGP_MEMORY_HAS_PAGES
#else
 #undef NV_AGP_MEMORY_HAS_PAGES
#endif

/* Implement conftest.sh function scatterlist */
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,24)
 #define NV_SCATTERLIST_HAS_PAGE
#else
 #undef NV_SCATTERLIST_HAS_PAGE
#endif

/* Implement conftest.sh function pci_domain_nr */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,5,71)
 #define NV_PCI_DOMAIN_NR_PRESENT
#else
 #undef NV_PCI_DOMAIN_NR_PRESENT
#endif

/* Implement conftest.sh function file_operations */
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,36)
 #define NV_FILE_OPERATIONS_HAS_IOCTL
#else
 #undef NV_FILE_OPERATIONS_HAS_IOCTL
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,11)
 #define NV_FILE_OPERATIONS_HAS_UNLOCKED_IOCTL
 #define NV_FILE_OPERATIONS_HAS_COMPAT_IOCTL
#else
 #undef NV_FILE_OPERATIONS_HAS_UNLOCKED_IOCTL
 #undef NV_FILE_OPERATIONS_HAS_COMPAT_IOCTL
#endif

/* Implement conftest.sh function efi_enabled */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,1)
 #define NV_EFI_ENABLED_PRESENT
#else
 #undef NV_EFI_ENABLED_PRESENT
#endif

/* Implement conftest.sh function dom0_kernel_present */
#if 0
 #define NV_DOM0_KERNEL_PRESENT
#else
 #undef NV_DOM0_KERNEL_PRESENT
#endif

/* Implement conftest.sh function drm_available */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,9,0) && IS_ENABLED(CONFIG_DRM)
 #define NV_DRM_AVAILABLE
#else
 #undef NV_DRM_AVAILABLE
#endif

/* Implement conftest.sh function proc_create_data */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,26)
 #define NV_PROC_CREATE_DATA_PRESENT
#else
 #undef NV_PROC_CREATE_DATA_PRESENT
#endif

/* Implement conftest.sh function pde_data */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0)
 #define NV_PDE_DATA_PRESENT
#else
 #undef NV_PDE_DATA_PRESENT
#endif

/* Implement conftest.sh function get_num_physpages */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,11,0)
 #define NV_GET_NUM_PHYSPAGES_PRESENT
#else
 #undef NV_GET_NUM_PHYSPAGES_PRESENT
#endif

/* Implement conftest.sh function proc_remove */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0)
 #define NV_PROC_REMOVE_PRESENT
#else
 #undef NV_PROC_REMOVE_PRESENT
#endif

/* Implement conftest.sh function vm_operations_struct */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,23)
 #define NV_VM_OPERATIONS_STRUCT_HAS_FAULT
#else
 #undef NV_VM_OPERATIONS_STRUCT_HAS_FAULT
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
 #define NV_VM_OPERATIONS_STRUCT_HAS_ACCESS
#else
 #undef NV_VM_OPERATIONS_STRUCT_HAS_ACCESS
#endif

/* Implement conftest.sh function fault_flags */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,23)
 #define NV_FAULT_FLAG_PRESENT
#else
 #undef NV_FAULT_FLAG_PRESENT
#endif

/* Implement conftest.sh function atomic64_type */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,31)
 #define NV_ATOMIC64_PRESENT
#else
 #undef NV_ATOMIC64_PRESENT
#endif

/* Implement conftest.sh function task_struct */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,29)
 #define NV_TASK_STRUCT_HAS_CRED
#else
 #undef NV_TASK_STRUCT_HAS_CRED
#endif

/* Implement conftest.sh function address_space */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,12) && \
                LINUX_VERSION_CODE < KERNEL_VERSION(2,6,27)
 #define NV_ADDRESS_SPACE_HAS_RWLOCK_TREE_LOCK
#else
 #undef NV_ADDRESS_SPACE_HAS_RWLOCK_TREE_LOCK
#endif

/* Implement conftest.sh function address_space_init_once */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38)  /* 2.6.37.3 */
 #define NV_ADDRESS_SPACE_INIT_ONCE_PRESENT
#else
 #undef NV_ADDRESS_SPACE_INIT_ONCE_PRESENT
#endif

/* Implement conftest.sh function kbasename */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,8,0)
 #define NV_KBASENAME_PRESENT
#else
 #undef NV_KBASENAME_PRESENT
#endif

/* Implement conftest.sh function fatal_signal_pending */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)
 #define NV_FATAL_SIGNAL_PENDING_PRESENT
#else
 #undef NV_FATAL_SIGNAL_PENDING_PRESENT
#endif

/* Implement conftest.sh function kuid_t */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,5,0)
 #define NV_KUID_T_PRESENT
#else
 #undef NV_KUID_T_PRESENT
#endif

/* Implement conftest.sh function pm_vt_switch_required */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0)
 #define NV_PM_VT_SWITCH_REQUIRED_PRESENT
#else
 #undef NV_PM_VT_SWITCH_REQUIRED_PRESENT
#endif

/* Implement conftest.sh function sg_table */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)
 #define NV_SG_TABLE_PRESENT
#else
 #undef NV_SG_TABLE_PRESENT
#endif

/* Implement conftest.sh function sg_alloc_table */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)
 #define NV_SG_ALLOC_TABLE_PRESENT
#else
 #undef NV_SG_ALLOC_TABLE_PRESENT
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,6,0)
 #define NV_SG_ALLOC_TABLE_FROM_PAGES_PRESENT
#else
 #undef NV_SG_ALLOC_TABLE_FROM_PAGES_PRESENT
#endif

/* Implement conftest.sh function sg_init_table */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)
 #define NV_SG_INIT_TABLE_PRESENT
#else
 #undef NV_SG_INIT_TABLE_PRESENT
#endif

/* Implement conftest.sh function file_inode */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,9,0)
 #define NV_FILE_HAS_INODE
#else
 #undef NV_FILE_HAS_INODE
#endif

/* Implement conftest.sh function drm_pci_set_busid */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,18,0)
 #define NV_DRM_PCI_SET_BUSID_PRESENT
#else
 #undef NV_DRM_PCI_SET_BUSID_PRESENT
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

/* Check for drm/drmP.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
 #define NV_DRM_DRMP_H_PRESENT
#else
 #undef NV_DRM_DRMP_H_PRESENT
#endif

/* Check for drm/drm_gem.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,18,0)
 #define NV_DRM_DRM_GEM_H_PRESENT
#else
 #undef NV_DRM_DRM_GEM_H_PRESENT
#endif

/* Check for generated/autoconf.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
 #define NV_GENERATED_AUTOCONF_H_PRESENT
#else
 #undef NV_GENERATED_AUTOCONF_H_PRESENT
#endif

/* Check for generated/compile.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
 #define NV_GENERATED_COMPILE_H_PRESENT
#else
 #undef NV_GENERATED_COMPILE_H_PRESENT
#endif

/* Check for generated/utsrelease.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
 #define NV_GENERATED_UTSRELEASE_H_PRESENT
#else
 #undef NV_GENERATED_UTSRELEASE_H_PRESENT
#endif

/* Check for asm/system.h */
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0)
 #define NV_ASM_SYSTEM_H_PRESENT
#else
 #undef NV_ASM_SYSTEM_H_PRESENT
#endif

/* Check for linux/efi.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,5,33)
 #define NV_LINUX_EFI_H_PRESENT
#else
 #undef NV_LINUX_EFI_H_PRESENT
#endif

/* Check for linux/kconfig.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,1,0)
 #define NV_LINUX_KCONFIG_H_PRESENT
#else
 #undef NV_LINUX_KCONFIG_H_PRESENT
#endif

/* Check for linux/screen_info.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,16)
 #define NV_LINUX_SCREEN_INFO_H_PRESENT
#else
 #undef NV_LINUX_SCREEN_INFO_H_PRESENT
#endif

/* Check for linux/nvmap.h */
// does not (yet) exist in kernel source
 #undef NV_LINUX_NVMAP_H_PRESENT

/* Check for linux/printk.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,37)
 #define NV_LINUX_PRINTK_H_PRESENT
#else
 #undef NV_LINUX_PRINTK_H_PRESENT
#endif

/* Check for linux/ratelimit.h */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
 #define NV_LINUX_RATELIMIT_H_PRESENT
#else
 #undef NV_LINUX_RATELIMIT_H_PRESENT
#endif

/* Check for linux/prio_tree.h */
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,7,0)
 #define NV_LINUX_PRIO_TREE_H_PRESENT
#else
 #undef NV_LINUX_PRIO_TREE_H_PRESENT
#endif
