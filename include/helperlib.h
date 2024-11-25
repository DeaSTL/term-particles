#define NEW_HS(type,amount) (*#type)calloc(amount,sizeof(#type))

static unsigned int g_seed;

static inline void fast_srand(int seed) {
    g_seed = seed;
}

static inline int fast_rand(void) {
    g_seed = (214013*g_seed+2531011);
    return (g_seed>>16)&0x7FFF;
}
