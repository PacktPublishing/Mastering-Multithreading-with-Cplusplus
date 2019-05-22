type __atomic_load_n (type *ptr, int memorder)
void __atomic_load (type *ptr, type *ret, int memorder)
void __atomic_store_n (type *ptr, type val, int memorder)
void __atomic_store (type *ptr, type *val, int memorder)
type __atomic_exchange_n (type *ptr, type val, int memorder)
void __atomic_exchange (type *ptr, type *val, type *ret, int memorder)
bool __atomic_compare_exchange_n (type *ptr, type *expected, type desired,
bool weak, int success_memorder, int failure_memorder)
bool __atomic_compare_exchange (type *ptr, type *expected, type *desired,
bool weak, int success_memorder, int failure_memorder)

type __atomic_add_fetch (type *ptr, type val, int memorder)
type __atomic_sub_fetch (type *ptr, type val, int memorder)
type __atomic_and_fetch (type *ptr, type val, int memorder)
type __atomic_xor_fetch (type *ptr, type val, int memorder)
type __atomic_or_fetch (type *ptr, type val, int memorder)
type __atomic_nand_fetch (type *ptr, type val, int memorder)

type __atomic_fetch_add (type *ptr, type val, int memorder)
type __atomic_fetch_sub (type *ptr, type val, int memorder)
type __atomic_fetch_and (type *ptr, type val, int memorder)
type __atomic_fetch_xor (type *ptr, type val, int memorder)
type __atomic_fetch_or (type *ptr, type val, int memorder)
type __atomic_fetch_nand (type *ptr, type val, int memorder)

bool __atomic_test_and_set (void *ptr, int memorder)

void __atomic_clear (bool *ptr, int memorder)

void __atomic_thread_fence (int memorder)

void __atomic_signal_fence (int memorder)

bool __atomic_always_lock_free (size_t size, void *ptr)

bool __atomic_is_lock_free (size_t size, void *ptr)
