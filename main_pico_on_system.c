#include "images_140X140.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// #define STB_IMAGE_IMPLEMENTATION
// #include <stdlib.h>
// #include <stdint.h>
// #include <stdio.h>
// #include "lodepng.h"

// #include <png.h>

// #include <stdlib.h>
// #include <math.h>

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <stdbool.h>

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <dirent.h>
// #include <sys/stat.h>

// #include <stdint.h>
// #include <stddef.h>

// #include <limits.h>



// #define MAX_REP_LEN 100

// double threshold = 4.5;

// // //////////////////////
// // #if __has_include(<malloc.h>)
// //   #include <malloc.h>
// // #endif
// // #if __has_include(<unistd.h>)
// //   #include <unistd.h>   // for sbrk(0) if provided by your C library
// // #endif

// // // Linker symbols provided by the Pico SDK linker scripts.
// // // Names are the same on RP2040 & RP2350 builds.
// // extern char __StackTop;      // initial stack pointer (top of stack region, higher address)
// // extern char __StackLimit;    // bottom of stack region (lower address)
// // extern char __bss_start__, __bss_end__;
// // extern char __data_start__, __data_end__;

// // // --- Segment sizes (link-time fixed parts) ---
// // static inline uint32_t data_size(void) {
// //     return (uint32_t)((uintptr_t)&__data_end__ - (uintptr_t)&__data_start__);
// // }
// // static inline uint32_t bss_size(void) {
// //     return (uint32_t)((uintptr_t)&__bss_end__ - (uintptr_t)&__bss_start__);
// // }

// // // --- Heap accounting ---
// // static inline uint32_t heap_total_region(void) {
// //     // Heap grows up from end of .bss toward __StackLimit
// //     return (uint32_t)((uintptr_t)&__StackLimit - (uintptr_t)&__bss_end__);
// // }

// // static inline uint32_t heap_used_runtime(void) {
// // #if defined(__GLIBC__) || defined(__NEWLIB__)
// //   #if __has_include(<malloc.h>)
// //     // mallinfo is common on embedded newlib; if mallinfo2 exists you can switch to it.
// //     struct mallinfo mi = mallinfo();
// //     return (uint32_t)mi.uordblks; // bytes currently allocated on the heap
// //   #else
// //     return 0u;
// //   #endif
// // #else
// //     return 0u;
// // #endif
// // }

// // // Current program break (end of heap) if sbrk available:
// // static inline uintptr_t heap_brk(void) {
// // #if __has_include(<unistd.h>)
// //     void *brk = sbrk(0);
// //     return (uintptr_t)brk;
// // #else
// //     // Fallback estimate: end of .bss + heap_used (works if allocator is linear)
// //     return (uintptr_t)&__bss_end__ + heap_used_runtime();
// // #endif
// // }

// // // --- Stack accounting ---
// // static inline uint32_t stack_capacity(void) {
// //     // Stack region is [__StackLimit, __StackTop], grows downward from __StackTop
// //     return (uint32_t)((uintptr_t)&__StackTop - (uintptr_t)&__StackLimit);
// // }

// // static inline uint32_t stack_used_now(void) {
// //     volatile char sp_probe;                 // lives on the current stack frame
// //     uintptr_t sp = (uintptr_t)&sp_probe;    // current stack pointer approx
// //     uintptr_t top = (uintptr_t)&__StackTop; // initial SP (top of stack)
// //     // Because stack grows down, bytes used = top - current_sp
// //     return (uint32_t)(top - sp);
// // }

// // // --- Convenience: free space between heap and current stack ---
// // static inline uint32_t free_between_heap_and_stack(void) {
// //     volatile char sp_probe;
// //     uintptr_t sp  = (uintptr_t)&sp_probe;
// //     uintptr_t brk = heap_brk();
// //     if (sp > brk) {
// //         return (uint32_t)(sp - brk);
// //     } else {
// //         // Heap/stack collision (or estimate failure)
// //         return 0u;
// //     }
// // }

// // void print_sram_usage(void) {
// //     uint32_t data   = data_size();
// //     uint32_t bss    = bss_size();
// //     uint32_t heap_u = heap_used_runtime();
// //     uint32_t heap_T = heap_total_region();
// //     uint32_t stk_u  = stack_used_now();
// //     uint32_t stk_T  = stack_capacity();
// //     uint32_t gap    = free_between_heap_and_stack();

// //     printf("SRAM usage breakdown (bytes):\n");
// //     printf("  .data:                 %u\n", data);
// //     printf("  .bss:                  %u\n", bss);
// //     printf("  Heap used:             %u\n", heap_u);
// //     printf("  Heap total region:     %u\n", heap_T);
// //     printf("  Stack used (current):  %u\n", stk_u);
// //     printf("  Stack capacity:        %u\n", stk_T);
// //     printf("  Free (heap<->stack):   %u\n", gap);

// //     // Optional: total 'currently used' estimate (excludes unused part of heap/stack regions)
// //     uint32_t est_used_now = data + bss + heap_u + stk_u;
// //     printf("  ----\n");
// //     printf("  Estimated used now:    %u\n", est_used_now);
// // }

// /////////////////////

// // #include <time.h>

// // #define DEBUG_UART uart0    // UART0 for printf debugging
// // #define SENSOR_UART uart1   // UART1 for fingerprint sensor

// // #define BAUD_RATE 115200    // Debug UART baud rate
// // #define SENSOR_BAUD 19200   // Fingerprint sensor baud rate
// // // max 200 fingerprints in R502

// // // UART0 (for printf)
// // #define UART0_TX_PIN 0
// // #define UART0_RX_PIN 1

// // // UART1 (for fingerprint sensor)
// // #define UART1_TX_PIN 4
// // #define UART1_RX_PIN 5

// // // #define FINGER_IRQ_PIN 6
// // // #define FINGER_EN_PIN 7

// // #define TRUE          1
// // #define FALSE         0

// // // Basic response message definition
// // #define ACK_SUCCESS            0x00
// // #define ACK_FAIL               0x01
// // #define ACK_FULL               0x04
// // #define ACK_NO_USER            0x05
// // #define ACK_TIMEOUT            0x08
// // #define ACK_GO_OUT             0x0F     // The center of the fingerprint is out of alignment with sensor

// // // User information definition
// // #define ACK_ALL_USER           0x00
// // #define ACK_GUEST_USER         0x01
// // #define ACK_NORMAL_USER        0x02
// // #define ACK_MASTER_USER        0x03

// // #define USER_MAX_CNT           1000        // Maximum fingerprint number

// // // Command definition
// // #define CMD_HEAD               0xF5
// // #define CMD_TAIL               0xF5
// // #define CMD_ADD_1              0x01
// // #define CMD_ADD_2              0x02
// // #define CMD_ADD_3              0x03
// // #define CMD_MATCH              0x0C
// // #define CMD_UPLOAD_EIGEN_VALUES 0x31
// // #define CMD_ACQUIRE_IMAGE_AND_UPLOAD 0x24
// // #define CMD_GET_EIGEN_VALUES_OF_FINGER 0x23
// // #define CMD_COMPARE_EIGEN_VALUES_OF_FINGER 0x44
// // #define CMD_COMPARE_EIGEN_VALUES_WITH_ALL_USERS 0x43
// // #define CMD_DEL                0x04
// // #define CMD_DEL_ALL            0x05
// // #define CMD_USER_CNT           0x09
// // #define CMD_COM_LEV            0x28
// // #define CMD_LP_MODE            0x2C
// // #define CMD_TIMEOUT            0x2E

// // #define CMD_FINGER_DETECTED    0x14

// // // uint8_t Finger_SleepFlag    = 0; 

// // uint8_t g_rx_buf [10000] = {0};

// // uint8_t fingerprint_eigen_database[193]={0};

// // #define RING_BUFFER_SIZE 20000

// // // === Ring Buffer ===
// // volatile uint8_t ring_buffer[RING_BUFFER_SIZE];
// // volatile size_t head = 0;
// // volatile size_t tail = 0;

// // void Auto_Verify_Finger()
// // {
// //     while(true)
// //     {
// //         /*
// //         By default, Finger_SleepFlag is 0, which means the module is awake.
// //         Using "CMD2", add multiple users first.
// //         Then, use "CMD5" to put the module into sleep mode.
// //         Then use Auto_Verify_Finger() to always check for fingerprint verification whenever user presses on top of sensor and now, all other CMDs except for "CMD6" won't work
// //         If you want to add a new user, use "CMD6" to wake up the module. Now, Auto_Verify_Finger() will not longer work. Add new user using "CMD2" and then put module to sleep using "CM5" and now forever-loop for Auto_Verify_Finger() is back.
// //         */
// //         if(Finger_SleepFlag==1)
// //         {
// //             if (gpio_get(FINGER_WAKE_PIN))
// //             {
// //                 sleep_ms(10); 
// //                 if(gpio_get(FINGER_WAKE_PIN))           // Finger is indeed pressed for verification?
// //                 {
// //                     gpio_put(FINGER_RST_PIN, 1);        // Temporary work will happen
// //                     sleep_ms(250);
// //                     printf("Waiting Finger......Please try to place the center of the fingerprint flat to sensor !\n");
// //                     uint8_t r=VerifyUser();
// //                     if(r==ACK_SUCCESS)
// //                     {
// //                         printf("Matching successful.\n");
// //                     }
// //                     else if(r==ACK_NO_USER)
// //                     {
// //                         printf("No matching fingerprint found.\n");
// //                     }
// //                     else if(r==ACK_TIMEOUT)
// //                     {
// //                         printf("Timeout occurred while matching fingerprint.\n");
// //                     }
// //                     else if(r==ACK_GO_OUT)
// //                     {
// //                         printf("Fingerprint is out of alignment with sensor.\n");
// //                     }

// //                     gpio_put(FINGER_RST_PIN, 0);

// //                 }
// //             }
// //         }

// //         sleep_ms(200);
// //     }
// // }

// // int main() {
// //     // // stdio_init_all();
// //     // setup_uart0();  // Initialize UART0 for debugging
// //     // printf("UART0 is done!\n");
// //     // setup_uart1();  // Initialize UART1 for fingerprint sensor
// //     // // // init_gpio();
// //     // // printf("UART1 is done!\n");

// //     // while(SetCompareLevel(5) != 5)
// //     // {
// //     //     printf("Set compare level failed, retrying...\n");
// //     //     sleep_ms(1000);
// //     // }

// //     // // // multicore_launch_core1(Auto_Verify_Finger);  // Start the auto verification thread



// //     // while(true)
// //     // {
// //     //     uart_puts(DEBUG_UART,"Commands:\n");
// //     //     uart_puts(DEBUG_UART,"1: Query the number of existing fingerprints\n");
// //     //     uart_puts(DEBUG_UART,"2: Register fingerprint\n");
// //     //     uart_puts(DEBUG_UART,"3: Fingerprint matching\n");
// //     //     uart_puts(DEBUG_UART,"4: Clear all fingerprints\n");
// //     //     uart_puts(DEBUG_UART,"5: Get image for current finger\n");
// //     //     uart_puts(DEBUG_UART,"6: Exit\n");

// //     //     char input[100];
// //     //     int i = 0;
// //     //     while (i < 99) {
// //     //         char c = uart_getc(DEBUG_UART);
// //     //         uart_putc(DEBUG_UART, c);        // Echo back to terminal
// //     //         if (c == '\r' || c == '\n') break;  // Stop on Enter key
// //     //         input[i++] = c;
// //     //     }
// //     //     input[i] = '\0';

// //     //     Analysis_PC_Command(input);
// //     // }

// //     // return 0;
// // }

// ///////////////////////////////////////////////////////////////


// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// // #define STB_IMAGE_IMPLEMENTATION
// // #include "stb_image.h"
// // #include <stdlib.h>
// #include <stdint.h>
// // #include <stdio.h>

// // #include <png.h>

// // #include <stdlib.h>
// // #include <math.h>

// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <math.h>
// #include <stdbool.h>

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// // #include <dirent.h>
// // #include <sys/stat.h>

// // #include <stdint.h>
// #include <stddef.h>

// #include <limits.h>

// #define MASK_VOTE_RADIUS 7
// #define MASK_VOTE_MAJORITY 0.51
// #define MASK_VOTE_BORDER_DISTANCE 4
// #define CLIPPED_CONTRAST 0.08
// #define MIN_ABSOLUTE_CONTRAST  17 / 255.0
// #define MASK_VOTE_RADIUS 7
// #define MASK_VOTE_MAJORITY 0.51
// #define MASK_VOTE_BORDER_DISTANCE 4
// #define RELATIVE_CONTRAST_SAMPLE 168568
// #define RELATIVE_CONTRAST_PERCENTILE 0.49
// #define MIN_RELATIVE_CONTRAST 0.34

// #define BLOCK_ERRORS_VOTE_RADIUS 1
// #define BLOCK_ERRORS_VOTE_MAJORITY 0.7
// #define BLOCK_ERRORS_VOTE_BORDER_DISTANCE 4
// #define MASK_VOTE_RADIUS 7
// #define MASK_VOTE_MAJORITY  0.51
// #define MASK_VOTE_BORDER_DISTANCE 4

// #define MAX_EQUALIZATION_SCALING  3.99
// #define MIN_EQUALIZATION_SCALING  0.25

// #define ORIENTATION_SPLIT 50
// #define ORIENTATIONS_CHECKED 20
// #define MIN_ORIENTATION_RADIUS 2
// #define MAX_ORIENTATION_RADIUS 6
// #define ORIENTATION_SMOOTHING_RADIUS 1

// #define PARALLEL_SMOOTHING_RESOLUTION  32
// #define PARALLEL_SMOOTHING_RADIUS  7
// #define PARALLEL_SMOOTHING_STEP  1.59
// #define ORTHOGONAL_SMOOTHING_RESOLUTION  11
// #define ORTHOGONAL_SMOOTHING_RADIUS  4
// #define ORTHOGONAL_SMOOTHING_STEP 1.11

// #define M_PI 3.141592653589793
// #define PI2 2*M_PI
// #define INV_PI2 1.0/(PI2)// 1 / M_PI
// #define HALF_PI 0.5*M_PI

// #define INNER_MASK_BORDER_DISTANCE  14

// #define BINARIZED_VOTE_RADIUS 2
// #define BINARIZED_VOTE_MAJORITY 0.61
// #define BINARIZED_VOTE_BORDER_DISTANCE 17

// #define THINNING_ITERATIONS  26

// #define MAX_PORE_ARM 41

// #define TOLERATED_GAP_OVERLAP 2
// #define GAP_ANGLE_OFFSET 22
// #define MAX_RUPTURE_SIZE 5
// #define MAX_GAP_SIZE 20
// #define MAX_GAP_ANGLE (M_PI / 4.0)  // 45 degrees in radians
// #define TOLERATED_GAP_OVERLAP 2
// #define SHORTEST_JOINED_ENDING 7
// #define MIN_TAIL_LENGTH 21
// #define MIN_FRAGMENT_LENGTH 22

// #define RIDGE_DIRECTION_SKIP 1
// #define RIDGE_DIRECTION_SAMPLE 21

// #define MASK_DISPLACEMENT 10.06

// #define MINUTIA_CLOUD_RADIUS 20
// #define MAX_CLOUD_SIZE  4

// #define MAX_MINUTIAE 100

// #define SORT_BY_NEIGHBOR  5

// #define POLAR_CACHE_BITS 8
// #define POLAR_CACHE_RADIUS (1 << POLAR_CACHE_BITS)
// #define POLAR_CACHE_SIZE (POLAR_CACHE_RADIUS * POLAR_CACHE_RADIUS)

// #define EDGE_TABLE_NEIGHBORS 9

// #define MIN_ROOT_EDGE_LENGTH 58

// #define MAX_ROOT_EDGE_LOOKUPS 1633

// // // // #define printf(...)   

// typedef struct { int width, height; uint32_t* argb; } ArgbImage;

// // sRGB encoding: linear [0..1] -> sRGB [0..1]
// static inline uint8_t linear_to_srgb_u8(float L) {
//     if (L <= 0.0031308f) L = 12.92f * L;
//     else                 L = 1.055f * powf(L, 1.0f/2.4f) - 0.055f;
//     int out = (int)lroundf(fmaxf(0.f, fminf(1.f, L)) * 255.f);
//     return (uint8_t)out;
// }

// static void free_argb(ArgbImage* img) {
//     if (!img) return;
//     // free(img->argb);
//     img->argb = NULL;
//     img->width = img->height = 0;
// }

// // static void inspect_png_chunks(const unsigned char* png, size_t len) {
// //     LodePNGState st; lodepng_state_init(&st);
// //     unsigned w=0,h=0;
// //     unsigned err = lodepng_inspect(&w,&h,&st,png,len);
// //     // if (err) {
// //     //     printf("inspect error=%u\n", err);
// //     // } else {
// //     //     printf("PNG %ux%u  sRGB=%u  gAMA_defined=%u  iCCP=%u\n",
// //     //            w,h, st.info_png.srgb_defined, st.info_png.gama_defined
// //     //           , st.info_png.iccp_defined);
// //     // }
// //     lodepng_state_cleanup(&st);
// // }
// // // Decode and try to match Java ImageIO getRGB() on grayscale PNGs with no profile
// // static int decode_png_file_to_argb32_javaish(const char* path, ArgbImage* out) {
// //     // Load file
// //     unsigned char* png = NULL; size_t pnglen = 0;
// //     unsigned err = lodepng_load_file(&png, &pnglen, path);

// //     // #undef printf
// //     // #define printf printf
// //     // printf("Decoding PNG file: %s; pnglen: %d\n", path, (int)pnglen);
// //     // for(int i=0; i<pnglen; i++) {
// //     //     printf("%d ", png[i]);
// //     // }
// //     // printf("\n");
// //     // // // #define printf(...)

// //     if (err) return (int)err;

// //     // Inspect chunks
// //     LodePNGState st; lodepng_state_init(&st);
// //     unsigned w=0,h=0;
// //     err = lodepng_inspect(&w,&h,&st,png,pnglen);
// //     if (err) { lodepng_state_cleanup(&st); free(png); return (int)err; }
// //     int is_gray = (st.info_png.color.colortype == LCT_GREY);
// //     int has_profile = st.info_png.srgb_defined || st.info_png.gama_defined || st.info_png.iccp_defined;
// //     lodepng_state_cleanup(&st);

// //     // Decode
// //     unsigned char* gray = NULL;
// //     unsigned char* rgba = NULL;
// //     if (is_gray) {
// //         LodePNGState st2; lodepng_state_init(&st2);
// //         st2.info_raw.colortype = LCT_GREY;
// //         st2.info_raw.bitdepth  = 8;
// //         err = lodepng_decode(&gray, &w, &h, &st2, png, pnglen);
// //         lodepng_state_cleanup(&st2);

// //         #undef printf
// //         #define printf printf
// //         printf("Decoded gray image: %dx%d  has_profile=%d  err=%d\n", (int)w, (int)h, has_profile, err);
// //         for(int i=0;i<h;i++)
// //         {
// //             for(int j=0;j<w;j++)
// //             {
// //                 printf("%d ",gray[i*w+j]);
// //             }
// //             printf("\n");
// //         }
// //         printf("\n");
// //         // // #define printf(...)
// //     } else {
// //         err = lodepng_decode32(&rgba, &w, &h, png, pnglen);
// //     }
// //     free(png);
// //     if (err) return (int)err;

// //     size_t n = (size_t)w * h;
// //     uint32_t* argb = (uint32_t*)malloc(n * sizeof(uint32_t));
// //     if (!argb) { free(gray); free(rgba); return 100; }

// //     if (is_gray) {                                                                  // is_gray=1
// //         // Build linear->sRGB LUT once
// //         static uint8_t lut[256];
// //         static int lut_init = 0;
// //         if (!lut_init) {                                                            // lut_init=1
// //             for (int v = 0; v < 256; v++) {
// //                 float L = v / 255.0f;           // interpret stored gray as linear
// //                 lut[v] = linear_to_srgb_u8(L);  // encode to sRGB
// //             }
// //             lut_init = 1;
// //         }

// //         if (has_profile) {                                                          // 0
// //             printf("has_prfile\n");
// //             // If PNG already declares sRGB/ICC/gAMA, use bytes as-is (Java does not re-compand)
// //             for (size_t i = 0; i < n; i++) {
// //                 uint8_t g = gray[i];
// //                 argb[i] = 0xFF000000u | (g<<16) | (g<<8) | g;
// //             }
// //         } else {
// //             // No profile: assume linear gray -> sRGB to match ImageIO.getRGB() brightness
// //             for (size_t i = 0; i < n; i++) {
// //                 uint8_t g = lut[gray[i]];
// //                 argb[i] = 0xFF000000u | (g<<16) | (g<<8) | g;
// //             }
// //         }
// //         free(gray);
// //     } else {
// //         // Color case: just pack RGBA -> ARGB (add full sRGB handling if you need perfect parity)
// //         for (size_t i = 0; i < n; i++) {
// //             uint8_t r = rgba[4*i+0], g = rgba[4*i+1], b = rgba[4*i+2], a = rgba[4*i+3];
// //             argb[i] = ((uint32_t)a<<24)|((uint32_t)r<<16)|((uint32_t)g<<8)|b;
// //         }
// //         free(rgba);
// //     }

// //     out->width  = (int)w;
// //     out->height = (int)h;
// //     out->argb   = argb;

// //     #undef printf
// //     #define printf printf
// //     for (size_t i = 0; i < n; i++) {
// //         printf("argb[%d]: %u; ",i,argb[i]);
// //     }
// //     printf("\n");
// //     // // #define printf(...)

// //     return 0;
// // }

// /////////////////////
// // BlockGrid and BlockMap structures

// typedef struct {
//     int x;
//     int y;
// } IntPoint;

// typedef struct {
//     IntPoint blocks;
//     IntPoint corners;
//     int* x;  // size = blocks.x + 1
//     int* y;  // size = blocks.y + 1
// } BlockGrid;

// typedef struct{
// 	IntPoint pixels;
// 	BlockGrid primary;
// 	BlockGrid secondary;
// } BlockMap;


// // typedef struct {
// // 	IntPoint topLeft;
// // 	IntPoint bottomRight;
// // } IntRect;
// typedef struct {
//     int x;
//     int y;
//     int width;
//     int height;
// } IntRect;

// // Constant: ZERO = (0, 0)
// const IntPoint INTPOINT_ZERO = {0, 0};

// // Constant array: EDGE_NEIGHBORS
// const IntPoint EDGE_NEIGHBORS[4] = {
// 	{ 0, -1}, // top
// 	{-1,  0}, // left
// 	{ 1,  0}, // right
// 	{ 0,  1}  // bottom
// };

// // Constant array: CORNER_NEIGHBORS
// const IntPoint CORNER_NEIGHBORS[8] = {
// 	{-1, -1}, // top-left
// 	{ 0, -1}, // top
// 	{ 1, -1}, // top-right
// 	{-1,  0}, // left
// 	{ 1,  0}, // right
// 	{-1,  1}, // bottom-left
// 	{ 0,  1}, // bottom
// 	{ 1,  1}  // bottom-right
// };


// BlockGrid create_block_grid(IntPoint size) {
// 	BlockGrid grid;
// 	grid.blocks = size;
// 	grid.corners.x = size.x + 1;
// 	grid.corners.y = size.y + 1;

// 	grid.x = (int*)malloc(sizeof(int) * grid.corners.x);
// 	grid.y = (int*)malloc(sizeof(int) * grid.corners.y);

// 	return grid;
// }

// BlockGrid create_block_grid_from_dimensions(int width, int height) {
// 	IntPoint size = {width, height};
// 	return create_block_grid(size);
// }

// IntPoint blockgrid_corner(const BlockGrid* grid, int atX, int atY) {
// 	IntPoint pt = { grid->x[atX], grid->y[atY] };
// 	return pt;
// }

// IntPoint blockgrid_corner_point(const BlockGrid* grid, IntPoint at) {
// 	return blockgrid_corner(grid, at.x, at.y);
// }

// IntPoint intpoint_negate(IntPoint p) {
//     IntPoint result;
//     result.x = -p.x;
//     result.y = -p.y;
//     return result;
// }

// bool intpoint_equal(IntPoint a, IntPoint b) {
//     return a.x == b.x && a.y == b.y;
// }

// bool contains_intpoint(IntPoint* array, int size, IntPoint value) {
//     for (int i = 0; i < size; ++i) {
//         if (intpoint_equal(array[i], value))
//             return true;
//     }
//     return false;
// }

// IntRect create_intrect(int x, int y, int width, int height) {
//     IntRect rect;
//     rect.x = x;
//     rect.y = y;
//     rect.width = width;
//     rect.height = height;
//     return rect;
// }

// IntRect intrect_between(IntPoint a, IntPoint b) {
//     int x = a.x;
//     int y = a.y;
//     int width = b.x - a.x;
//     int height = b.y - a.y;
//     return create_intrect(x, y, width, height);
// }

// IntRect move_rect(IntRect rect, IntPoint delta) {
//     IntRect result;
//     result.x = rect.x + delta.x;
//     result.y = rect.y + delta.y;
//     result.width = rect.width;
//     result.height = rect.height;
//     return result;
// }

// IntRect intersect_rect(IntRect a, IntRect b) {
//     int left = fmax(a.x, b.x);
//     int top = fmax(a.y, b.y);
//     int right = fmin(a.x + a.width, b.x + b.width);
//     int bottom = fmin(a.y + a.height, b.y + b.height);

//     IntRect result;
//     result.x = left;
//     result.y = top;
//     result.width = right > left ? right - left : 0;
//     result.height = bottom > top ? bottom - top : 0;

//     return result;
// }



// IntRect blockgrid_block(const BlockGrid* grid, int atX, int atY) {
// 	IntPoint topLeft = blockgrid_corner(grid, atX, atY);
// 	IntPoint bottomRight = blockgrid_corner(grid, atX + 1, atY + 1);
// 	return intrect_between(topLeft, bottomRight);
// }

// IntRect blockgrid_block_point(const BlockGrid* grid, IntPoint at) {
// 	return blockgrid_block(grid, at.x, at.y);
// }


// // --- Helper functions ---
// static inline int round_up_div(int a, int b) {
// 	return (a + b - 1) / b;
// }

// void free_block_grid(BlockGrid* grid) {
// 	free(grid->x);
// 	free(grid->y);
// }

// // Emulate primary.block(x,y).center()
// IntPoint block_center(BlockGrid* grid, int x, int y) {
// 	int center_x = (grid->x[x] + grid->x[x + 1]) / 2;
// 	int center_y = (grid->y[y] + grid->y[y + 1]) / 2;
// 	IntPoint center = {center_x, center_y};
// 	return center;
// }

// BlockMap create_block_map(int width, int height, int maxBlockSize) {
// 	BlockMap map;
// 	map.pixels.x = width;
// 	map.pixels.y = height;
//     // printf("width: %d, height: %d, maxBlockSize: %d\n", width, height, maxBlockSize);

// 	IntPoint primary_blocks = {
// 		round_up_div(width, maxBlockSize),
// 		round_up_div(height, maxBlockSize)
// 	};

//     // printf("primary_blocks.x: %d, primary_blocks.y: %d\n", primary_blocks.x, primary_blocks.y);

// 	map.primary = create_block_grid(primary_blocks);

// 	for (int y = 0; y <= primary_blocks.y; ++y)
// 		map.primary.y[y] = y * height / primary_blocks.y;

// 	for (int x = 0; x <= primary_blocks.x; ++x)
// 		map.primary.x[x] = x * width / primary_blocks.x;

// 	map.secondary = create_block_grid(map.primary.corners);

// 	map.secondary.y[0] = 0;
// 	for (int y = 0; y < primary_blocks.y; ++y)
// 		map.secondary.y[y + 1] = block_center(&map.primary, 0, y).y;
// 	map.secondary.y[map.secondary.blocks.y] = height;

// 	map.secondary.x[0] = 0;
// 	for (int x = 0; x < primary_blocks.x; ++x)
// 		map.secondary.x[x + 1] = block_center(&map.primary, x, 0).x;
// 	map.secondary.x[map.secondary.blocks.x] = width;

// 	return map;
// }

// //////////////////

// #define MAX_LINES 1000000

// typedef struct {
//     int width;
//     int height;
//     float* data;
// } DoubleMatrix;

// DoubleMatrix create_matrix(int width, int height) {
//     DoubleMatrix mat;
//     mat.width = width;
//     mat.height = height;
//     mat.data = calloc(width * height, sizeof(float));
//     return mat;
// }

// void free_matrix(DoubleMatrix* mat) {
//     free(mat->data);
//     free(mat);
// }

// float get(DoubleMatrix* mat, int x, int y) {
//     return mat->data[y * mat->width + x];
// }

// void set(DoubleMatrix* mat, int x, int y, float value) {
//     mat->data[y * mat->width + x] = value;
// }

// // static inline int double_matrix_offset(const DoubleMatrix* matrix, int x, int y) {
// //     return y * matrix->width + x;
// // }

// void double_matrix_add(DoubleMatrix* matrix, int x, int y, float value) {
//     int index = double_matrix_offset(matrix, x, y);
//     matrix->data[index] += value;
// }

// void double_matrix_add_point(DoubleMatrix* matrix, IntPoint at, float value) {
//     double_matrix_add(matrix, at.x, at.y, value);
// }

// void double_matrix_multiply(DoubleMatrix* matrix, int x, int y, float value) {
//     int index = double_matrix_offset(matrix, x, y);
//     matrix->data[index] *= value;
// }

// void double_matrix_multiply_point(DoubleMatrix* matrix, IntPoint at, float value) {
//     double_matrix_multiply(matrix, at.x, at.y, value);
// }

// DoubleMatrix resize_matrix(DoubleMatrix input, int newWidth, int newHeight) {
//     if (newWidth == input.width && newHeight == input.height)
//         return input;

//     DoubleMatrix output = create_matrix(newWidth, newHeight);
//     float scaleX = newWidth / (float)input.width;
//     float scaleY = newHeight / (float)input.height;
//     float descaleX = 1.0 / scaleX;
//     float descaleY = 1.0 / scaleY;

//     for (int y = 0; y < newHeight; ++y) {
//         float y1 = y * descaleY;
//         float y2 = y1 + descaleY;
//         int y1i = (int)y1;
//         int y2i = fmin((int)ceil(y2), input.height);

//         for (int x = 0; x < newWidth; ++x) {
//             float x1 = x * descaleX;
//             float x2 = x1 + descaleX;
//             int x1i = (int)x1;
//             int x2i = fmin((int)ceil(x2), input.width);
//             float sum = 0.0;

//             for (int oy = y1i; oy < y2i; ++oy) {
//                 float ry = fmin(oy + 1.0, y2) - fmax(oy * 1.0, y1);
//                 for (int ox = x1i; ox < x2i; ++ox) {
//                     float rx = fmin(ox + 1.0, x2) - fmax(ox * 1.0, x1);
//                     sum += rx * ry * get(&input, ox, oy);
//                 }
//             }

//             set(&output, x, y, sum * (scaleX * scaleY));
//         }
//     }

//     return output;
// }

// DoubleMatrix resize_dpi(DoubleMatrix input, int dpi) {
//     int newWidth = (int)round(500.0 / dpi * input.width);
//     int newHeight = (int)round(500.0 / dpi * input.height);
//     return resize_matrix(input, newWidth, newHeight);
// }

// // DoubleMatrix decode_image(const uint8_t* image_data, size_t size) {

// //     // return d;
// //     int width, height, channels;

// //     printf("Size: %zu\n", size);
// //     for (int i = 0; i < size; i++) {
// //         printf("%02x ", image_data[i]);
// //         if ((i + 1) % 16 == 0) printf("\n");
// //     }

// //     printf("(int)(size): %d\n", (int)(size));

// //     // // Force 4 channels (RGBA)
// //     // unsigned char* img = stbi_load_from_memory(image_data, (int)(size), &width, &height, &channels, 1);
// //     uint8_t* img = stbi_load("/home/kshitij/SecurSi/read-write-data-from-uart-by-client/pixels_dir/pixelsKshitijleftindexfinger_0.png", &width, &height, &channels, 4);

// //     // Allocate DoubleMatrix
// //     DoubleMatrix decoded;
// //     decoded.width = width;
// //     decoded.height = height;
// //     decoded.data = (float*)malloc(width * height * sizeof(float));

// //     if (!img) {
// //         fprintf(stderr, "Unsupported or invalid image format\n");
// //         fprintf(stderr, "STB reason: %s\n", stbi_failure_reason());  // <-- add this here
// //         return decoded;
// //     }

// //     printf("width: %d, height: %d, channels: %d\n", width, height, channels);

// //     int *pixels = malloc(width * height * sizeof(int));
// //     if (!pixels) {
// //         perror("malloc failed");
// //         exit(1);
// //     }

// //      for (int y = 0; y < height; ++y) {
// //         for (int x = 0; x < width; ++x) {
// //             int idx = (y * width + x) * 4;
// //             uint8_t rr = img[idx + 0];
// //             uint8_t g = img[idx + 1];
// //             uint8_t b = img[idx + 2];
// //             uint8_t a = img[idx + 3];

// //             printf("rr:  %d, g: %d, b: %d, a: %d\n", rr, g, b, a);

// //             // Match Java's ARGB pixel
// //             uint32_t pixel = (a << 24) | (g << 16) | (g << 8) | g;

// //             float px=g;
// //             float intensity = 1-px*1.0/255;

// //             // int color = (pixel & 0xff) + ((pixel >> 8) & 0xff) + ((pixel >> 16) & 0xff);
// //             // float intensity = 1.0f - color * (1.0f / (3.0f * 255.0f));
// //             // // float intensity = 1.0f - pow(r/255,2.2);

// //             printf("Pixel at (y=%d, x=%d): 0x%08x, intensity: %.6f\n", y, x, pixel,intensity);

// //             decoded.data[idx]=intensity;

// //             // Use intensity as needed
// //         }
// //     }

// //     stbi_image_free(img);
// //     return decoded;
// // }

// unsigned char* read_all_bytes(const char* filepath, size_t* out_size) {
//     FILE* file = fopen(filepath, "rb");
//     if (!file) {
//         perror("Failed to open file");
//         return NULL;
//     }

//     // puts file pointer to end of file
//     fseek(file, 0, SEEK_END);
//     // gets position of file pointer
//     size_t size = ftell(file);
//     // moves file pointer again to start of file
//     rewind(file);

//     printf("size: %lu\n",size);

//     unsigned char* buffer = (unsigned char*)malloc(size);
//     if (!buffer) {
//         perror("Memory allocation failed");
//         fclose(file);
//         return NULL;
//     }

//     // copy each byte of size 1 to destination buffer
//     size_t read_size = fread(buffer, 1, size, file);

//     fclose(file);

//     if (read_size != size) {
//         perror("Failed to read entire file");
//         free(buffer);
//         return NULL;
//     }

//     *out_size = size;
//     return buffer;
// }

// typedef struct {
// 	int width;
// 	int height;
// 	int bins;
// 	int* counts;  // Array of size width * height * bins
// } HistogramCube;

// static int offset(const HistogramCube* cube, int x, int y, int z) {
// 	return (y * cube->width + x) * cube->bins + z;
// }

// void print_histogram_cube(const HistogramCube* cube) {
// 	for (int y = 0; y < cube->height; ++y) {
// 		for (int x = 0; x < cube->width; ++x) {
// 			for (int bin = 0; bin < cube->bins; ++bin) {
// 				int value = histogram_cube_get(cube, x, y, bin);
// 				printf("%d ", value); // Print bins in same line
// 			}
// 			printf("\n"); // Newline between blocks
// 		}
// 	}
// }

// HistogramCube create_histogram_cube(int width, int height, int bins) {
//     printf("Inside create_histogram_cube, before creating cube\n");
//     // print_sram_usage();
//     // sleep_ms(8000); 
// 	HistogramCube cube;
// 	cube.width = width;
// 	cube.height = height;
// 	cube.bins = bins;
//     printf("width: %d, height: %d, bins: %d\n", width, height, bins);
//     printf("width * height * bins* sizeof(int): %d\n", width * height * bins* sizeof(int));
// 	cube.counts = (int*)calloc(width * height * bins, sizeof(int));
//     printf("About to go outside create_histogram_cube");
//     // print_sram_usage();
//     // sleep_ms(8000);
// 	return cube;
// }

// HistogramCube create_histogram_cube_from_point(IntPoint size, int bins) {
// 	return create_histogram_cube(size.x, size.y, bins);
// }

// void free_histogram_cube(HistogramCube* cube) {
// 	free(cube->counts);
// 	cube->counts = NULL;
// }

// // Clamp z between 0 and bins-1
// int histogram_cube_constrain(const HistogramCube* cube, int z) {
// 	if (z < 0) return 0;
// 	if (z >= cube->bins) return cube->bins - 1;
// 	return z;
// }

// int histogram_cube_get(const HistogramCube* cube, int x, int y, int z) {
// 	return cube->counts[offset(cube, x, y, z)];
// }

// int histogram_cube_get_at(const HistogramCube* cube, IntPoint at, int z) {
// 	return histogram_cube_get(cube, at.x, at.y, z);
// }

// int histogram_cube_sum(const HistogramCube* cube, int x, int y) {
// 	int sum = 0;
// 	for (int i = 0; i < cube->bins; ++i)
// 		sum += histogram_cube_get(cube, x, y, i);
// 	return sum;
// }

// int histogram_cube_sum_at(const HistogramCube* cube, IntPoint at) {
// 	return histogram_cube_sum(cube, at.x, at.y);
// }

// void histogram_cube_set(HistogramCube* cube, int x, int y, int z, int value) {
// 	cube->counts[offset(cube, x, y, z)] = value;
// }

// void histogram_cube_set_at(HistogramCube* cube, IntPoint at, int z, int value) {
// 	histogram_cube_set(cube, at.x, at.y, z, value);
// }

// void histogram_cube_add(HistogramCube* cube, int x, int y, int z, int value) {
// 	cube->counts[offset(cube, x, y, z)] += value;
// }

// void histogram_cube_add_at(HistogramCube* cube, IntPoint at, int z, int value) {
// 	histogram_cube_add(cube, at.x, at.y, z, value);
// }

// void histogram_cube_increment(HistogramCube* cube, int x, int y, int z) {
// 	histogram_cube_add(cube, x, y, z, 1);
// }

// void histogram_cube_increment_at(HistogramCube* cube, IntPoint at, int z) {
// 	histogram_cube_increment(cube, at.x, at.y, z);
// }

// IntPoint intpoint_add(IntPoint a, IntPoint b) {
//     return (IntPoint){ a.x + b.x, a.y + b.y };
// }

// bool blockgrid_contains(const BlockGrid* grid, IntPoint p) {
//     return p.x >= 0 && p.y >= 0 &&
//            p.x < grid->blocks.x && p.y < grid->blocks.y;
// }

// HistogramCube histogramcube_smooth(const BlockMap* blocks, const HistogramCube* input) {
//     HistogramCube output = create_histogram_cube_from_point(blocks->secondary.blocks, input->bins);

//     IntPoint blocksAround[] = {
//         {0, 0}, {-1, 0}, {0, -1}, {-1, -1}
//     };

//     for (int y = 0; y < blocks->secondary.blocks.y; ++y) {
//         for (int x = 0; x < blocks->secondary.blocks.x; ++x) {
//             IntPoint corner = {x, y};

//             for (int i = 0; i < 4; ++i) {
//                 IntPoint relative = blocksAround[i];
//                 IntPoint block = intpoint_add(corner, relative);

//                 // Check if the block in the neighborhood of the sencodary block, is within the primary blockgrid
//                 if (blockgrid_contains(&blocks->primary, block)) {
//                     for (int bin = 0; bin < input->bins; ++bin) {
//                         int value = histogram_cube_get_at(input, block, bin);
//                         histogram_cube_add_at(&output, corner, bin, value);
//                     }
//                 }
//             }
//         }
//     }

//     // Optional: Logging or visualization
//     print_histogram_cube(&output); // if you want to inspect

//     return output;
// }

// typedef struct {
//     int width;
//     int height;
//     bool* cells;
// } BooleanMatrix;

// // Constructor from dimensions
// BooleanMatrix create_boolean_matrix(int width, int height) {
//     BooleanMatrix matrix;
//     matrix.width = width;
//     matrix.height = height;
//     printf("Creating BooleanMatrix with width: %d, height: %d\n", width, height);
//     matrix.cells = (bool*)(malloc(width * height * sizeof(bool)));
//     for(int i=0;i<width*height;i++)
//     {
//         matrix.cells[i] = false;  // Initialize all cells to false
//     }
//     printf("Created matrix\n");
//     return matrix;
// }

// // Constructor from dimensions
// BooleanMatrix* create_boolean_matrix_pointer(int width, int height) {
//     BooleanMatrix* matrix=(BooleanMatrix*)(malloc(sizeof(BooleanMatrix)));
//     matrix->width = width;
//     matrix->height = height;
//     printf("Creating BooleanMatrix with width: %d, height: %d\n", width, height);
//     matrix->cells = (bool*)(malloc(width * height * sizeof(bool)));
//     for(int i=0;i<width*height;i++)
//     {
//         matrix->cells[i] = false;  // Initialize all cells to false
//     }
//     printf("Created matrix\n");
//     return matrix;
// }

// // Constructor from IntPoint
// BooleanMatrix create_boolean_matrix_from_point(IntPoint size) {
//     return create_boolean_matrix(size.x, size.y);
// }

// // Copy constructor
// BooleanMatrix copy_boolean_matrix(BooleanMatrix* other) {
//     BooleanMatrix matrix = create_boolean_matrix(other->width, other->height);
//     memcpy(matrix.cells, other->cells, other->width * other->height * sizeof(bool));
//     return matrix;
// }

// // Offset helper
// int boolean_matrix_offset(BooleanMatrix* m, int x, int y) {
//     return y * m->width + x;
// }

// // Get
// bool boolean_matrix_get(BooleanMatrix* m, int x, int y) {
//     return m->cells[boolean_matrix_offset(m, x, y)];
// }

// bool boolean_matrix_get_point(BooleanMatrix* m, IntPoint at) {
//     return boolean_matrix_get(m, at.x, at.y);
// }

// bool boolean_matrix_get_fallback(BooleanMatrix* m, int x, int y, bool fallback) {
//     if (x < 0 || y < 0 || x >= m->width || y >= m->height)
//         return fallback;
//     return boolean_matrix_get(m, x, y);
// }

// bool boolean_matrix_get_point_fallback(BooleanMatrix* m, IntPoint at, bool fallback) {
//     return boolean_matrix_get_fallback(m, at.x, at.y, fallback);
// }

// // Set
// void boolean_matrix_set(BooleanMatrix* m, int x, int y, bool value) {
//     m->cells[boolean_matrix_offset(m, x, y)] = value ? true : false;
//     // printf("m->cells[%d] set to %s\n", boolean_matrix_offset(m, x, y), value ? "true" : "false");
// }

// void boolean_matrix_set_point(BooleanMatrix* m, IntPoint at, bool value) {
//     boolean_matrix_set(m, at.x, at.y, value);
// }

// bool boolean_matrix_get_with_fallback(BooleanMatrix* matrix, int x, int y, bool fallback) {
//     if (x < 0 || y < 0 || x >= matrix->width || y >= matrix->height)
//         return fallback;
//     return matrix->cells[y * matrix->width + x];
// }


// // Invert all cells
// void boolean_matrix_invert(BooleanMatrix* m) {
//     int total = m->width * m->height;
//     for (int i = 0; i < total; ++i)
//         m->cells[i] = !m->cells[i];
// }

// // Merge another matrix using OR
// void boolean_matrix_merge(BooleanMatrix* m, BooleanMatrix* other) {
//     if (m->width != other->width || m->height != other->height) {
//         fprintf(stderr, "BooleanMatrix.merge: dimensions do not match!\n");
//         exit(EXIT_FAILURE);
//     }
//     int total = m->width * m->height;
//     for (int i = 0; i < total; ++i)
//         m->cells[i] |= other->cells[i];
// }

// int histogram_offset(HistogramCube* cube, int x, int y, int z) {
//     return (y * cube->width + x) * cube->bins + z;
// }

// int histogram_get(HistogramCube* cube, IntPoint at, int z) {
//     return cube->counts[histogram_offset(cube, at.x, at.y, z)];
// }

// int histogram_sum(HistogramCube* cube, IntPoint at) {
//     int sum = 0;
//     for (int i = 0; i < cube->bins; ++i)
//         sum += histogram_get(cube, at, i);
//     return sum;
// }

// // C version of compute_clipped_contrast
// DoubleMatrix compute_clipped_contrast(BlockMap blocks, HistogramCube histogram) {
//     DoubleMatrix result;
//     result.width = blocks.primary.blocks.x;
//     result.height = blocks.primary.blocks.y;
//     result.data = calloc(result.width * result.height, sizeof(float));
//     printf("result.width: %d, result.height: %d\n", result.width, result.height);
//     printf("blocks.primary.blocks.x: %d, blocks.primary.blocks.y: %d\n", blocks.primary.blocks.x, blocks.primary.blocks.y);

//     for (int y = 0; y < result.height; ++y) {
//         for (int x = 0; x < result.width; ++x) {
//             IntPoint block = {x, y};
//             printf("Computing contrast for block: %d, %d\n", block.x, block.y);
//             printf("histogram.bins: %d, histogram.width: %d, histogram.height: %d\n", histogram.bins, histogram.width, histogram.height);
//             int volume = histogram_sum(&histogram, block);
//             printf("Volume for block %d, %d: %d\n", block.x, block.y, volume);
//             int clipLimit = (int)round(volume * CLIPPED_CONTRAST);
//             int accumulator = 0;
//             int lowerBound = histogram.bins - 1;
//             for (int i = 0; i < histogram.bins; ++i) {
//                 accumulator += histogram_get(&histogram, block, i);
//                 if (accumulator > clipLimit) {
//                     lowerBound = i;
//                     break;
//                 }
//             }
//             printf("Lower bound for block %d, %d: %d\n", block.x, block.y, lowerBound);
//             accumulator = 0;
//             int upperBound = 0;
//             for (int i = histogram.bins - 1; i >= 0; --i) {
//                 accumulator += histogram_get(&histogram, block, i);
//                 if (accumulator > clipLimit) {
//                     upperBound = i;
//                     break;
//                 }
//             }
//             printf("Upper bound for block %d, %d: %d\n", block.x, block.y, upperBound);
//             float contrast = (upperBound - lowerBound) * (1.0 / (histogram.bins - 1));
//             result.data[y * result.width + x] = contrast;
//         }
//     }


//     // log_transparency("contrast", &result);
//     return result;
// }

// // C version of AbsoluteContrastMask.compute
// BooleanMatrix compute_absolute_contrast_mask(DoubleMatrix contrast) {
//     BooleanMatrix result = create_boolean_matrix(contrast.width, contrast.height);
//     printf("Created boolean matrix with width: %d, height: %d\n", result.width, result.height);
//     for (int y = 0; y < contrast.height; ++y) {
//         for (int x = 0; x < contrast.width; ++x) {
//             if (contrast.data[y * contrast.width + x] < MIN_ABSOLUTE_CONTRAST)
//                 boolean_matrix_set(&result, x, y, true);
//         }
//     }
//     // log_transparency("absolute-contrast-mask", &result);
//     return result;
// }

// int compare_doubles_desc(const void* a, const void* b) {
//     float fa = *(const float*)a;
//     float fb = *(const float*)b;
//     if (fb > fa) return 1;
//     else if (fb < fa) return -1;
//     else return 0;
// }

// DoubleMatrix create_double_matrix(int width, int height) {
//     DoubleMatrix matrix;
//     matrix.width = width;
//     matrix.height = height;
//     matrix.data = calloc(width * height, sizeof(float));
//     return matrix;
// }

// int double_matrix_offset(DoubleMatrix* matrix, int x, int y) {
//     return y * matrix->width + x;
// }

// float double_matrix_get(DoubleMatrix* matrix, int x, int y) {
//     return matrix->data[double_matrix_offset(matrix, x, y)];
// }

// void double_matrix_set(DoubleMatrix* matrix, int x, int y, float value) {
//     matrix->data[double_matrix_offset(matrix, x, y)] = value;
// }

// int intpoint_area(IntPoint p) {
//     return p.x * p.y;
// }

// BooleanMatrix compute_relative_contrast_mask(DoubleMatrix contrast, BlockMap blocks) {
//     int total = contrast.width * contrast.height;
//     float* sorted = malloc(total * sizeof(float));
//     memcpy(sorted, contrast.data, total * sizeof(float));
//     // Sort block contrast values in descending order
//     qsort(sorted, total, sizeof(float), compare_doubles_desc);
//     // pixelsPerBlock = number of pixels / number of blocks
//     int pixelsPerBlock = intpoint_area(blocks.pixels) / (blocks.primary.blocks.x * blocks.primary.blocks.y);
//     int sampleCount = RELATIVE_CONTRAST_SAMPLE / pixelsPerBlock;
//     if (sampleCount > total) sampleCount = total;
//     int considered = (int)round(sampleCount * RELATIVE_CONTRAST_PERCENTILE);
//     if (considered < 1) considered = 1;

//     float sum = 0;
//     for (int i = 0; i < considered; ++i)
//         sum += sorted[i];
//     free(sorted);

//     float average = sum / considered;
//     float limit = average * MIN_RELATIVE_CONTRAST;

//     BooleanMatrix result = create_boolean_matrix(contrast.width, contrast.height);
    
//     for (int y = 0; y < contrast.height; ++y) {
//         for (int x = 0; x < contrast.width; ++x) {
//             IntPoint block = {x, y};
//             if (double_matrix_get(&contrast, block.x, block.y) < limit)
//             {
//                 // printf("Setting mask at (%d, %d) to true, contrast: %f, limit: %f\n", x, y, double_matrix_get(&contrast, block), limit);
//                 boolean_matrix_set(&result, x, y, true);
//                 printf("result.cells[%d] = %d\n", boolean_matrix_offset(&result, x, y), boolean_matrix_get(&result, x, y));
//             }
//         }
//     }
//     // log_transparency("relative-contrast-mask", &result);
//     for(int i = 0; i < result.width * result.height; ++i) {
//         printf("result.cells[%d] = %d\n", i, result.cells[i]);
//     }

//     return result;
// }

// typedef struct {
//     int width;
//     int height;
//     int* data;
// } IntMatrix;

// IntMatrix create_int_matrix(int width, int height) {
//     IntMatrix matrix;
//     matrix.width = width;
//     matrix.height = height;
//     matrix.data = calloc(width * height, sizeof(int));
//     return matrix;
// }

// int int_matrix_offset(IntMatrix* m, int x, int y) {
//     return y * m->width + x;
// }

// int int_matrix_get(IntMatrix* m, int x, int y) {
//     return m->data[int_matrix_offset(m, x, y)];
// }

// void int_matrix_set(IntMatrix* m, int x, int y, int value) {
//     m->data[int_matrix_offset(m, x, y)] = value;
// }

// int* compute_thresholds(int radius, float majority, int* out_length) {
//     int window_size = (2 * radius + 1) * (2 * radius + 1);
//     *out_length = window_size + 1;
//     int* thresholds = malloc(sizeof(int) * (*out_length));
//     for (int i = 0; i <= window_size; ++i)
//         thresholds[i] = (int)ceil(majority * i);
//     return thresholds;
// }

// BooleanMatrix vote_filter(BooleanMatrix* input, BooleanMatrix* mask, int radius, float majority, int borderDistance) {
//     printf("In vote_filter: input width=%d, height=%d\n", input->width, input->height);
//     IntPoint size = { input->width, input->height };
//     IntRect rect = { borderDistance, borderDistance, size.x - 2 * borderDistance, size.y - 2 * borderDistance };

//     int threshold_len;
//     int* thresholds = compute_thresholds(radius, majority, &threshold_len);

//     IntMatrix counts = create_int_matrix(size.x, size.y);
//     BooleanMatrix output = create_boolean_matrix(size.x, size.y);

//     for (int y = rect.y; y < rect.y + rect.height; ++y) {
//         int superTop = y - radius - 1;
//         int superBottom = y + radius;
//         int yMin = y - radius < 0 ? 0 : y - radius;
//         int yMax = y + radius >= size.y ? size.y - 1 : y + radius;
//         int yRange = yMax - yMin + 1;

//         for (int x = rect.x; x < rect.x + rect.width; ++x) {
//             if (!mask || boolean_matrix_get(mask, x, y)) {
//                 int left = (x > 0) ? int_matrix_get(&counts, x - 1, y) : 0;
//                 int top = (y > 0) ? int_matrix_get(&counts, x, y - 1) : 0;
//                 int diag = (x > 0 && y > 0) ? int_matrix_get(&counts, x - 1, y - 1) : 0;

//                 int xMin = x - radius < 0 ? 0 : x - radius;
//                 int xMax = x + radius >= size.x ? size.x - 1 : x + radius;
//                 int ones = 0;

//                 if (left > 0 && top > 0 && diag > 0) {
//                     ones = top + left - diag - 1;
//                     int superLeft = x - radius - 1;
//                     int superRight = x + radius;

//                     if (superLeft >= 0 && superTop >= 0 && boolean_matrix_get(input, superLeft, superTop))
//                         ++ones;
//                     if (superLeft >= 0 && superBottom < size.y && boolean_matrix_get(input, superLeft, superBottom))
//                         --ones;
//                     if (superRight < size.x && superTop >= 0 && boolean_matrix_get(input, superRight, superTop))
//                         --ones;
//                     if (superRight < size.x && superBottom < size.y && boolean_matrix_get(input, superRight, superBottom))
//                         ++ones;
//                 } else {
//                     for (int ny = yMin; ny <= yMax; ++ny)
//                         for (int nx = xMin; nx <= xMax; ++nx)
//                             if (boolean_matrix_get(input, nx, ny))
//                                 ++ones;
//                 }

//                 int_matrix_set(&counts, x, y, ones + 1);

//                 if (ones >= thresholds[yRange * (xMax - xMin + 1)])
//                     boolean_matrix_set(&output, x, y, true);
//             }
//         }
//     }

//     free(thresholds);
//     free(counts.data);
//     return output;
// }

// BooleanMatrix apply_vote_filter(BooleanMatrix* input) {
//     return vote_filter(
//         input,
//         NULL,
//         BLOCK_ERRORS_VOTE_RADIUS,
//         BLOCK_ERRORS_VOTE_MAJORITY,
//         BLOCK_ERRORS_VOTE_BORDER_DISTANCE
//     );
// }


// // C version of compute function
// BooleanMatrix compute_mask(BlockMap blocks, HistogramCube histogram) {
//     DoubleMatrix contrast = compute_clipped_contrast(blocks, histogram);
//     printf("contrast.width: %d, contrast.height: %d\n", contrast.width, contrast.height);
//     for(int i=0;i<contrast.height;i++)
//     {
//         for(int j=0;j<contrast.width;j++)
//         {
//             printf("%f ",i,j,contrast.data[i*contrast.width+j]);
//         }
//     }

//     BooleanMatrix mask = compute_absolute_contrast_mask(contrast);
//     printf("mask.width: %d, mask.height: %d\n", mask.width, mask.height);
//     for(int i=0;i<mask.height;i++)
//     {
//         for(int j=0;j<mask.width;j++)   
//         {
//             printf("%d ",boolean_matrix_get(&mask,j,i));
//         }
//         printf("\n");
//     }

//     // BooleanMatrix mask2;

//     BooleanMatrix relative_contrast_mask= compute_relative_contrast_mask(contrast, blocks);
//     printf("relative_contrast_mask.width: %d, relative_contrast_mask.height: %d\n", relative_contrast_mask.width, relative_contrast_mask.height);
//     for (int i = 0; i < relative_contrast_mask.height; i++) {
//         for (int j = 0; j < relative_contrast_mask.width; j++) {
//             printf("%d ", boolean_matrix_get(&relative_contrast_mask, j, i));
//         }
//         printf("\n");
//     }

//     boolean_matrix_merge(&mask, &relative_contrast_mask);
//     BooleanMatrix mask2 = apply_vote_filter(&mask);
//     boolean_matrix_merge(&mask, &mask2);
//     boolean_matrix_invert(&mask);

//     mask2 = apply_vote_filter(&mask);
//     boolean_matrix_merge(&mask, &mask2);

//     mask2 = apply_vote_filter(&mask);
//     boolean_matrix_merge(&mask, &mask2);

//     mask2 = vote_filter(
//         &mask,
//         NULL,
//         MASK_VOTE_RADIUS,
//         MASK_VOTE_MAJORITY,
//         MASK_VOTE_BORDER_DISTANCE
//     );
//     boolean_matrix_merge(&mask, &mask2);

//     printf("fin mask.width: %d, fin mask.height: %d\n", mask.width, mask.height);
//     for(int i=0;i<mask.height;i++)
//     {
//         for(int j=0;j<mask.width;j++)   
//         {
//             printf("%d ",boolean_matrix_get(&mask,j,i));
//         }
//         printf("\n");
//     }
   
//     // BooleanMatrix mask = compute_absolute_contrast_mask(contrast);
//     // BooleanMatrix relmask = compute_relative_contrast_mask(contrast, blocks);
//     // boolean_matrix_merge(&mask, &relmask);
//     // log_transparency("combined-mask", mask);

//     // BooleanMatrix f1 = filter(&mask);
//     // boolean_matrix_merge(&mask, &f1);
//     // boolean_matrix_invert(&mask);
//     // BooleanMatrix f2 = filter(&mask);
//     // boolean_matrix_merge(&mask, &f2);
//     // BooleanMatrix f3 = filter(&mask);
//     // boolean_matrix_merge(&mask, &f3);

//     // BooleanMatrix voted = vote_filter(&mask, NULL, MASK_VOTE_RADIUS, MASK_VOTE_MAJORITY, MASK_VOTE_BORDER_DISTANCE);
//     // boolean_matrix_merge(&mask, &voted);

//     // log_transparency("filtered-mask", mask);
//     free(contrast.data);
//     free(relative_contrast_mask.cells);
//     free(mask2.cells);

//     return mask;
// }

// typedef struct {
//     int width;
//     int height;
//     int bins;
//     float** data;
// } MappingTable;

// MappingTable create_mapping_table(int width, int height, int bins) {
//     printf("IN create_mapping_table, before creating table\n");
//     printf("width: %d, height: %d, bins: %d\n", width, height, bins);
//     // print_sram_usage();
//     MappingTable table;
//     table.width = width;
//     table.height = height;
//     table.bins = bins;
//     // float->float
//     table.data = malloc(width * height * sizeof(float*));
//     for (int i = 0; i < width * height; ++i) {
//         table.data[i] = calloc(bins, sizeof(float));
//     }
//     printf("AFter creating table\n");
//     // print_sram_usage();
//     return table;
// }

// float* mapping_table_get(MappingTable* table, IntPoint pt) {
//     if (pt.x < 0 || pt.y < 0 || pt.x >= table->width || pt.y >= table->height) {
//         fprintf(stderr, "mapping_table_get: Index out of bounds (%d, %d)\n", pt.x, pt.y);
//         exit(EXIT_FAILURE);
//     }
//     return table->data[pt.y * table->width + pt.x];
// }

// void mapping_table_free(MappingTable* table) {
//     for (int i = 0; i < table->width * table->height; ++i) {
//         free(table->data[i]);
//     }
//     free(table->data);
// }

// // Computes square of a number
// float sq(float value) {
//     return value * value;
// }

// // Linear interpolation between two values
// float interpolate(float start, float end, float position) {
//     return start + position * (end - start);
// }

// // Bilinear interpolation using four corners and x/y positions
// float interpolate_doubles(float bottomleft, float bottomright, float topleft, float topright, float x, float y) {
//     float left = interpolate(topleft, bottomleft, y);
//     float right = interpolate(topright, bottomright, y);
//     return interpolate(left, right, x);
// }

// // Exponential interpolation (e.g., for equalization scaling)
// float interpolate_exponential(float start, float end, float position) {
//     return pow(end / start, position) * start;
// }


// // ImageEqualization function
// DoubleMatrix equalize_image(BlockMap blocks, DoubleMatrix image, HistogramCube histogram, BooleanMatrix blockMask) {
//     printf("In equalize_image\n");

//     //float->float
//     const float rangeMin = -1;
//     const float rangeMax = 1;
//     const float rangeSize = rangeMax - rangeMin;
//     const float widthMax = rangeSize / 256.0 * MAX_EQUALIZATION_SCALING;
//     const float widthMin = rangeSize / 256.0 * MIN_EQUALIZATION_SCALING;

//     // float->float
//     float* limitedMin = malloc(histogram.bins * sizeof(float));
//     float* limitedMax = malloc(histogram.bins * sizeof(float));
//     float* dequantized = malloc(histogram.bins * sizeof(float));

//     for (int i = 0; i < histogram.bins; ++i) {
//         limitedMin[i] = fmax(i * widthMin + rangeMin, rangeMax - (histogram.bins - 1 - i) * widthMax);
//         limitedMax[i] = fmin(i * widthMax + rangeMin, rangeMax - (histogram.bins - 1 - i) * widthMin);
//         dequantized[i] = i / (float)(histogram.bins - 1);
//     }

//     MappingTable mappings = create_mapping_table(blocks.secondary.blocks.x, blocks.secondary.blocks.y, histogram.bins);

//     for (int by = 0; by < blocks.secondary.blocks.y; ++by) {
//         for (int bx = 0; bx < blocks.secondary.blocks.x; ++bx) {
//             IntPoint corner = {bx, by};
//             float* mapping = mapping_table_get(&mappings, corner);

//             if (boolean_matrix_get_with_fallback(&blockMask, bx, by, false) ||
//                 boolean_matrix_get_with_fallback(&blockMask, bx - 1, by, false) ||
//                 boolean_matrix_get_with_fallback(&blockMask, bx, by - 1, false) ||
//                 boolean_matrix_get_with_fallback(&blockMask, bx - 1, by - 1, false)) {

//                 int volume = histogram_cube_sum(&histogram, corner.x, corner.y);
                 
//                 float step = rangeSize / volume;
//                 float top = rangeMin;

//                 for (int i = 0; i < histogram.bins; ++i) {
//                     // float->float
//                     float band = histogram_cube_get(&histogram, corner.x,corner.y,i) * step;
//                     float equalized = top + dequantized[i] * band;
                    
//                     top += band;
//                     if (equalized < limitedMin[i]) equalized = limitedMin[i];
//                     if (equalized > limitedMax[i]) equalized = limitedMax[i];
//                     mapping[i] = equalized;
//                 }
//             }
//         }
//     }

//     DoubleMatrix result = create_double_matrix(blocks.pixels.x, blocks.pixels.y);

//     for (int by = 0; by < blocks.primary.blocks.y; ++by) {
//         for (int bx = 0; bx < blocks.primary.blocks.x; ++bx) {
//             IntPoint block = {bx, by};
//             IntRect area = blockgrid_block_point(&blocks.primary, block);

//             if (boolean_matrix_get(&blockMask, bx, by)) {
//                 float* topleft = mapping_table_get(&mappings, block);
//                 float* topright = mapping_table_get(&mappings, (IntPoint){block.x + 1, block.y});
//                 float* bottomleft = mapping_table_get(&mappings, (IntPoint){block.x, block.y + 1});
//                 float* bottomright = mapping_table_get(&mappings, (IntPoint){block.x + 1, block.y + 1});

//                 for (int y = area.y; y < area.y + area.height; ++y) {
//                     for (int x = area.x; x < area.x + area.width; ++x) {
//                         int depth = histogram_cube_constrain(&histogram, (int)(double_matrix_get(&image, x, y) * histogram.bins));
//                         float rx = (x - area.x + 0.5) / area.width;
//                         float ry = (y - area.y + 0.5) / area.height;
//                         float value = interpolate_doubles(bottomleft[depth], bottomright[depth], topleft[depth], topright[depth], rx, ry);
//                         double_matrix_set(&result, x, y, value);
//                     }
//                 }
//             } else {
//                 for (int y = area.y; y < area.y + area.height; ++y) {
//                     for (int x = area.x; x < area.x + area.width; ++x) {
//                         double_matrix_set(&result, x, y, -1);
//                     }
//                 }
//             }
//         }
//     }

//     free(limitedMin);
//     free(limitedMax);
//     free(dequantized);
//     mapping_table_free(&mappings);

//     return result;
// }

// // float->float
// /*DoublePointMatrx*/
// typedef struct {
//     int width;
//     int height;
//     // float* vectors; // Stores [x0, y0, x1, y1, ...]
//     float* vectors;
// } DoublePointMatrix;

// DoublePointMatrix create_double_point_matrix(int width, int height) {
//     printf("In create_double_point_matrix (width=%d, height=%d), before creating matrix\n", width, height);
//     // print_sram_usage();
//     DoublePointMatrix matrix;
//     matrix.width = width;
//     matrix.height = height;
//     // float->float
//     matrix.vectors = malloc(2 * width * height * sizeof(float));
//     for(int i=0;i<2*width*height;i++)
//     {
//         matrix.vectors[i] = 0.0;  // Initialize all vectors to zero
//     }

//     printf("After creating matrix\n");
//     // print_sram_usage();

//     return matrix;
// }


// int double_point_matrix_offset(DoublePointMatrix* matrix, int x, int y) {
//     return 2 * (y * matrix->width + x);
// }

// //float->float
// void double_point_matrix_set(DoublePointMatrix* matrix, int x, int y, float px, float py) {
//     int i = double_point_matrix_offset(matrix, x, y);
//     matrix->vectors[i] = px;
//     matrix->vectors[i + 1] = py;
// }

// //float->float
// void double_point_matrix_add(DoublePointMatrix* matrix, int x, int y, float px, float py) {
//     int i = double_point_matrix_offset(matrix, x, y);
//     matrix->vectors[i] += px;
//     matrix->vectors[i + 1] += py;
// }


// //float->float
// typedef struct {
//     float x;
//     float y;
// } DoublePoint;


// // Constant
// const DoublePoint DOUBLE_POINT_ZERO = {0.0f, 0.0f};

// // Constructor
// DoublePoint create_double_point(float x, float y) {
//     DoublePoint p = {x, y};
//     return p;
// }

// // Add two points
// DoublePoint add_doublepoint(DoublePoint a, DoublePoint b) {
//     return create_double_point(a.x + b.x, a.y + b.y);
// }

// // Negate a point
// DoublePoint negate_doublepoint(DoublePoint p) {
//     return create_double_point(-p.x, -p.y);
// }

// // Multiply point by scalar
// DoublePoint multiply_doublepoint(DoublePoint p, float factor) {
//     return create_double_point(factor * p.x, factor * p.y);
// }



// DoublePoint to_vector(float angle) {
//     DoublePoint result;
//     result.x = cos(angle);
//     result.y = sin(angle);
//     return result;
// }


// DoublePoint double_point_matrix_get(const DoublePointMatrix* m, int x, int y) {
//     int index = double_point_matrix_offset(m, x, y);
//     DoublePoint dp;
//     dp.x = m->vectors[index];
//     dp.y = m->vectors[index + 1];
//     return dp;
// }

// float double_point_matrix_get_x(DoublePointMatrix* matrix, int x, int y) {
//     return matrix->vectors[double_point_matrix_offset(matrix, x, y)];
// }

// float double_point_matrix_get_y(DoublePointMatrix* matrix, int x, int y) {
//     return matrix->vectors[double_point_matrix_offset(matrix, x, y) + 1];
// }

// /*PixelWiseOrientation*/

// float atan_doublepoint(DoublePoint vector) {
//     float angle = atan2(vector.y, vector.x);
//     return angle >= 0 ? angle : angle + PI2;
// }

// float atan_intpoint(IntPoint vector) {
//     DoublePoint d = { vector.x, vector.y };
//     return atan_doublepoint(d);
// }

// float atan_from_points(IntPoint center, IntPoint point) {
//     IntPoint delta = { point.x - center.x, point.y - center.y };
//     return atan_intpoint(delta);
// }

// DoublePoint to_doublepoint(IntPoint p) {
//     DoublePoint result;
//     result.x = (float)p.x;
//     result.y = (float)p.y;
//     return result;
// }

// float to_orientation(float angle) {
//     return angle < M_PI ? 2.0 * angle : 2.0 * (angle - M_PI);
// }

// float from_orientation(float angle) {
//     return 0.5 * angle;
// }

// float add_double_angle(float start, float delta) {
//     float angle = start + delta;
//     return angle < PI2 ? angle : angle - PI2;
// }

// float bucket_center(int bucket, int resolution) {
//     return PI2 * (2 * bucket + 1) / (2.0 * resolution);
// }

// int quantize_angle(float angle, int resolution) {
//     // printf("quantize_angle: angle=%f, INV_PI2: %f, resolution=%d\n", angle, INV_PI2, resolution);
//     int result = (int)(angle * INV_PI2 * resolution);
//     // printf("quantize_angle: result=%d\n", result);
//     if (result < 0) return 0;
//     else if (result >= resolution) return resolution - 1;
//     else return result;
// }

// float opposite_angle(float angle) {
//     return angle < M_PI ? angle + M_PI : angle - M_PI;
// }

// float distance_between_angles(float first, float second) {
//     float delta = fabs(first - second);
//     return delta <= M_PI ? delta : PI2 - delta;
// }

// float difference_between_angles(float first, float second) {
//     float angle = first - second;
//     return angle >= 0 ? angle : angle + PI2;
// }

// float complementary_angle(float angle) {
//     float complement = PI2 - angle;
//     return complement < PI2 ? complement : complement - PI2;
// }

// bool is_normalized_angle(float angle) {
//     return angle >= 0 && angle < PI2;
// }

// int java_round(float x) {
//     return (int)floor(x + 0.5);
// }

// // Round to IntPoint (assumes IntPoint is already defined)
// IntPoint round_doublepoint(DoublePoint p) {
//     IntPoint result = {
//         // .x = (int)round(p.x),
//         // .y = (int)round(p.y)
//         .x = (int)java_round(p.x),
//         .y = (int)java_round(p.y)
//     };
//     return result;
// }

// typedef struct {
//     int start;
//     int end;
// } IntRange;

// const IntRange INT_RANGE_ZERO = {0, 0};

// int int_range_length(IntRange range) {
//     return range.end - range.start;
// }
// typedef struct {
//     IntPoint offset;
//     DoublePoint orientation;
// } ConsideredOrientation;

// typedef struct {
//     unsigned long long state;
// } OrientationRandom;

// // #define ORIENTATION_SPLIT 50
// // #define ORIENTATIONS_CHECKED 20
// #define ORIENTATION_SPLIT 30
// #define ORIENTATIONS_CHECKED 10
// #define MIN_ORIENTATION_RADIUS 2
// #define MAX_ORIENTATION_RADIUS 6

// void orientation_random_init(OrientationRandom* rng) {
//     rng->state = 1610612741ULL * 1610612741ULL * 1610612741ULL;
// }

// float orientation_random_next(OrientationRandom* rng) {
//     const unsigned long long PRIME = 1610612741ULL;
//     const int BITS = 30;
//     const unsigned long long MASK = (1ULL << BITS) - 1;
//     const float SCALING = 1.0 / (1ULL << BITS);
//     rng->state *= PRIME;
//     return ((rng->state & MASK) + 0.5) * SCALING;
// }

// bool intpoint_equals(IntPoint a, IntPoint b) {
//     return a.x == b.x && a.y == b.y;
// }

// ConsideredOrientation** plan_orientations() {
//     printf("In planned_orientations\n");
//     // print_sram_usage();
//     OrientationRandom rng;
//     orientation_random_init(&rng);

//     ConsideredOrientation** splits = malloc(sizeof(ConsideredOrientation*) * ORIENTATION_SPLIT);

//     for (int i = 0; i < ORIENTATION_SPLIT; ++i) {
//         splits[i] = malloc(sizeof(ConsideredOrientation) * ORIENTATIONS_CHECKED);
//         for (int j = 0; j < ORIENTATIONS_CHECKED; ++j) {
//             ConsideredOrientation* sample = &splits[i][j];
//             bool conflict;
//             do {
//                 conflict = false;
//                 float angle = orientation_random_next(&rng) * M_PI;
//                 float distance = interpolate_exponential(MIN_ORIENTATION_RADIUS, MAX_ORIENTATION_RADIUS, orientation_random_next(&rng));
//                 sample->offset = round_doublepoint(multiply_doublepoint(to_vector(angle), distance));
//                 if ((sample->offset.x == 0 && sample->offset.y == 0) || sample->offset.y < 0)
//                     conflict = true;
//                 else {
//                     for (int k = 0; k < j; ++k) {
//                         if (intpoint_equals(splits[i][k].offset, sample->offset)) {
//                             conflict = true;
//                             break;
//                         }
//                     }
//                 }
//             } while (conflict);
//             float direction = atan_doublepoint(to_doublepoint(sample->offset));
//             float orient_angle = add_double_angle(to_orientation(direction), M_PI);
//             sample->orientation = to_vector(orient_angle);
//         }
//     }

//     printf("After planned_orientations\n");
//     // print_sram_usage();
//     return splits;
// }

// IntRange compute_mask_range(BooleanMatrix* mask, int y) {
//     int first = -1, last = -1;
//     for (int x = 0; x < mask->width; ++x) {
//         if (boolean_matrix_get(mask, x, y)) {
//             last = x;
//             if (first < 0)
//                 first = x;
//         }
//     }
//     IntRange result;
//     if (first >= 0)
//         result = (IntRange){ first, last + 1 };
//     else
//         result = (IntRange){ 0, 0 };
//     return result;
// }

// IntRect blockmap_block(BlockMap* map, int bx, int by) {
//     IntRect rect;
//     // printf("blockmap_block: bx=%d, by=%d\n", bx, by);
        
//     // printf("map->primary.blocks.x: %d, map->primary.blocks.y: %d\n", map->primary.blocks.x, map->primary.blocks.y);
    
//     if (!map->primary.y) {
//         fprintf(stderr, "Error: map->primary.y is NULL\n");
//         exit(1);
//     }

//     // for(int i=0;i<map->primary.blocks.x;i++)
//     // {
//     //     printf("map->primary.x[%d]: %d\n", i, map->primary.x[i]);
//     // }
//     // for(int i=0;i<map->primary.blocks.y;i++)
//     // {
//     //     printf("map->primary.y[%d]: %d\n", i, map->primary.y[i]);
//     // }

//     rect.x = map->primary.x[bx];
//     rect.y = map->primary.y[by];
//     rect.width = map->primary.x[bx + 1] - map->primary.x[bx];
//     rect.height = map->primary.y[by + 1] - map->primary.y[by];
//     return rect;
// }

// DoublePointMatrix compute_pixelwise_orientations(DoubleMatrix* input, BooleanMatrix* mask, BlockMap* blocks) {
//     ConsideredOrientation** neighbors = plan_orientations();
//     DoublePointMatrix orientation = create_double_point_matrix(input->width, input->height);
//     printf("In compute_pixelwise_orientations, after create_double_point_matrix\n");
//     // print_sram_usage();

//     for(int i=0;i<blocks->primary.corners.x;i++)
//     {
//         printf("BBB2locks.primary.x[%d]: %d\n",i,blocks->primary.x[i]);
//     }
//     for(int i=0;i<blocks->primary.corners.y;i++)
//     {
//         printf("BBB2locks.primary.y[%d]: %d\n",i,blocks->primary.y[i]);
//     }

//     for (int blockY = 0; blockY < blocks->primary.blocks.y; ++blockY) {
//         IntRange range = compute_mask_range(mask, blockY);
//         if (range.end > range.start) {
//             IntRect left_rect = blockmap_block(blocks, range.start, blockY);
//             IntRect right_rect = blockmap_block(blocks, range.end - 1, blockY);
//             IntRange validX = (IntRange){ left_rect.x, right_rect.x + right_rect.width };

//             IntRect base_rect = blockmap_block(blocks, 0, blockY);
//             for (int y = base_rect.y; y < base_rect.y + base_rect.height; ++y) {
//                 for (int j = 0; j < ORIENTATIONS_CHECKED; ++j) {
//                     ConsideredOrientation* neighbor = &neighbors[y % ORIENTATION_SPLIT][j];
//                     int radius = fmax(abs(neighbor->offset.x), abs(neighbor->offset.y));
//                     if (y - radius >= 0 && y + radius < input->height) {
//                         IntRange x_range = {
//                             fmax(radius, validX.start),
//                             fmin(input->width - radius, validX.end)
//                         };
//                         for (int x = x_range.start; x < x_range.end; ++x) {
//                             float before = double_matrix_get(input, x - neighbor->offset.x, y - neighbor->offset.y);
//                             float at = double_matrix_get(input, x, y);
//                             float after = double_matrix_get(input, x + neighbor->offset.x, y + neighbor->offset.y);
//                             float strength = at - fmax(before, after);
//                             if (strength > 0)
//                                 double_point_matrix_add(&orientation, x, y,
//                                     neighbor->orientation.x * strength,
//                                     neighbor->orientation.y * strength);
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < ORIENTATION_SPLIT; ++i)
//         free(neighbors[i]);
//     free(neighbors);

//     return orientation;
// }


// DoublePointMatrix aggregate_orientation(DoublePointMatrix* orientation, BlockMap* blocks, BooleanMatrix* mask) {
//     IntPoint gridSize = blocks->primary.blocks;
//     DoublePointMatrix sums = create_double_point_matrix(gridSize.x, gridSize.y);
//     printf("In aggregate orientation\n");

//     for (int by = 0; by < gridSize.y; ++by) {
//         for (int bx = 0; bx < gridSize.x; ++bx) {
//             if (boolean_matrix_get(mask, bx, by)) {
//                 IntRect area = blockmap_block(blocks, bx, by);
//                 for (int y = area.y; y < area.y + area.height; ++y) {
//                     for (int x = area.x; x < area.x + area.width; ++x) {
//                         DoublePoint dp = double_point_matrix_get(orientation, x, y);
//                         IntPoint block = {bx, by};
//                         // printf("(x: %d,y: %d): (block.x: %d, block.y: %d), (d.x: %f, d.y: %f)\n", x, y, block.x, block.y, dp.x, dp.y);
//                         double_point_matrix_add(&sums, block.x, block.y, dp.x, dp.y);
//                     }
//                 }
//             }
//         }
//     }

//     // If you want to log the result, insert your logging function here
//     // log_double_point_matrix("block-orientation", &sums);

//     return sums;
// }


// DoublePointMatrix smooth_orientation(DoublePointMatrix orientation, BooleanMatrix* mask, int radius) {
//     DoublePointMatrix smoothed = create_double_point_matrix(mask->width, mask->height);
//     for (int y = 0; y < mask->height; ++y) {
//         for (int x = 0; x < mask->width; ++x) {
//             IntPoint block = {x, y};
//             if (boolean_matrix_get(mask, block.x, block.y)) {
//                 for (int dy = -radius; dy <= radius; ++dy) {
//                     for (int dx = -radius; dx <= radius; ++dx) {
//                         int nx = x + dx, ny = y + dy;
//                         if (nx >= 0 && ny >= 0 && nx < mask->width && ny < mask->height) {
//                             IntPoint neighbor = {nx, ny};
//                             if (boolean_matrix_get(mask, neighbor.x, neighbor.y)) {
//                                 DoublePoint v = double_point_matrix_get(&orientation, neighbor.x, neighbor.y);
//                                 double_point_matrix_add(&smoothed, block.x, block.y, v.x, v.y);
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return smoothed;
// }

// DoubleMatrix compute_angles(DoublePointMatrix* vectors, BooleanMatrix* mask) {
//     DoubleMatrix angles = create_double_matrix(mask->width, mask->height);
//     for (int y = 0; y < mask->height; ++y) {
//         for (int x = 0; x < mask->width; ++x) {
//             if (boolean_matrix_get(mask, x, y)) {
//                 DoublePoint dp = double_point_matrix_get(vectors, x, y);
//                 float angle = atan_doublepoint(dp);
//                 IntPoint p = {x, y};
//                 double_matrix_set(&angles, p.x, p.y, angle);
//             }
//         }
//     }
//     return angles;
// }

// DoubleMatrix compute_orientation(DoubleMatrix image, BooleanMatrix mask, BlockMap blocks) {
//     DoublePointMatrix accumulated = compute_pixelwise_orientations(&image, &mask, &blocks);
//     printf("accumulated.width: %d, accumulated.height: %d\n", accumulated.width, accumulated.height);
//     // for(int i=0;i<accumulated.width;i++)
//     // {
//     //     for(int j=0;j<accumulated.height;j++)
//     //     {
//     //         DoublePoint dp = double_point_matrix_get(&accumulated, i, j);
//     //         printf("(%d, %d): (%f, %f)\n", i, j, dp.x, dp.y);
//     //     }
//     // }

//     DoublePointMatrix byBlock = aggregate_orientation(&accumulated, &blocks, &mask);
//     free(accumulated.vectors);

//     printf("blocked.width: %d, blocked.height: %d\n", byBlock.width, byBlock.height);
//     // for(int i=0;i<byBlock.width;i++)
//     // {   
//     //     for(int j=0;j<byBlock.height;j++)
//     //     {
//     //         DoublePoint dp = double_point_matrix_get(&byBlock, j, i);
//     //         printf("(%d, %d): (%f, %f)\n", i, j, dp.x, dp.y);
//     //     }
//     // }
//     DoublePointMatrix smooth = smooth_orientation(byBlock, &mask, ORIENTATION_SMOOTHING_RADIUS);
//     free(byBlock.vectors);

//     DoubleMatrix orientation_fin =  compute_angles(&smooth, &mask);
//     free(smooth.vectors);

//     printf("Orientation computed: width=%d, height=%d\n", orientation_fin.width, orientation_fin.height);
//     // for (int i = 0; i < orientation_fin.height; ++i) {
//     //     for (int j = 0; j < orientation_fin.width; ++j) {           
//     //         printf("%f ", double_matrix_get(&orientation_fin, j, i));
//     //     }
//     //     printf("\n");   
//     // }

//     return orientation_fin;
// }

// /*//////////////  OrientedSmoothing ////////////////*/
// float add_angles(float start, float delta) {
//     float angle = start + delta;
//     return (angle < PI2) ? angle : (angle - PI2);
// }

// IntPoint** generate_lines(int resolution, int radius, float step, int* out_line_lengths) {
//     IntPoint** result = malloc(resolution * sizeof(IntPoint*));
//     *out_line_lengths = 0;

//     for (int i = 0; i < resolution; ++i) {
//         IntPoint* line = malloc(256 * sizeof(IntPoint)); // max size guess
//         int line_size = 0;
//         line[line_size++] = (IntPoint){0, 0};

//         float angle = from_orientation(bucket_center(i, resolution));
//         DoublePoint direction = to_vector(angle);

//         for (float r = radius; r >= 0.5; r /= step) {
//             IntPoint sample = round_doublepoint(multiply_doublepoint(direction, r));
//             if (!contains_intpoint(line, line_size, sample)) {
//                 line[line_size++] = sample;
//                 line[line_size++] = intpoint_negate(sample);
//             }
//         }

//         result[i] = malloc(line_size * sizeof(IntPoint));
//         memcpy(result[i], line, line_size * sizeof(IntPoint));
//         out_line_lengths[i] = line_size;
//         free(line);
//     }

//     return result;
// }


// DoubleMatrix smooth(DoubleMatrix input, DoubleMatrix orientation, BooleanMatrix mask, BlockMap* blocks, float angle, IntPoint** lines, int* line_lengths, int resolution) {
//     DoubleMatrix output = create_double_matrix(input.width, input.height);

//     // printf("Inside smmoth\n");
//     // for(int i=0;i<orientation.width;i++)
//     // {
//     //     for(int j=0;j<orientation.height;j++)
//     //     {
//     //         printf("(%d, %d): %f\n", i, j, double_matrix_get(&orientation, i, j));
//     //     }
//     // }

//     for (int by = 0; by < blocks->primary.blocks.y; ++by) {
//         for (int bx = 0; bx < blocks->primary.blocks.x; ++bx) {
//             if (boolean_matrix_get(&mask, bx, by)) {
//                 printf("Processing block (%d, %d)\n", bx, by);
//                 IntPoint block = {bx, by};
//                 float base_angle = double_matrix_get(&orientation, bx, by);
//                 float sum_angle = add_angles(base_angle, angle);
//                 int index = quantize_angle(sum_angle, resolution);
                
//                 IntPoint* line = lines[index];
//                 int line_len = line_lengths[index];
//                 // printf("line_len: %d, index: %d, base_angle: %f, sum_angle: %f\n", line_len, index, base_angle, sum_angle);

//                 IntRect target = blockmap_block(blocks, bx, by);
//                 for (int i = 0; i < line_len; ++i) {
//                     IntPoint offset = line[i];
//                     // printf("offset: (%d, %d)\n", offset.x, offset.y);
//                     IntRect source = move_rect(target, offset);
//                     // printf("source: (%d, %d, %d, %d)\n", source.x, source.y, source.width, source.height);
//                     source = intersect_rect(source, (IntRect){0, 0, blocks->pixels.x, blocks->pixels.y});
//                     // printf("source after intersection: (%d, %d, %d, %d)\n", source.x, source.y, source.width, source.height);
//                     IntRect target_moved = move_rect(source, intpoint_negate(offset));
//                     // printf("target_moved: (%d, %d, %d, %d)\n", target_moved.x, target_moved.y, target_moved.width, target_moved.height);
//                     for (int y = target_moved.y; y < target_moved.y + target_moved.height; ++y)
//                         for (int x = target_moved.x; x < target_moved.x + target_moved.width; ++x)
//                             double_matrix_add(&output, x, y, double_matrix_get(&input, x + offset.x, y + offset.y));
//                 }

//                 for (int y = target.y; y < target.y + target.height; ++y)
//                     for (int x = target.x; x < target.x + target.width; ++x)
//                         double_matrix_multiply(&output, x, y, 1.0 / line_len);
                
//                 // printf("Block (%d, %d) processed. Output:\n",bx,by);
//                 // for(int i=0;i<output.width;i++)
//                 // {
//                 //     for(int j=0;j<output.height;j++)
//                 //     {
//                 //         printf("%f ", double_matrix_get(&output, i, j));
//                 //     }
//                 //     printf("\n");
//                 // }
//             }
//         }
//     }

//     return output;
// }

// DoubleMatrix oriented_smoothing_parallel(DoubleMatrix input, DoubleMatrix orientation, BooleanMatrix mask, BlockMap* blocks) {
//     int resolution = PARALLEL_SMOOTHING_RESOLUTION;
//     int radius = PARALLEL_SMOOTHING_RADIUS;
//     float step = PARALLEL_SMOOTHING_STEP;
    
//     // printf("Inside parallel\n");
//     // printf("orientation.width: %d, orientation.height: %d\n",orientation.width,orientation.height);

//     // for(int i=0;i<orientation.width;i++)
//     // {
//     //     for(int j=0;j<orientation.height;j++)
//     //     {
//     //         printf("(%d, %d): %f\n", i, j, double_matrix_get(&orientation, i, j));
//     //     }
//     // }

//     int* line_lengths = malloc(resolution * sizeof(int));
//     IntPoint** lines = generate_lines(resolution, radius, step, line_lengths);
//     for (int i = 0; i < resolution; ++i) {
//         printf("lines Orientation %d:\n", i);
//         for (int j = 0; j < line_lengths[i]; ++j) {
//             printf("(%d, %d) ", lines[i][j].x, lines[i][j].y);
//         }
//         printf("\n");
//     }
    
//     DoubleMatrix result = smooth(input, orientation, mask, blocks, 0.0, lines, line_lengths, resolution);

//     // free lines
//     for (int i = 0; i < resolution; ++i)
//         free(lines[i]);
//     free(lines);
//     free(line_lengths);

//     return result;
// }

// DoubleMatrix oriented_smoothing_orthogonal(DoubleMatrix input, DoubleMatrix orientation, BooleanMatrix mask, BlockMap* blocks) {
//     int resolution = ORTHOGONAL_SMOOTHING_RESOLUTION;
//     int radius = ORTHOGONAL_SMOOTHING_RADIUS;
//     float step = ORTHOGONAL_SMOOTHING_STEP;

//     int* line_lengths = malloc(resolution * sizeof(int));
//     IntPoint** lines = generate_lines(resolution, radius, step, line_lengths);
//     DoubleMatrix result = smooth(input, orientation, mask, blocks, M_PI, lines, line_lengths, resolution);

//     // free lines
//     for (int i = 0; i < resolution; ++i)
//         free(lines[i]);
//     free(lines);
//     free(line_lengths);

//     return result;
// }

// ////////// Binarized image ///////////////
// IntRect BlockGrid_block(BlockGrid* grid, int atX, int atY) {
//     int left = grid->x[atX];
//     int top = grid->y[atY];
//     int right = grid->x[atX + 1];
//     int bottom = grid->y[atY + 1];

//     IntRect rect;
//     rect.x = left;
//     rect.y = top;
//     rect.width = right - left;
//     rect.height = bottom - top;
//     return rect;
// }


// #define IDX(width, x, y) ((y) * (width) + (x))

// bool get_boolean(const BooleanMatrix* m, int x, int y) {
//     return m->cells[IDX(m->width, x, y)];
// }

// void set_boolean(BooleanMatrix* m, int x, int y, bool value) {
//     m->cells[IDX(m->width, x, y)] = value;
// }


// BooleanMatrix binarize(const DoubleMatrix* input, const DoubleMatrix* baseline, const BooleanMatrix* mask, const BlockMap* blocks) {
//     IntPoint size = {input->width, input->height};
//     BooleanMatrix binarized = create_boolean_matrix(size.x, size.y);

//     for (int by = 0; by < blocks->primary.blocks.y; ++by) {
//         for (int bx = 0; bx < blocks->primary.blocks.x; ++bx) {
//             IntPoint block = {bx, by};

//             if (get_boolean(mask, block.x, block.y)) {
//                 // printf("bin Processing block (%d, %d)\n", block.x, block.y);
//                 IntRect rect = BlockGrid_block(&blocks->primary, block.x, block.y);
//                 // printf("BlockRect: (%d, %d, %d, %d)\n", rect.x, rect.y, rect.width, rect.height);

//                 for (int y = rect.y; y < rect.y + rect.height; ++y) {
//                     for (int x = rect.x; x < rect.x + rect.width; ++x) {
//                         float diff = input->data[IDX(input->width, x, y)] - baseline->data[IDX(input->width, x, y)];
//                         if (diff > 0)
//                         {
//                             // printf("Setting binarized at (%d, %d) to true\n", x, y);
//                             set_boolean(&binarized, x, y, true);
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     return binarized;
// }

// void set_boolean_matrix(BooleanMatrix* matrix, int x, int y, bool value) {
//     if (x >= 0 && x < matrix->width && y >= 0 && y < matrix->height) {
//         matrix->cells[y * matrix->width + x] = value;
//     }
// }

// void free_boolean_matrix(BooleanMatrix* matrix) {
//     if (matrix->cells != NULL) {
//         free(matrix->cells);
//         matrix->cells = NULL;
//     }
//     matrix->width = 0;
//     matrix->height = 0;
// }

// bool get_boolean_matrix(const BooleanMatrix* matrix, int x, int y) {
//     if (x >= 0 && x < matrix->width && y >= 0 && y < matrix->height) {
//         return matrix->cells[y * matrix->width + x];
//     }
//     return false;  // or handle error differently
// }

// bool get_boolean_matrix_safe(BooleanMatrix* matrix, int x, int y) {
//     if (x < 0 || x >= matrix->width || y < 0 || y >= matrix->height)
//         return false;
//     return matrix->cells[y * matrix->width + x];
// }

// void binarize_cleanup(BooleanMatrix* binary, const BooleanMatrix* mask) {
//     printf("In binarize_cleanup\n");
//     IntPoint size = { binary->width, binary->height };

//     // Invert binary
//     BooleanMatrix inverted = create_boolean_matrix(size.x, size.y);
//     for (int y = 0; y < size.y; ++y) {
//         for (int x = 0; x < size.x; ++x) {
//             bool value = get_boolean(binary, x, y);
//             set_boolean(&inverted, x, y, !value);
//         }
//     }

//     printf("inverted.width: %d, inverted.height: %d\n", inverted.width, inverted.height);

//     free_boolean_matrix(&inverted);

//     // islands = VoteFilter.vote(inverted, mask, ...)
//     BooleanMatrix islands = vote_filter(
//         &inverted,
//         mask,
//         BINARIZED_VOTE_RADIUS,
//         BINARIZED_VOTE_MAJORITY,
//         BINARIZED_VOTE_BORDER_DISTANCE
//     );

//     printf("islands.width: %d, islands.height: %d\n", islands.width, islands.height);

//     // holes = VoteFilter.vote(binary, mask, ...)
//     BooleanMatrix holes = vote_filter(
//         binary,
//         mask,
//         BINARIZED_VOTE_RADIUS,
//         BINARIZED_VOTE_MAJORITY,
//         BINARIZED_VOTE_BORDER_DISTANCE
//     );

//     printf("holes.width: %d, holes.height: %d\n", holes.width, holes.height);

//     // binary = binary && !islands || holes
//     for (int y = 0; y < size.y; ++y) {
//         for (int x = 0; x < size.x; ++x) {
//             bool bin = get_boolean(binary, x, y);
//             bool isl = get_boolean(&islands, x, y);
//             bool hol = get_boolean(&holes, x, y);
//             set_boolean(binary, x, y, (bin && !isl) || hol);
//         }
//     }

//     // Remove diagonal crosses
//     remove_crosses(binary);

//     // Optional logging
//     // log_boolean_matrix("filtered-binary-image", binary);

//     // Cleanup
//     free_boolean_matrix(&islands);
//     free_boolean_matrix(&holes);
// }


// void remove_crosses(BooleanMatrix* input) {
//     IntPoint size = {input->width, input->height};
//     bool any = true;
//     while (any) {
//         any = false;
//         for (int y = 0; y < size.y - 1; ++y) {
//             for (int x = 0; x < size.x - 1; ++x) {
//                 bool a = get_boolean(input, x, y);
//                 bool b = get_boolean(input, x + 1, y + 1);
//                 bool c = get_boolean(input, x, y + 1);
//                 bool d = get_boolean(input, x + 1, y);
//                 if ((a && b && !c && !d) || (c && d && !a && !b)) {
//                     set_boolean(input, x, y, false);
//                     set_boolean(input, x, y + 1, false);
//                     set_boolean(input, x + 1, y, false);
//                     set_boolean(input, x + 1, y + 1, false);
//                     any = true;
//                 }
//             }
//         }
//     }
// }

// BooleanMatrix invert(BooleanMatrix* binary, BooleanMatrix* mask) {
//     IntPoint size = {binary->width, binary->height};
//     BooleanMatrix inverted = create_boolean_matrix(size.x, size.y);
//     for (int y = 0; y < size.y; ++y) {
//         for (int x = 0; x < size.x; ++x) {
//             bool val = !get_boolean(binary, x, y) && get_boolean(mask, x, y);
//             set_boolean(&inverted, x, y, val);
//         }
//     }
//     return inverted;
// }




// ////////////////////////////////

// //////////////////////
// BooleanMatrix pixelwise(BooleanMatrix* mask, BlockMap* blocks) {
//     int block_width = blocks->primary.blocks.x;
//     int block_height = blocks->primary.blocks.y;

//     BooleanMatrix pixelized = create_boolean_matrix(blocks->pixels.x, blocks->pixels.y);

//     for (int by = 0; by < block_height; ++by) {
//         for (int bx = 0; bx < block_width; ++bx) {
//             if (get_boolean_matrix(mask, bx, by)) {
//                 IntRect rect = BlockGrid_block(&blocks->primary, bx, by);
//                 for (int y = rect.y; y < rect.y + rect.height; ++y) {
//                     for (int x = rect.x; x < rect.x + rect.width; ++x) {
//                         set_boolean_matrix(&pixelized, x, y, true);
//                     }
//                 }
//             }
//         }
//     }

//     // No TransparencySink in C, you can log if needed:
//     // print_boolean_matrix(&pixelized); // optional for debug
//     return pixelized;
// }

// BooleanMatrix shrink(BooleanMatrix* mask, int amount) {
//     IntPoint size = {mask->width, mask->height};
//     BooleanMatrix shrunk = create_boolean_matrix(size.x, size.y);

//     for (int y = amount; y < size.y - amount; ++y) {
//         for (int x = amount; x < size.x - amount; ++x) {
//             bool val =
//                 get_boolean(mask, x, y - amount) &&
//                 get_boolean(mask, x, y + amount) &&
//                 get_boolean(mask, x - amount, y) &&
//                 get_boolean(mask, x + amount, y);
//             set_boolean(&shrunk, x, y, val);
//         }
//     }

//     return shrunk;
// }

// BooleanMatrix inner(BooleanMatrix* outer) {
//     printf("In inner mask computation\n");
//     IntPoint size = {outer->width, outer->height};
//     BooleanMatrix inner = create_boolean_matrix(size.x, size.y);

//     // Copy central region
//     for (int y = 1; y < size.y - 1; ++y) {
//         for (int x = 1; x < size.x - 1; ++x) {
//             bool val = get_boolean(outer, x, y);
//             set_boolean(&inner, x, y, val);
//         }
//     }

//     // Shrink inner by 1 if necessary
//     if (INNER_MASK_BORDER_DISTANCE >= 1) {
//         BooleanMatrix temp = shrink(&inner, 1);
//         free_boolean_matrix(&inner);
//         inner = temp;
//         // free_boolean_matrix(temp);
//     }

//     int total = 1;
//     for (int step = 1; total + step <= INNER_MASK_BORDER_DISTANCE; step *= 2) {
//         BooleanMatrix temp = shrink(&inner, step);
//         free_boolean_matrix(&inner);
//         inner = temp;
//         // free_boolean_matrix(temp);
//         total += step;
//     }

//     if (total < INNER_MASK_BORDER_DISTANCE) {
//         int remaining = INNER_MASK_BORDER_DISTANCE - total;
//         BooleanMatrix temp = shrink(&inner, remaining);
//         free_boolean_matrix(&inner);
//         inner = temp;
//     }

//     // log_boolean_matrix("inner-mask", &inner); // Optional logging
//     return inner;
// }

// //////////// Skeleton ////////////////////////
// typedef enum {
//     SKELETON_RIDGES,
//     SKELETON_VALLEYS
// } SkeletonType;

// static const char* SkeletonTypePrefix[] = {
//     [SKELETON_RIDGES] = "ridges-",
//     [SKELETON_VALLEYS] = "valleys-"
// };

// ////////////// SkeletonRidge and SkeletonMinutiae
// struct SkeletonRidge; // forward declaration

// typedef struct SkeletonMinutia {
//     IntPoint position;
//     struct SkeletonRidge** ridges;
//     int ridge_count;
//     int ridge_capacity;
// } SkeletonMinutia;

// typedef struct SkeletonRidge {
//     IntPoint* points;
//     int point_count;
//     int point_capacity;

//     struct SkeletonRidge* reversed;
//     SkeletonMinutia* startMinutia;
//     SkeletonMinutia* endMinutia;

//     int is_view; 
//     unsigned char freed;
// } SkeletonRidge;


// typedef struct {
//     SkeletonType type;
//     IntPoint size;
//     SkeletonMinutia** minutiae;  // dynamically allocated array
//     int count;
//     int capacity;
// } Skeleton;

// ///////

// static inline IntPoint ridge_point_at(const SkeletonRidge* h, int i) {
//     const SkeletonRidge* b = h->is_view ? h->reversed : h;
//     // bounds check! (return {0,0} or assert on OOB)
//     return h->is_view ? b->points[b->point_count - 1 - i] : b->points[i];
// }

// static inline SkeletonRidge* base_of(SkeletonRidge* r) {
//     if (!r) return NULL;
//     return (r->is_view && r->reversed) ? r->reversed : r;
// }

// void expand_size(SkeletonRidge* ridge) {
//     SkeletonRidge* base = base_of(ridge);
//     if (base->point_count == base->point_capacity) {
//         base->point_capacity = base->point_capacity * 2 + 1;
//         base->points = realloc(base->points, sizeof(IntPoint) * base->point_capacity);
//         if (base->reversed) 
//         {
//             base->reversed->point_count = base->point_count;
//             base->reversed->point_capacity = base->point_capacity;
//         }
//     }
// }

// /////////

// void init_skeleton_minutia(SkeletonMinutia* m, IntPoint position) {
//     m->position = position;
//     m->ridge_capacity = 4;
//     m->ridge_count = 0;
//     m->ridges = malloc(sizeof(SkeletonRidge*) * m->ridge_capacity);
// }

// void free_skeleton_minutia(SkeletonMinutia* m) {
//     free(m->ridges);
// }

// // m is assumed to have all base_of originally
// // r is also assumed to be base_of
// bool minutia_contains_ridge(SkeletonMinutia* m, SkeletonRidge* r) {
//     for (int i = 0; i < m->ridge_count; ++i)
//         if (m->ridges[i] == r)
//             return true;
//     return false;
// }

// void minutia_attach_start(SkeletonMinutia* m, SkeletonRidge* r); // forward

// void minutia_add_ridge(SkeletonMinutia* m, SkeletonRidge* r) {
//     if (!minutia_contains_ridge(m, r)) {
//         if (m->ridge_count == m->ridge_capacity) {
//             // m->ridge_capacity *= 2;
//             m->ridge_capacity = m->ridge_capacity * 3 / 2 + 1;

//             m->ridges = realloc(m->ridges, sizeof(SkeletonRidge*) * m->ridge_capacity);
//         }
//         m->ridges[m->ridge_count++] = r;
//         minutia_attach_start(m, r); // call after add
//     }
// }

// void minutia_remove_ridge(SkeletonMinutia* m, SkeletonRidge* r) {
//     for (int i = 0; i < m->ridge_count; ++i) {
//         if (m->ridges[i] == r) {
//             for (int j = i + 1; j < m->ridge_count; ++j)
//                 m->ridges[j - 1] = m->ridges[j];
//             m->ridge_count--;
//             break;
//         }
//     }
// }

// void ridge_set_start(SkeletonRidge* ridge, SkeletonMinutia* value);
// void ridge_set_end(SkeletonRidge* ridge, SkeletonMinutia* value);

// void minutia_attach_start(SkeletonMinutia* m, SkeletonRidge* r) {
//     if (!minutia_contains_ridge(m, r)) {
//         minutia_add_ridge(m, r);
//         ridge_set_start(r, m);
//     }
// }

// void minutia_detach_start(SkeletonMinutia* m, SkeletonRidge* r) {
//     if (minutia_contains_ridge(m, r)) {
//         minutia_remove_ridge(m, r);
//         if (r->startMinutia == m)
//             ridge_set_start(r, NULL);
//     }
// }

// void reverse_ridge_points(SkeletonRidge* ridge) {
//     // SkeletonRidge* rev = ridge->reversed;
//     // rev->point_capacity = ridge->point_count;
//     // rev->point_count = ridge->point_count;
//     // rev->points = malloc(sizeof(IntPoint) * rev->point_capacity);

//     // for (int i = 0; i < ridge->point_count; ++i) {
//     //     rev->points[i] = ridge->points[ridge->point_count - 1 - i];
//     // }

//     SkeletonRidge* base = base_of(ridge);

//     if (base->reversed) 
//     {
//         base->reversed->point_count = base->point_count;
//         base->reversed->point_capacity = base->point_capacity;
//     }
// }


// SkeletonRidge* create_ridge() {
//     SkeletonRidge* r = malloc(sizeof(SkeletonRidge));
//     r->point_capacity = 8;
//     r->point_count = 0;
//     r->points = malloc(sizeof(IntPoint) * r->point_capacity);
//     r->is_view = 0; // This is the real one
//     r->freed = 0;
    
//     r->reversed = malloc(sizeof(SkeletonRidge));
//     r->reversed->point_capacity = 8;
//     r->reversed->point_count = 0;
//     // r->reversed->points = malloc(sizeof(IntPoint) * r->point_capacity); // will allocate after reversal
//     r->reversed->reversed = r;
//     r->reversed->is_view = 1; // This is the view
//     r->reversed->freed = 0;

//     r->startMinutia = NULL;
//     r->endMinutia = NULL;
//     r->reversed->startMinutia = NULL;
//     r->reversed->endMinutia = NULL;

//     return r;
// }

// void ridge_set_start(SkeletonRidge* ridge, SkeletonMinutia* value) {
//     // Skip if value minutiae is already on ridge
//     if (ridge->startMinutia != value) {
//         // If ridge was already connected to some minutia, detach it
//         // Remove the ridge from the old minutaie detachFrom's ridge list using minutia_detach_start
//         if (ridge->startMinutia != NULL) {
//             SkeletonMinutia* detachFrom = ridge->startMinutia;
//             ridge->startMinutia = NULL;
//             minutia_detach_start(detachFrom, ridge);
//         }

//         // New startMinutiae for ridge is value
//         ridge->startMinutia = value;
//         // Add the ridge to the new minutia’s list (if non-null) via minutia_attach_start.
//         if (value != NULL)
//             minutia_attach_start(value, ridge);
//         ridge->reversed->endMinutia = value;
//     }
// }

// void ridge_set_end(SkeletonRidge* ridge, SkeletonMinutia* value) {
//     if (ridge->endMinutia != value) {
//         printf("Setting endMinutia\n");
//         ridge->endMinutia = value;
//         ridge_set_start(ridge->reversed, value);
//     }
// }

// void ridge_detach(SkeletonRidge* ridge) {
//     ridge_set_start(ridge, NULL);
//     ridge_set_end(ridge, NULL);
// }

// ////////////////// SkeletonTracing
// #define INITIAL_HASHMAP_CAPACITY 64


// bool point_equals(IntPoint a, IntPoint b) {
//     return (a.x == b.x && a.y == b.y);
// }

// typedef struct {
//     IntPoint* keys;
//     void** values;
//     int size;
//     int capacity;
// } HashMap;

// HashMap* create_hash_map() {
//     HashMap* map = malloc(sizeof(HashMap));
//     map->capacity = INITIAL_HASHMAP_CAPACITY;
//     map->size = 0;
//     map->keys = malloc(sizeof(IntPoint) * map->capacity);
//     map->values = malloc(sizeof(void*) * map->capacity);
//     return map;
// }

// void* hash_map_get(HashMap* map, IntPoint key) {
//     for (int i = 0; i < map->size; ++i) {
//         if (point_equals(map->keys[i], key))
//             return map->values[i];
//     }
//     return NULL;
// }

// void hash_map_put(HashMap* map, IntPoint key, void* value) {
//     for (int i = 0; i < map->size; ++i) {
//         if (point_equals(map->keys[i], key)) {
//             map->values[i] = value;
//             return;
//         }
//     }
//     if (map->size == map->capacity) {
//         // map->capacity *= 2;
//         map->capacity = map->capacity * 3 / 2 + 1;
//         map->keys = realloc(map->keys, sizeof(IntPoint) * map->capacity);
//         map->values = realloc(map->values, sizeof(void*) * map->capacity);
//     }
//     map->keys[map->size] = key;
//     map->values[map->size] = value;
//     map->size++;
// }


// // IntPointArray definition
// typedef struct IntPointArray {
//     IntPoint* data;
//     int size;
//     int capacity;
// } IntPointArray;

// void free_int_point_array(IntPointArray* array) {
//     if (array) {
//         free(array->data);
//         free(array);
//     }
// }

// void free_minutia_link_map(HashMap* linking) {
//     HashMap* seen = create_hash_map();
//     for (int i = 0; i < linking->size; ++i) {
//         IntPointArray* arr = (IntPointArray*)linking->values[i];
//         if (hash_map_get(seen, (IntPoint){(intptr_t)arr, 0}) == NULL) {
//             hash_map_put(seen, (IntPoint){(intptr_t)arr, 0}, arr);  // dummy key to track
//             free_int_point_array(arr);
//         }
//     }
//     free(seen->keys);
//     free(seen->values);
//     free(seen);
//     free(linking->keys);
//     free(linking->values);
//     free(linking);
// }


// void free_minutia_map(HashMap* map) {
//     if (!map) return;
//     // Do NOT free SkeletonMinutia* — they are owned by the skeleton
//     free(map->keys);
//     free(map->values);
//     free(map);
// }

// IntPointArray* create_int_point_array(int capacity) {
//     IntPointArray* array = malloc(sizeof(IntPointArray));
//     array->data = malloc(capacity * sizeof(IntPoint));
//     array->size = 0;
//     array->capacity = capacity;
//     return array;
// }

// void append_int_point(IntPointArray* array, IntPoint point) {
//     if (array->size == array->capacity) {
//         array->capacity *= 2;
//         // array->capacity = array->capacity * 3 / 2 + 1;
//         array->data = realloc(array->data, array->capacity * sizeof(IntPoint));
//     }
//     array->data[array->size++] = point;
// }

// // int java_round(float x) {
// //     return (int)floor(x + 0.5);
// // }

// IntPointArray* line_to(IntPoint a, IntPoint b) {
//     IntPointArray* result;
//     int dx = b.x - a.x;
//     int dy = b.y - a.y;

//     printf("a.x: %d, a.y: %d, b.x: %d, b.y: %d\n",a.x,a.y,b.x,b.y);

//     if (abs(dx) >= abs(dy)) {
//         int length = abs(dx) + 1;
//         result = create_int_point_array(length);
//         if (dx > 0) {
//             for (int i = 0; i <= dx; ++i) {
//                 int y_offset = java_round(i * (dy / (float)dx));
//                 printf("i: %d, dy: %d, dx: %d\n",i,dy,dx);
//                 printf("a.y: %d, y_offset: %d, a.y+y_offset: %d\n",a.y,y_offset,a.y+y_offset);
//                 append_int_point(result, (IntPoint){ a.x + i, a.y + y_offset });
//             }
//         } else if (dx < 0) {
//             for (int i = 0; i <= -dx; ++i) {

//                 int y_offset = java_round(i * (dy / (float)dx));
//                 printf("i: %d, dy: %d, dx: %d\n",i,dy,dx);
//                 printf("dy / (float)dx: %f\n",dy / (float)dx);
//                 printf("i*(dy / (float)dx): %f\n",i*(dy / (float)dx));

//                 printf("a.y: %d, y_offset: %d, a.y-y_offset: %d\n",a.y,y_offset,a.y-y_offset);
//                 append_int_point(result, (IntPoint){ a.x - i, a.y - y_offset });
//             }
//         } else {
//             append_int_point(result, a);
//         }
//     } else {
//         int length = abs(dy) + 1;
//         result = create_int_point_array(length);
//         if (dy > 0) {
//             for (int i = 0; i <= dy; ++i) {
//                 int x_offset = java_round(i * (dx / (float)dy));
//                 printf("a.y: %d, i: %d, a.y+i: %d\n",a.y,i,a.y+i);
//                 append_int_point(result, (IntPoint){ a.x + x_offset, a.y + i });
//             }
//         } else if (dy < 0) {
//             for (int i = 0; i <= -dy; ++i) {
//                 int x_offset = java_round(i * (dx / (float)dy));
//                 printf("a.y: %d, i: %d, a.y-i: %d\n",a.y,i,a.y-i);
//                 append_int_point(result, (IntPoint){ a.x - x_offset, a.y - i });
//             }
//         } else {
//             append_int_point(result, a);
//         }
//     }

//     return result;
// }


// IntPointArray* create_int_point_array_empty() {
//     IntPointArray* array = malloc(sizeof(IntPointArray));
//     array->size = 0;
//     array->capacity = 8;
//     array->data = malloc(array->capacity * sizeof(IntPoint));
//     return array;
// }

// void push_point(IntPointArray* array, IntPoint p) {
//     if (array->size == array->capacity) {
//         array->capacity *= 2;
//         // array->capacity = array->capacity * 3 / 2 + 1;
//         array->data = realloc(array->data, array->capacity * sizeof(IntPoint));
//     }
//     array->data[array->size++] = p;
// }

// void push_point_skeletonridge(SkeletonRidge* ridge, IntPoint point) {
//     printf("In push_point_skeletonridge\n");
//     // print_sram_usage();

//     SkeletonRidge* base = base_of(ridge);
//     if (base->point_count >= base->point_capacity) {
//         base->point_capacity = base->point_capacity ? base->point_capacity * 2 : 8;
//         base->points = realloc(base->points, base->point_capacity * sizeof(IntPoint));
//     }
//     base->points[base->point_count++] = point;

//     if (base->reversed) 
//     {
//         base->reversed->point_count = base->point_count;
//         base->reversed->point_capacity = base->point_capacity;
//     }

//     // // Ensure capacity for ridge
//     // if (ridge->point_count >= ridge->point_capacity) {
//     //     printf("ridge->point_count: %d, ridge->point_capacity: %d\n",ridge->point_count,ridge->point_capacity);
//     //     ridge->point_capacity = ridge->point_capacity > 0 ? ridge->point_capacity * 2 : 8;
//     //     printf("New ridge->point_capacity: %d\n",ridge->point_capacity);
//     //     ridge->points = realloc(ridge->points, ridge->point_capacity * sizeof(IntPoint));
//     //     if (!ridge->points) {
//     //         fprintf(stderr, "Memory allocation failed in push_point (ridge)\n");
//     //         exit(1);
//     //     }
//     // }

//     // // Add to original ridge (append)
//     // ridge->points[ridge->point_count++] = point;

//     // // Add to reversed ridge (prepend)
//     // if (ridge->reversed) {
//     //     SkeletonRidge* rev = ridge->reversed;

//     //     // Ensure capacity
//     //     if (rev->point_count >= rev->point_capacity) {
//     //         printf("rev->point_count: %d, rev->point_capacity: %d\n",rev->point_count,rev->point_capacity);
//     //         rev->point_capacity = rev->point_capacity > 0 ? rev->point_capacity * 2 : 8;
//     //         printf("Before realloc, New rev->point_count: %d, rev->point_capacity: %d\n",rev->point_count,rev->point_capacity);
//     //         rev->points = realloc(rev->points, rev->point_capacity * sizeof(IntPoint));
//     //         printf("rev->points: %p\n",rev->points);

//     //         if (!rev->points) {
//     //             fprintf(stderr, "Memory allocation failed in push_point (reversed)\n");
//     //             exit(1);
//     //         }
//     //     }

//     //     // Shift existing points right to make space at index 0
//     //     for (int i = rev->point_count; i > 0; --i)
//     //         rev->points[i] = rev->points[i - 1];

//     //     // Prepend to reversed
//     //     rev->points[0] = point;
//     //     rev->point_count++;
//     // }
// }


// IntPoint add_points(IntPoint a, IntPoint b) {
//     IntPoint result = {a.x + b.x, a.y + b.y};
//     return result;
// }


// IntPointArray* find_minutiae(BooleanMatrix* thinned) {
//     IntPointArray* result = create_int_point_array_empty();
//     for (int y = 0; y < thinned->height; ++y) {
//         for (int x = 0; x < thinned->width; ++x) {
//             if (get_boolean_matrix(thinned, x, y)) {
//                 int count = 0;
//                 for (int i = 0; i < 8; ++i) {
//                     IntPoint neighbor = add_points((IntPoint){x, y}, CORNER_NEIGHBORS[i]);
//                     if (get_boolean_matrix_safe(thinned, neighbor.x, neighbor.y))
//                         ++count;
//                 }
//                 // If pixel at position has one neighbour thats also true (ridge endings)
//                 // and more than 2 neighbours (ridge bifurcations) that are true, then its a MINUTIAE
//                 if (count == 1 || count > 2)
//                     push_point(result, (IntPoint){x, y});
//             }
//         }
//     }
//     return result;
// }

// // linkNeighboringMinutiae translated to C
// //  Each group of neighboring minutiae ends up sharing the same IntPointArray*
// HashMap* link_neighboring_minutiae(IntPointArray* minutiae) {
//     HashMap* linking = create_hash_map();
//     for (int i = 0; i < minutiae->size; ++i) {
//         IntPoint minutiaPos = minutiae->data[i];
//         IntPointArray* ownLinks = NULL;
//         for (int j = 0; j < 8; ++j) {
//             IntPoint neighborRelative = CORNER_NEIGHBORS[j];
//             IntPoint neighborPos = add_points(minutiaPos, neighborRelative);
//             IntPointArray* neighborLinks = (IntPointArray*)hash_map_get(linking, neighborPos);
//             // sets of points exist for some neighbour of minutiaPos - neighborLinks != NULL
//             if (neighborLinks && neighborLinks != ownLinks) {
//                 if (ownLinks != NULL) {
//                     for (int k = 0; k < ownLinks->size; ++k)
//                         push_point(neighborLinks, ownLinks->data[k]);
                    
//                     // Each ownLinks point is added to neighborLinks; so array is same for all ownLinks in this case
//                     for (int k = 0; k < ownLinks->size; ++k)
//                         hash_map_put(linking, ownLinks->data[k], neighborLinks);
//                 }
//                 ownLinks = neighborLinks;
//             }
//         }
//         if (ownLinks == NULL)
//             ownLinks = create_int_point_array_empty();
//         push_point(ownLinks, minutiaPos);

//         // Basically, for each minutiae position minutiaePos, we add value corresponding to it as ownLinks
//         hash_map_put(linking, minutiaPos, ownLinks);
//     }
//     return linking;
// }

// SkeletonMinutia* deep_copy_minutia(SkeletonMinutia* src) {
//     SkeletonMinutia* copy = malloc(sizeof(SkeletonMinutia));
//     copy->position = src->position;
//     copy->ridge_count = src->ridge_count;
//     copy->ridge_capacity = src->ridge_capacity;

//     // Allocate and copy ridges array (shallow copy of ridge pointers)
//     copy->ridges = malloc(copy->ridge_capacity * sizeof(SkeletonRidge*));
//     for (int i = 0; i < copy->ridge_count; ++i) {
//         copy->ridges[i] = src->ridges[i];  // still shallow for now
//     }

//     return copy;
// }


// // minutiaCenters in C
// // Note that skeleton is intially empty

// // The build_minutia_centers function adds only one minutia (at the centroid) per connected component to the Skeleton
// // centers[primary_pos]=SkeletonMinutia* for the primary position of the component; single SkeletonMinutia* — that is, a pointer to one specific SkeletonMinutia structure, representing the centroid of that connected component
// // build_minutia_centers with pointer array
// HashMap* build_minutia_centers(Skeleton* skeleton, HashMap* linking) {
//     HashMap* centers = create_hash_map();
//     for (int i = 0; i < linking->size; ++i) {
//         IntPoint current_pos = linking->keys[i];
//         IntPointArray* linked_minutiae = (IntPointArray*)hash_map_get(linking, current_pos);
//         IntPoint primary_pos = linked_minutiae->data[0];

//         if (hash_map_get(centers, primary_pos) == NULL) {
//             IntPoint sum = {0, 0};
//             for (int j = 0; j < linked_minutiae->size; ++j)
//                 sum = add_points(sum, linked_minutiae->data[j]);
//             IntPoint center = {sum.x / linked_minutiae->size, sum.y / linked_minutiae->size};
//             SkeletonMinutia* minutia = malloc(sizeof(SkeletonMinutia));
//             init_skeleton_minutia(minutia, center);
//             if (skeleton->count == skeleton->capacity) {
//                 // skeleton->capacity *= 2;
//                 skeleton->capacity = skeleton->capacity * 3 / 2 + 1;
//                 skeleton->minutiae = realloc(skeleton->minutiae, skeleton->capacity * sizeof(SkeletonMinutia*));
//             }
//             skeleton->minutiae[skeleton->count] = minutia;
//             hash_map_put(centers, primary_pos, minutia);
//             skeleton->count++;
//         }
//         hash_map_put(centers, current_pos, hash_map_get(centers, primary_pos));
//     }
//     return centers;
// }


// // HashMap* build_minutia_centers(Skeleton* skeleton, HashMap* linking) {
// //     HashMap* centers = create_hash_map();
// //     for (int i = 0; i < linking->size; ++i) {
// //         // FOr all keys in linking hashmap; keys are of type IntPoint(position) and value is IntPointArray*
// //         IntPoint current_pos = linking->keys[i];
// //         IntPointArray* linked_minutiae = (IntPointArray*)hash_map_get(linking, current_pos);
// //         IntPoint primary_pos = linked_minutiae->data[0];

// //         // If primary_pos is NOT already in our newly created centers hashmap, create a new SkeletonMinutia at the center of linked_minutiae
// //         // and add to centers hashmap
// //         if (hash_map_get(centers, primary_pos) == NULL) {
// //             IntPoint sum = {0, 0};
// //             for (int j = 0; j < linked_minutiae->size; ++j)
// //                 sum = add_points(sum, linked_minutiae->data[j]);
// //             // Get center of all linked minutaie, whose primary_pos is linking[linking->keys[i]]
// //             IntPoint center = {sum.x / linked_minutiae->size, sum.y / linked_minutiae->size};
// //             // SkeletonMinutia minutia;
// //             SkeletonMinutia* minutia = malloc(sizeof(SkeletonMinutia));
// //             // create skeleton_minutaie (CREATE A MINUTIAE) whose position is the center, and it has ridges
// //             init_skeleton_minutia(minutia, center);
// //             // Add to skeleton
// //             if (skeleton->count == skeleton->capacity) {
// //                 skeleton->capacity *= 2;
// //                 skeleton->minutiae = realloc(skeleton->minutiae, skeleton->capacity * sizeof(SkeletonMinutia));
// //             }

// //             // Add the newly created centroid minutiae to the old skeleton
// //             skeleton->minutiae[skeleton->count] = *(deep_copy_minutia(minutia));
// //             hash_map_put(centers, primary_pos, &skeleton->minutiae[skeleton->count]);
// //             skeleton->count++;
// //         }
// //         hash_map_put(centers, current_pos, hash_map_get(centers, primary_pos));
// //     }
// //     return centers;
// // }


// // traceRidges in C
// // trace all ridges between SKeletonMinutaie points and create SkeletonRidge for each ridge
// // BooleanMatrix* thinned is a binary skeleton image (1 for ridge pixels, 0 for background).
// // HashMap* minutiae_points maps IntPoint → SkeletonMinutia* for all detected minutiae.
// // Each ridge is a sequence of ridge pixels connecting two minutiae, stored as a SkeletonRidge.
// // traceRidges in C

// int compare_intpoints(const void* a, const void* b) {
//     const IntPoint* p1 = (const IntPoint*)a;
//     const IntPoint* p2 = (const IntPoint*)b;
//     if (p1->y != p2->y)
//         return p1->y - p2->y;
//     return p1->x - p2->x;
// }

// // minutiae_point map has center->SkeletonMinutia* mapping; but none of these SkeletonMinutia* have any ridges yet
// // These ridges will be put in this function
// void trace_ridges(BooleanMatrix* thinned, HashMap* minutiae_points) {
//     // leads: A map that keeps track of ridge-starting pixels, so we don't trace the same ridge twice.
//     HashMap* leads = create_hash_map();

//     IntPoint* sorted_keys = malloc(sizeof(IntPoint) * minutiae_points->size);
//     memcpy(sorted_keys, minutiae_points->keys, sizeof(IntPoint) * minutiae_points->size);
//     qsort(sorted_keys, minutiae_points->size, sizeof(IntPoint), compare_intpoints);

//     // Iterates over each key in the minutiaePoints map (which are positions of detected minutiae).
//     for (int i = 0; i < minutiae_points->size; ++i) {
//         // IntPoint minutia_point = minutiae_points->keys[i];
//         IntPoint minutia_point = sorted_keys[i];
//         printf("i: %d/%d, orig minutiaPoint: (%d, %d)\n", i, minutiae_points->size, minutia_point.x, minutia_point.y);
//         SkeletonMinutia* minutia = (SkeletonMinutia*)hash_map_get(minutiae_points, minutia_point);
//         for (int j = 0; j < 8; ++j) {
//             IntPoint start_relative = CORNER_NEIGHBORS[j];
//             IntPoint start = add_points(minutia_point, start_relative);
//             printf("j: %d/8, Processing start=(%d, %d)\n", j, start.x, start.y);
//             // printf("get_boolean_matrix_safe(thinned,start): %d, hash_map_get(minutiae_points, start): %d, hash_map_get(leads, start): %d\n",
//             //        get_boolean_matrix_safe(thinned, start.x, start.y),
//             //        hash_map_get(minutiae_points, start)==NULL,
//             //        hash_map_get(leads, start)==NULL);

//             if (get_boolean_matrix_safe(thinned, start.x, start.y) &&
//                 hash_map_get(minutiae_points, start) == NULL &&
//                 hash_map_get(leads, start) == NULL) {

//                 SkeletonRidge* ridge = create_ridge();
//                 // printf("minutia_point: (%d, %d), start: (%d, %d)\n", minutia_point.x, minutia_point.y, start.x, start.y);

//                 // If valis start is found for new ridge, Pushes minutiaPoint and start into the ridge.points list
                
//                 push_point_skeletonridge(ridge, minutia_point);
//                 push_point_skeletonridge(ridge, start);
//                 IntPoint previous = minutia_point;
//                 IntPoint current = start;
//                 IntPoint next;
//                 do {
//                     next = (IntPoint){0, 0};
//                     for (int k = 0; k < 8; ++k) {
//                         IntPoint next_relative = CORNER_NEIGHBORS[k];
//                         next = add_points(current, next_relative);
//                         if (get_boolean_matrix_safe(thinned, next.x, next.y) && !point_equals(next, previous))
//                             break;
//                     }
//                     previous = current;
//                     current = next;
//                     printf("current: (%d, %d)\n", current.x, current.y);
//                     push_point_skeletonridge(ridge, current);
//                 } while (hash_map_get(minutiae_points, current) == NULL);
//                 printf("end: (%d, %d)\n", current.x, current.y);
                
//                 reverse_ridge_points(ridge);

//                 #undef printf
//                 #define printf printf
//                 printf("ridge: ");
//                 SkeletonRidge* base = ridge;

//                 for(int p = 0; p < base->point_count; ++p) {
//                     printf("  (%d, %d)", base->points[p].x, base->points[p].y);
//                 }
//                 printf("\n");
                
//                 // printf("Setting start ridge for minutia: (%d, %d)\n", minutia->position.x, minutia->position.y);
//                 // printf("Setting end ridge for minutia: (%d, %d)\n", ((SkeletonMinutia*)hash_map_get(minutiae_points, current))->position.x, ((SkeletonMinutia*)hash_map_get(minutiae_points, current))->position.y);
//                 printf("ridge_point_at(ridge,1): (%d, %d)\n", ridge_point_at(ridge,1).x, ridge_point_at(ridge,1).y);
//                 printf("ridge_point_at(ridge->reversed,1): (%d, %d)\n", ridge_point_at(ridge->reversed,1).x, ridge_point_at(ridge->reversed,1).y);

//                 printf("minutia_point: (%d, %d), start: (%d, %d), end: (%d, %d)\n", minutia_point.x, minutia_point.y, start.x, start.y, current.x, current.y);
//                 printf("hash_map_get(minutiae_points, current): %p\n", hash_map_get(minutiae_points, current));
//                 printf("ridge->is_view: %d\n", ridge->is_view);

//                 // minutia set as startMinutia of ridge
//                 ridge_set_start(ridge, minutia);
//                 ridge_set_end(ridge, (SkeletonMinutia*)hash_map_get(minutiae_points, current));
//                 hash_map_put(leads, ridge_point_at(ridge,1), ridge);
//                 hash_map_put(leads, ridge_point_at(ridge->reversed,1), ridge);
//                 // // #define printf(...)
//             }
//         }
//     }

//     free(sorted_keys);
//     free(leads->keys);
//     free(leads->values);
//     free(leads);
//     leads = NULL;
// }

// void fix_linking_gaps(Skeleton* skeleton) {
//     printf("In fix_linking_gaps, skeleton->count: %d\n",skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i) {
//         printf("Adding to minutia %d at (%d, %d)\n", i, skeleton->minutiae[i]->position.x, skeleton->minutiae[i]->position.y);
//         SkeletonMinutia* minutia = skeleton->minutiae[i];
//         for (int j = 0; j < minutia->ridge_count; ++j) {
//             SkeletonRidge* ridge = minutia->ridges[j];
//             printf("Ridge number %d with %d points\n", j, ridge->point_count);

//             if (!point_equals(ridge_point_at(ridge,0), minutia->position)) {
//                 IntPointArray* filling = line_to(ridge_point_at(ridge,0), minutia->position);

//                 // Skip the first point to avoid duplication
//                 for (int k = 1; k < filling->size; ++k) {
//                     IntPoint point = filling->data[k];

//                     expand_size(ridge);

//                     // // Append to reversed.points
//                     // if (ridge->reversed->point_count == ridge->reversed->point_capacity) {
//                     //     // ridge->reversed->point_capacity *= 2;
//                     //     ridge->reversed->point_capacity = ridge->reversed->point_capacity * 3 / 2 + 1;

//                     //     ridge->reversed->points = realloc(
//                     //         ridge->reversed->points,
//                     //         ridge->reversed->point_capacity * sizeof(IntPoint));
//                     // }
//                     // ridge->reversed->points[ridge->reversed->point_count++] = point;

//                     // // Also prepend to ridge->points (since reversed is reverse of this)
//                     // if (ridge->point_count == ridge->point_capacity) {
//                     //     // ridge->point_capacity *= 2;
//                     //     ridge->point_capacity = ridge->point_capacity * 3 / 2 + 1;

//                     //     ridge->points = realloc(
//                     //         ridge->points,
//                     //         ridge->point_capacity * sizeof(IntPoint));
//                     // }

//                     if(ridge->is_view==0)
//                     {
//                         // Shift existing points to the right to insert at the beginning
//                         for (int m = ridge->point_count; m > 0; --m) {
//                             ridge->points[m] = ridge->points[m - 1];
//                         }
//                         ridge->points[0] = point;
//                         ridge->point_count++;
//                         printf("New ridge->points[0]: (%d, %d)\n", ridge->points[0].x, ridge->points[0].y);

//                         ridge->reversed->point_count = ridge->point_count;
//                         ridge->reversed->point_capacity = ridge->point_capacity;
//                     }
//                     else
//                     {
//                         SkeletonRidge* base = ridge->reversed;
//                         base->points[base->point_count++] = point;
//                         base->reversed->point_count = base->point_count;
//                         base->reversed->point_capacity = base->point_capacity;
//                     }
//                 }

//                 free(filling->data);
//                 free(filling);
//             }
//         }
//     }
// }

// void init_skeleton(Skeleton* skeleton, SkeletonType type, IntPoint size) {
//     skeleton->type = type;
//     skeleton->size = size;
//     skeleton->count = 0;
//     skeleton->capacity = 16;
//     skeleton->minutiae = malloc(sizeof(SkeletonMinutia*) * skeleton->capacity);
//     if (!skeleton->minutiae) {
//         fprintf(stderr, "Failed to allocate minutiae array\n");
//         exit(1);
//     }
// }


// static inline const SkeletonRidge* base_of_c(const SkeletonRidge* r) {
//     return (r && r->is_view) ? r->reversed : r;
// }
// static inline void ridge_sync_view(SkeletonRidge* base) {
//     if (base && base->reversed) base->reversed->point_count = base->point_count;
// }

// // Input is thinned image
// Skeleton* trace(BooleanMatrix* thinned, SkeletonType type) {
//     IntPoint size = {thinned->width, thinned->height};
//     Skeleton* skeleton = (Skeleton*)malloc(sizeof(Skeleton));
//     // Initialize empty skeleton
//     init_skeleton(skeleton, type, size);  // assumes you have an init function

//     // Detects pixel positions with:
//     // Only 1 neighbor (ending ridge)
//     // Or 3+ neighbors (bifurcation)
//     // Returns a dynamic array of IntPoint minutiae positions.
//     IntPointArray* minutiaPoints = find_minutiae(thinned);
//     printf("Minutiae found: %d\n", minutiaPoints->size);
//     // for(int i = 0; i < minutiaPoints->size; ++i) {
//     //     IntPoint p = minutiaPoints->data[i];
//     //     printf("Minutia at (%d, %d)\n", p.x, p.y);
//     // }

//     // Link adjacent minutiae into clusters
//     // Returns a HashMap<IntPoint, IntPointArray*> where each key maps to a group of linked minutiae (like Union-Find).
//     HashMap* linking = link_neighboring_minutiae(minutiaPoints);  // define this type
//     free_int_point_array(minutiaPoints);

//     #undef printf
//     #define printf printf
//     printf("Minutia clusters found: %d\n", linking->size);

//     for(int i=0;i<linking->size;i++)
//     {
//         IntPointArray* minutiae_points= hash_map_get(linking,linking->keys[i]);
//         printf("Key minutiaepos: (%d,%d)\n",linking->keys[i].x,linking->keys[i].y);
        
//         for(int j = 0; j < minutiae_points->size; ++j) {
//             IntPoint p = minutiae_points->data[j];
//             printf("(%d, %d) ", p.x, p.y);
//         }
//         printf("\n");
//     }   
//     // // #define printf(...)

//     //  Computes average position of each cluster.
//     // Creates a SkeletonMinutia at the center.
//     // Maps every original minutia pixel to the representative SkeletonMinutia.

//     // minutiae progressively added to skeleton
//     // minutiae also represented as values in hashmap with key as centerpos
//     HashMap* minutiaMap = build_minutia_centers(skeleton, linking);  // define this type too
//     free_minutia_link_map(linking);

//     #undef printf
//     #define printf printf
//     for(int i=0;i<minutiaMap->size;i++)
//     {
//         printf("Minutia center at: (%d, %d)\n",minutiaMap->keys[i].x,minutiaMap->keys[i].y);
//         SkeletonMinutia* m = (SkeletonMinutia*)hash_map_get(minutiaMap, minutiaMap->keys[i]);
//         printf("Minutia at (%d, %d) with %d ridges\n", m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j) {
//             SkeletonRidge* r = m->ridges[j];
//             printf("Ridge with %d points from start: (%d, %d), end: (%d, %d)\n",
//                 r->startMinutia->position.x, r->startMinutia->position.y,
//                 r->endMinutia->position.x, r->endMinutia->position.y);
//             for(int k = 0; k < r->point_count; ++k) {
//                 printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//             }
//             printf("\n");
//         }
//     }
//     // // #define printf(...)


//     // Walks along the thinned lines between minutiae.
//     // For each traced path, builds a SkeletonRidge and connects two SkeletonMinutia endpoints.
//     trace_ridges(thinned, minutiaMap);  // define this

//     #undef printf
//     #define printf printf
//     printf("minutiaMap after trace_ridges, size: %d\n",minutiaMap->size);
//     for(int i=0;i<minutiaMap->size;i++)
//     {
//         printf("After trace_ridges Minutia center at (%d, %d)\n",minutiaMap->keys[i].x,minutiaMap->keys[i].y);
//         SkeletonMinutia* m = (SkeletonMinutia*)hash_map_get(minutiaMap, minutiaMap->keys[i]);
//         printf("After trace_ridges Minutia at (%d, %d) with %d ridges\n", m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j) {
//             SkeletonRidge* r = m->ridges[j];
//             printf("After trace_ridges Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x,r->endMinutia->position.y);
//                 if(r->is_view==0) {
//                     for(int k = 0; k < r->point_count; ++k) {
//                         printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//                     }
//                 } else {
//                     SkeletonRidge* b = base_of(r);
//                     for(int k = 0; k < b->point_count; ++k) {
//                         printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                     }
//                 }
//                 printf("\n");
            
//             }
//     }
    
//     printf("-------------------- Before\n");
//     // // // #define printf(...)

//     //     // ---- place this immediately after trace_ridges(thinned, minutiaMap); ----
//     // for (int i = 0; i < minutiaMap->size; ++i) {
//     //     // printf("iii: %d\n",i);
//     //     SkeletonMinutia* m = (SkeletonMinutia*)hash_map_get(minutiaMap, minutiaMap->keys[i]);
//     //     if (!m) continue;

//     //     for (int j = 0; j < m->ridge_count; ++j) {
//     //         SkeletonRidge* r = m->ridges[j];
//     //         if (!r) continue;

//     //         if (r->is_view) {
//     //             #undef printf
//     //             #define printf printf
//     //             printf("r->startMinutia: (%d, %d), r->endMinutia: (%d, %d), m: (%d, %d)\n",
//     //                    r->startMinutia->position.x, r->startMinutia->position.y,
//     //                    r->endMinutia->position.x, r->endMinutia->position.y,
//     //                    m->position.x, m->position.y);
//     //             // // #define printf(...)

//     //             SkeletonRidge* new_ridge = create_ridge();

//     //             new_ridge->point_capacity = r->point_capacity;
//     //             new_ridge->point_count = r->point_count;
//     //             new_ridge->is_view = 0; // This is the real one
                
//     //             r->reversed = malloc(sizeof(SkeletonRidge));
//     //             r->reversed->point_capacity = 8;
//     //             r->reversed->point_count = 0;
//     //             // r->reversed->points = malloc(sizeof(IntPoint) * r->point_capacity); // will allocate after reversal
//     //             r->reversed->reversed = r;
//     //             r->reversed->is_view = 1; // This is the view

//     //             r->startMinutia = NULL;
//     //             r->endMinutia = NULL;
//     //             r->reversed->startMinutia = NULL;
//     //             r->reversed->endMinutia = NULL;

//     //             // We hold the *view* at this adjacency. Make the base match this orientation.
//     //             SkeletonRidge* b = base_of(r);

//     //             int n = b->point_count;

//     //             // 1) Reverse the base points physically so base order == view's logical order
//     //             for (int a = 0, z = n - 1; a < n; ++a, --z) {
//     //                 r->points[a]=b->points[z];
//     //             }

//     //             // // 2) Swap endpoints: start/end minutiae must follow the new orientation
//     //             // SkeletonMinutia* tmpM = b->startMinutia;
//     //             // b->startMinutia = b->endMinutia;
//     //             // b->endMinutia   = tmpM;

//     //             // Keep the reversed view in sync (count only; it's still a view)
//     //             // ridge_sync_view(b);

//     //             // 3) Store the base handle in the minutia's adjacency list (no views in lists)
//     //             m->ridges[j] = r;

//     //             #undef printf
//     //             #define printf printf
//     //             printf("New r->startMinutia: (%d, %d), r->endMinutia: (%d, %d), m: (%d, %d)\n",
//     //                    r->startMinutia->position.x, r->startMinutia->position.y,
//     //                    r->endMinutia->position.x, r->endMinutia->position.y,
//     //                    m->position.x, m->position.y);
//     //             for(int k = 0; k < r->point_count; ++k) {
//     //                 printf("(%d, %d) ", ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//     //             }
//     //             printf("\n");
//     //             // // #define printf(...)
//     //         }
//     //         else
//     //         {
//     //             #undef printf
//     //             #define printf printf
//     //             printf("Same: r->startMinutia: (%d, %d), r->endMinutia: (%d, %d), m: (%d, %d)\n",
//     //                    r->startMinutia->position.x, r->startMinutia->position.y,
//     //                    r->endMinutia->position.x, r->endMinutia->position.y,
//     //                    m->position.x, m->position.y);
//     //             for(int k = 0; k < r->point_count; ++k) {
//     //                 printf("(%d, %d) ", ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//     //             }
//     //             printf("\n");
//     //             // // #define printf(...)
//     //         }

//     //         #undef printf
//     //         #define printf printf
//     //         printf("m->ridges[%d]: (%d, %d) to (%d, %d), point_count: %d\n",
//     //                j,m->ridges[j]->startMinutia->position.x, m->ridges[j]->startMinutia->position.y,
//     //                m->ridges[j]->endMinutia->position.x, m->ridges[j]->endMinutia->position.y,
//     //                m->ridges[j]->point_count);
//     //         for(int k = 0; k < m->ridges[j]->point_count; ++k) {
//     //             printf("(%d, %d) ", m->ridges[j]->points[k].x, m->ridges[j]->points[k].y);
//     //         }
//     //         printf("\n");
//     //         // // #define printf(...)

//     //     }
//     // }

//     // #undef printf
//     // #define printf printf
//     // for(int i=0;i<minutiaMap->size;i++)
//     // {
//     //     printf("After trace_ridges Minutia center at (%d, %d)\n",minutiaMap->keys[i].x,minutiaMap->keys[i].y);
//     //     SkeletonMinutia* m = (SkeletonMinutia*)hash_map_get(minutiaMap, minutiaMap->keys[i]);
//     //     printf("After trace_ridges Minutia at (%d, %d) with %d ridges\n", m->position.x, m->position.y, m->ridge_count);
//     //     for (int j = 0; j < m->ridge_count; ++j) {
//     //         SkeletonRidge* r = m->ridges[j];
//     //         // SkeletonRidge* r = base_of_c(r2);

//     //         printf("After trace_ridges Ridge with %d points from (%d, %d) to (%d, %d)\n",
//     //               r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//     //                r->endMinutia->position.x, r->endMinutia->position.y);
//     //         for(int k = 0; k < r->point_count; ++k) {
//     //             printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//     //         }
//     //         printf("\n");
//     //     }
//     // }
//     // printf("-------------------- After\n");
//     // // // #define printf(...)

//     #undef printf
//     #define printf printf
//     printf("\nSkeleton before fix_linking_gaps\n");
//     printf("Ridges created with %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//                 if(r->is_view==0) {
//                     for(int k = 0; k < r->point_count; ++k) {
//                         printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//                     }
//                 } else {
//                     SkeletonRidge* b = base_of(r);
//                     for(int k = 0; k < b->point_count; ++k) {
//                         printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                     }
//                 }
//             printf("\n");
//         }
//     }
//     // // #define printf(...)

//     fix_linking_gaps(skeleton);

//     #undef printf
//     #define printf printf
//     printf("Skeleton after fix_linking_gaps:\n");
//     printf("Ridges created: %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//                 if(r->is_view==0) {
//                     for(int k = 0; k < r->point_count; ++k) {
//                         printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//                     }
//                 } else {
//                     SkeletonRidge* b = base_of(r);
//                     for(int k = 0; k < b->point_count; ++k) {
//                         printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                     }
//                 }
//             printf("\n");
//         }
//     }
//     // // #define printf(...)

//     free_minutia_map(minutiaMap);

//     return skeleton;
// }


// //////////////////////////


// ///// BinaryThinning
// typedef enum {
//     SKELETON,
//     ENDING,
//     REMOVABLE
// } NeighborhoodType;


// // // Function to add two IntPoint values
// // IntPoint add_points(IntPoint a, IntPoint b) {
// // 	IntPoint result;
// // 	result.x = a.x + b.x;
// // 	result.y = a.y + b.y;
// // 	return result;
// // }

// NeighborhoodType* compute_neighborhood_types() {
//     NeighborhoodType* types = malloc(256 * sizeof(NeighborhoodType));
//     for (int mask = 0; mask < 256; ++mask) {
//         bool TL = (mask & 1) != 0;
//         bool TC = (mask & 2) != 0;
//         bool TR = (mask & 4) != 0;
//         bool CL = (mask & 8) != 0;
//         bool CR = (mask & 16) != 0;
//         bool BL = (mask & 32) != 0;
//         bool BC = (mask & 64) != 0;
//         bool BR = (mask & 128) != 0;

//         int count = __builtin_popcount(mask);

//         bool diagonal = (!TC && !CL && TL) || (!CL && !BC && BL) || (!BC && !CR && BR) || (!CR && !TC && TR);
//         bool horizontal = (!TC && !BC && (TR || CR || BR) && (TL || CL || BL));
//         bool vertical = (!CL && !CR && (TL || TC || TR) && (BL || BC || BR));
//         bool end = (count == 1);

//         if (end)
//             types[mask] = ENDING;
//         else if (!diagonal && !horizontal && !vertical)
//             types[mask] = REMOVABLE;
//         else
//             types[mask] = SKELETON;
//     }
//     return types;
// }

// bool is_false_ending(BooleanMatrix* binary, IntPoint ending) {
//     for (int i = 0; i < 8; ++i) {
//         IntPoint rel = CORNER_NEIGHBORS[i];
//         IntPoint neighbor = add_points(ending, rel);
//         if (get_boolean_matrix(binary, neighbor.x, neighbor.y)) {
//             int count = 0;
//             for (int j = 0; j < 8; ++j) {
//                 IntPoint rel2 = CORNER_NEIGHBORS[j];
//                 IntPoint n2 = add_points(neighbor, rel2);
//                 if (get_boolean_matrix_safe(binary, n2.x, n2.y))
//                     ++count;
//             }
//             return count > 2;
//         }
//     }
//     return false;
// }


// BooleanMatrix thin(BooleanMatrix* input, SkeletonType type) {
//     NeighborhoodType* types = compute_neighborhood_types();
//     IntPoint size = {input->width, input->height};
//     BooleanMatrix partial = create_boolean_matrix(size.x, size.y);
//     BooleanMatrix thinned = create_boolean_matrix(size.x, size.y);

//     for (int y = 1; y < size.y - 1; ++y)
//         for (int x = 1; x < size.x - 1; ++x)
//             set_boolean_matrix(&partial, x, y, get_boolean_matrix(input, x, y));

//     bool removed = true;
//     for (int i = 0; i < THINNING_ITERATIONS && removed; ++i) {
//         removed = false;
//         for (int evenY = 0; evenY < 2; ++evenY) {
//             for (int evenX = 0; evenX < 2; ++evenX) {
//                 for (int y = 1 + evenY; y < size.y - 1; y += 2) {
//                     for (int x = 1 + evenX; x < size.x - 1; x += 2) {
//                         if (get_boolean_matrix(&partial, x, y) &&
//                             !get_boolean_matrix(&thinned, x, y) &&
//                             !(get_boolean_matrix(&partial, x, y - 1) &&
//                               get_boolean_matrix(&partial, x, y + 1) &&
//                               get_boolean_matrix(&partial, x - 1, y) &&
//                               get_boolean_matrix(&partial, x + 1, y))) {
                            
//                             int neighbors =
//                                 (get_boolean_matrix(&partial, x + 1, y + 1) ? 128 : 0) |
//                                 (get_boolean_matrix(&partial, x, y + 1) ? 64 : 0) |
//                                 (get_boolean_matrix(&partial, x - 1, y + 1) ? 32 : 0) |
//                                 (get_boolean_matrix(&partial, x + 1, y) ? 16 : 0) |
//                                 (get_boolean_matrix(&partial, x - 1, y) ? 8 : 0) |
//                                 (get_boolean_matrix(&partial, x + 1, y - 1) ? 4 : 0) |
//                                 (get_boolean_matrix(&partial, x, y - 1) ? 2 : 0) |
//                                 (get_boolean_matrix(&partial, x - 1, y - 1) ? 1 : 0);

//                             if (types[neighbors] == REMOVABLE ||
//                                 (types[neighbors] == ENDING && is_false_ending(&partial, (IntPoint){x, y}))) {
//                                 removed = true;
//                                 set_boolean_matrix(&partial, x, y, false);
//                             } else {
//                                 set_boolean_matrix(&thinned, x, y, true);
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     // TransparencySink_log_matrix(type.prefix + "thinned-skeleton", &thinned);
//     free(types);
//     free(partial.cells);

//     return thinned;
// }

// /////////////// Filter Apply /////////////

// void minutia_detach_end(SkeletonMinutia* minutia, SkeletonRidge* ridge) {
//     // Find the ridge in the minutia's list of ridges and remove it
//     for (int i = 0; i < minutia->ridge_count; ++i) {
//         if (minutia->ridges[i] == ridge) {
//             // Shift remaining ridges left
//             for (int j = i; j < minutia->ridge_count - 1; ++j) {
//                 minutia->ridges[j] = minutia->ridges[j + 1];
//             }
//             minutia->ridge_count--;
//             break;
//         }
//     }

//     // Clear the endMinutia pointer in the ridge
//     if (ridge->endMinutia == minutia) {
//         ridge->endMinutia = NULL;
//     }

//     // Also clear reversed ridge's startMinutia if it's pointing to this
//     if (ridge->reversed && ridge->reversed->startMinutia == minutia) {
//         ridge->reversed->startMinutia = NULL;
//     }
// }


// void apply_skeleton_dot_filter(Skeleton* skeleton) {
//     int new_count = 0;
//     for (int i = 0; i < skeleton->count; ++i) {
//         SkeletonMinutia* minutia = skeleton->minutiae[i];
//         if (minutia->ridge_count > 0) {
//             // Keep this minutia
//             skeleton->minutiae[new_count++] = minutia;
//         } else {
//             // Free the minutia since it's unused
//             free(minutia->ridges); // if ridges was malloc'd
//             free(minutia);
//         }
//     }
//     skeleton->count = new_count;
// }

// void apply_skeleton_knot_filter(Skeleton* skeleton) {
//     for (int i = 0; i < skeleton->count; ++i) {
//         SkeletonMinutia* minutia = skeleton->minutiae[i];

//         if (minutia->ridge_count == 2 && minutia->ridges[0]->reversed != minutia->ridges[1]) {
//             printf("Minutia at (%d, %d) with %d ridges\n", minutia->position.x, minutia->position.y, minutia->ridge_count);
//             for(int j = 0; j < minutia->ridge_count; ++j) {
//                 SkeletonRidge* ridge = minutia->ridges[j];
//                 printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    ridge->point_count, ridge->startMinutia->position.x, ridge->startMinutia->position.y,
//                    ridge->endMinutia->position.x, ridge->endMinutia->position.y);
//                 if(ridge->is_view==0) {
//                     for(int k = 0; k < ridge->point_count; ++k) {
//                         printf("(%d, %d) ",ridge->points[k].x, ridge->points[k].y);
//                     }
//                 } else {
//                     SkeletonRidge* b = base_of(ridge);
//                     for(int k = 0; k < b->point_count; ++k) {
//                         printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                     }
//                 }
//             printf("\n");
//             }

//             SkeletonRidge* extended = minutia->ridges[0]->reversed;
//             SkeletonRidge* removed = minutia->ridges[1];
//             printf("extended ridge: \n");
//             for (int j = 0; j < extended->point_count; ++j)
//                 printf("(%d, %d) ", ridge_point_at(extended,j).x, ridge_point_at(extended,j).y);
//             printf("\nremoved ridge: \n");
//             for (int j = 0; j < removed->point_count; ++j)
//                 printf("(%d, %d) ", ridge_point_at(removed,j).x, ridge_point_at(removed,j).y);
//             printf("\n");

//             // Prefer longer ridge as extended
//             if (extended->point_count < removed->point_count) {
//                 SkeletonRidge* tmp = extended;
//                 extended = removed;
//                 removed = tmp;
//                 extended = extended->reversed;
//                 removed = removed->reversed;
//             }

//             // Remove the last point from extended ridge
//             if (extended->point_count > 0)
//             {
//                 if(extended->is_view==0)
//                 {
//                     extended->point_count--;

//                     extended->reversed->point_count--;

//                     // for (int k = 0; k < extended->reversed->point_count; k++)
//                     //     extended->reversed->points[k] = extended->reversed->points[k + 1];
//                 }
//                 else
//                 {
//                     SkeletonRidge* base = extended->reversed;
//                     base->point_count--;

//                     extended->point_count--;

//                     for (int k = 0; k < base->point_count; k++)
//                         base->points[k] = base->points[k + 1];
//                 }

//                 extended->reversed->point_capacity = extended->point_capacity;
//                 extended->reversed->point_count = extended->point_count;
               
//             }

//             // Append all points of removed ridge to extended
//             for (int j = 0; j < removed->point_count; ++j) {
//                 // // Ensure capacity in extended
//                 // if (extended->point_count == extended->point_capacity) {
//                 //     // extended->point_capacity *= 2;
//                 //     extended->point_capacity = extended->point_capacity * 3 / 2 + 1;
//                 //     extended->points = realloc(extended->points, extended->point_capacity * sizeof(IntPoint));
//                 // }
//                 expand_size(extended);
//                 if(extended->is_view==0)
//                     extended->points[extended->point_count++] = base_of(removed)->points[j];
//                 else
//                 {
//                     SkeletonRidge* base = extended->reversed;
//                     for(int k = base->point_count; k > 0; --k)
//                         base->points[k] = base->points[k - 1];
//                     base->points[0] = base_of(removed)->points[j];
//                     base->point_count++;
//                 }
//                 // extended->points[extended->point_count++] = removed->points[j];
//                 extended->reversed->point_count = extended->point_count;
//                 extended->reversed->point_capacity = extended->point_capacity;
//             }

//             // // Also update reversed ridge (prepend in reverse order)
//             // if (extended->reversed) {
//             //     SkeletonRidge* rev = extended->reversed;
//             //     printf("Original extended reversed ridge: \n");
//             //     for (int j = 0; j < rev->point_count; ++j)
//             //         printf("(%d, %d) ", rev->points[j].x, rev->points[j].y);
//             //     printf("\n");

//             //     for (int j = removed->point_count - 1; j >= 0; --j) {
//             //         // Ensure capacity
//             //         if (rev->point_count == rev->point_capacity) {
//             //             // rev->point_capacity *= 2;
//             //             rev->point_capacity = rev->point_capacity * 3 / 2 + 1;
//             //             rev->points = realloc(rev->points, rev->point_capacity * sizeof(IntPoint));
//             //         }
//             //         // Shift existing points to the right to prepend
//             //         for (int k = rev->point_count; k > 0; --k)
//             //             rev->points[k] = rev->points[k - 1];

//             //         // Prepend current point
//             //         rev->points[0] = removed->points[(removed->point_count - 1)-j];
//             //         rev->point_count++;

//             //         printf("temp extended reversed ridge: \n");
//             //         for (int j = 0; j < rev->point_count; ++j)
//             //             printf("(%d, %d) ", rev->points[j].x, rev->points[j].y);
//             //         printf("\n");
//             //     }
//             // }

//             // printf("new extended of size %d: \n",extended->point_count);
//             // for (int j = 0; j < extended->point_count; ++j)
//             //     printf("(%d, %d) ", extended->points[j].x, extended->points[j].y);
//             // printf("\n");
//             // printf("new extended reversed of size:%d \n",extended->reversed->point_count);
//             // for (int j = 0; j < extended->reversed->point_count; ++j)
//             //     printf("(%d, %d) ", extended->reversed->points[j].x, extended->reversed->points[j].y);
//             // printf("\n");

//             // printf("new removed pf size:%d \n",removed->point_count);
//             // for (int j = 0; j < removed->point_count; ++j)  
//             //     printf("(%d, %d) ", removed->points[j].x, removed->points[j].y);
//             // printf("\n");

//             // printf("Setting new extended ridge as end for removed->endMinutia: (%d, %d)\n",
//             //        removed->endMinutia->position.x, removed->endMinutia->position.y);
            
//             // printf("Before removed->endMinutia: (%d, %d)\n",
//             //        removed->endMinutia->position.x, removed->endMinutia->position.y);
//             // for(int j = 0; j < removed->endMinutia->ridge_count; ++j) {
//             //     SkeletonRidge* r = removed->endMinutia->ridges[j];
//             //     printf("Ridge %d with %d points from (%d, %d) to (%d, %d)\n",
//             //         j, r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//             //         r->endMinutia->position.x, r->endMinutia->position.y);
//             //     for (int k = 0; k < r->point_count; ++k) {
//             //         printf("(%d, %d) ", ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//             //     }
//             //     printf("\n");
//             // }
//                 // Set new end for extended ridge
//             ridge_set_end(extended, removed->endMinutia);

//             // // printf("After removed->endMinutia: (%d, %d)\n",
//             // //        removed->endMinutia->position.x, removed->endMinutia->position.y);
//             // for(int j = 0; j < removed->endMinutia->ridge_count; ++j) {
//             //     SkeletonRidge* r = removed->endMinutia->ridges[j];
//             //     // if(r->startMinutia && r->endMinutia)
//             //         printf("Ridge %d with %d points from (%d, %d) to (%d, %d)\n",
//             //            j, r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//             //            r->endMinutia->position.x, r->endMinutia->position.y);
//             //     for (int k = 0; k < r->point_count; ++k) {
//             //         printf("(%d, %d) ", ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//             //     }
//             //     printf("\n");
//             // }

//             // printf("Detaching removed ridge from current minutia\n");
//             // Detach removed ridge from minutiae
//             ridge_detach(removed);  // Implement this to detach from both start and end minutiae
//         }
//     }

//     apply_skeleton_dot_filter(skeleton); // Also convert and call SkeletonDotFilter
// }

// void apply_skeleton_pore_filter(Skeleton* skeleton) {
//     for (int i = 0; i < skeleton->count; ++i) {
//         SkeletonMinutia* minutia = skeleton->minutiae[i];

//         if (minutia->ridge_count == 3) {
//             for (int exit = 0; exit < 3; ++exit) {
//                 SkeletonRidge* exit_ridge = minutia->ridges[exit];
//                 SkeletonRidge* arm1 = minutia->ridges[(exit + 1) % 3];
//                 SkeletonRidge* arm2 = minutia->ridges[(exit + 2) % 3];

//                 SkeletonMinutia* common_end = arm1->endMinutia;
//                 if (common_end == arm2->endMinutia &&
//                     exit_ridge->endMinutia != common_end &&
//                     common_end != minutia &&
//                     exit_ridge->endMinutia != minutia) {

//                     if (common_end->ridge_count == 3 &&
//                         arm1->point_count <= MAX_PORE_ARM &&
//                         arm2->point_count <= MAX_PORE_ARM) {
//                         printf("exit: %d; ",exit);
//                         printf("exit_ridge->startMinutia: (%d, %d), exit_ridge->endMinutia: (%d, %d)\n",exit_ridge->startMinutia->position.x, exit_ridge->startMinutia->position.y,exit_ridge->endMinutia->position.x, exit_ridge->endMinutia->position.y);
//                         printf("arm1->startMinutia: (%d, %d), arm1->endMinutia: (%d, %d)\n",arm1->startMinutia->position.x, arm1->startMinutia->position.y,arm1->endMinutia->position.x, arm1->endMinutia->position.y);
//                         printf("arm2->startMinutia: (%d, %d), arm2->endMinutia: (%d, %d)\n",arm2->startMinutia->position.x, arm2->startMinutia->position.y,arm2->endMinutia->position.x, arm2->endMinutia->position.y);
    
//                         // minutia_detach_end(arm1->endMinutia, arm1);
//                         // minutia_detach_end(arm2->endMinutia, arm2);
//                         // minutia_detach_start(minutia, arm1);
//                         // minutia_detach_start(minutia, arm2);
//                         ridge_detach(arm1); ridge_detach(arm2);

//                         SkeletonRidge* merged = create_ridge();
//                         ridge_set_start(merged, minutia);
//                         ridge_set_end(merged, common_end);

//                         IntPointArray* path = line_to(minutia->position, common_end->position);
//                         for (int j = 0; j < path->size; ++j)
//                             push_point_skeletonridge(merged, path->data[j]);

//                         free(path->data);
//                         free(path);
//                     }
//                     break;
//                 }
//             }
//         }
//     }
//     printf("Before pore filter's knot filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             // if(r->startMinutia && r->endMinutia)
//                 printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//             for (int k = 0; k < r->point_count; ++k)
//             {
//                 printf("(%d, %d) ", ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//             }
//             printf("\n");
//         }
//     }

//     apply_skeleton_knot_filter(skeleton); // You must implement this too.
//     // Optionally add: log_skeleton("removed-pores", skeleton);

//     // #undef printf
//     // #define printf printf
//     // printf("After pore filter's knot filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     // for (int i = 0; i < skeleton->count; ++i)
//     // {
//     //     SkeletonMinutia* m = skeleton->minutiae[i];
//     //     printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//     //     for (int j = 0; j < m->ridge_count; ++j)
//     //     {
//     //         SkeletonRidge* r = m->ridges[j];
//     //         printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//     //                r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//     //                r->endMinutia->position.x, r->endMinutia->position.y);
//     //         for (int k = 0; k < r->point_count; ++k)
//     //         {
//     //             printf("(%d, %d) ", ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//     //         }
//     //         printf("\n");
//     //     }
//     // }
//     // // // #define printf(...)
// }

// //////////////// GAP FILTER ///////

// // Utility: Subtract two IntPoints
// IntPoint subtract_points(IntPoint a, IntPoint b) {
//     IntPoint result;
//     result.x = a.x - b.x;
//     result.y = a.y - b.y;
//     return result;
// }

// // Helper: square of integer
// int square(int value) {
//     return value * value;
// }



// // atan2 wrapper
// float double_angle_atan(IntPoint a, IntPoint b) {
//     float angle= atan2((float)(b.y - a.y), (float)(b.x - a.x));
//     return (angle >=0) ? angle : angle+PI2;
// }

// // Angle difference in radians, always positive, <= PI
// float double_angle_distance(float a1, float a2) {
//     float diff = fabs(a1 - a2);
//     return diff > M_PI ? 2 * M_PI - diff : diff;
// }

// // Return angle opposite to given angle
// float double_angle_opposite(float angle) {
//     angle += M_PI;
//     if (angle > 2 * M_PI)
//         angle -= 2 * M_PI;
//     return angle;
// }

// BooleanMatrix* skeleton_shadow(Skeleton* skeleton, IntPoint size) {
//     BooleanMatrix* shadow= create_boolean_matrix_pointer(size.x, size.y);

//     for (int i = 0; i < skeleton->count; ++i) {
//         SkeletonMinutia* minutia = skeleton->minutiae[i];
//         boolean_matrix_set(shadow, minutia->position.x, minutia->position.y, true);

//         for (int j = 0; j < minutia->ridge_count; ++j) {
//             SkeletonRidge* ridge = minutia->ridges[j];

//             if (ridge->startMinutia->position.y <= ridge->startMinutia->position.y) {
//                 for (int k = 0; k < ridge->point_count; ++k) {
//                     // IntPoint p = ridge->points[k];
//                     IntPoint p = ridge_point_at(ridge, k);
//                     boolean_matrix_set(shadow, p.x, p.y, true);
//                 }
//             }
//         }
//     }

//     return shadow;
// }



// typedef struct {
//     int distance;
//     SkeletonMinutia* end1;
//     SkeletonMinutia* end2;
// } SkeletonGap;

// // Helper to compare gaps (priority queue: smallest distance first)
// int compare_gaps(const void* a, const void* b) {
//     return ((SkeletonGap*)a)->distance - ((SkeletonGap*)b)->distance;
// }

// static void add_gap_ridge(BooleanMatrix* shadow, SkeletonGap* gap, IntPointArray* line) {
//     printf("Adding ridge for gap between (%d, %d) and (%d, %d)\n",
//            gap->end1->position.x, gap->end1->position.y,
//            gap->end2->position.x, gap->end2->position.y);
    
//     SkeletonRidge* ridge = create_ridge();
//     for (int i = 0; i < line->size; ++i)
//         push_point_skeletonridge(ridge, line->data[i]);

//     printf("Adding ridge: in add_gap_ridge\n");
//     for(int i = 0; i < ridge->point_count; ++i) {
//         printf("(%d, %d) ",ridge_point_at(ridge, i).x, ridge_point_at(ridge, i).y);
//         // printf("(%d, %d) ", ridge->points[i].x, ridge->points[i].y);
//     }
//     printf("\n");

//     printf("gap.end2 before: \n");
//     for(int i = 0; i < gap->end2->ridge_count; ++i) {
//         printf("Ridge number %d with %d points: ", i, gap->end2->ridges[i]->point_count);
//         for(int j = 0; j < gap->end2->ridges[i]->point_count; ++j) {
//             printf("(%d, %d) ", ridge_point_at(gap->end2->ridges[i], j).x, ridge_point_at(gap->end2->ridges[i], j).y);
//         }
//         printf("\n");
//     }

//     ridge_set_start(ridge, gap->end1);
//     ridge_set_end(ridge, gap->end2);

//     printf("gap.end2 after: \n");
//     for(int i = 0; i < gap->end2->ridge_count; ++i) {
//         printf("Ridge number %d with %d points: ", i, gap->end2->ridges[i]->point_count);
//         for(int j = 0; j < gap->end2->ridges[i]->point_count; ++j) {
//             printf("(%d, %d) ", ridge_point_at(gap->end2->ridges[i], j).x, ridge_point_at(gap->end2->ridges[i], j).y);
//         }
//         printf("\n");
//     }
//     for (int i = 0; i < line->size; ++i)
//         set_boolean_matrix(shadow, line->data[i].x, line->data[i].y, true);
// }



// static bool is_ridge_overlapping(IntPointArray* line, BooleanMatrix* shadow) {
//     for (int i = TOLERATED_GAP_OVERLAP; i < line->size - TOLERATED_GAP_OVERLAP; ++i)
//         if (get_boolean_matrix_safe(shadow, line->data[i].x, line->data[i].y))
//             return true;
//     return false;
// }

// static IntPoint angle_sample_for_gap_removal(SkeletonMinutia* minutia) {
//     SkeletonRidge* ridge = minutia->ridges[0];
//     if (GAP_ANGLE_OFFSET < ridge->point_count)
//         return ridge_point_at(ridge, GAP_ANGLE_OFFSET);
//         // return ridge->points[GAP_ANGLE_OFFSET];
//     else
//         return ridge->endMinutia->position;
// }

// static bool is_within_gap_limits(SkeletonMinutia* end1, SkeletonMinutia* end2) {
//     IntPoint delta = subtract_points(end1->position, end2->position);
//     int distanceSq = delta.x * delta.x + delta.y * delta.y;
//     // printf("Distance squared: %d\n", distanceSq);

//     if (distanceSq <= square(MAX_RUPTURE_SIZE))
//         return true;
//     if (distanceSq > square(MAX_GAP_SIZE))
//         return false;

//     float gapDirection = double_angle_atan(end1->position, end2->position);
//     // printf("end1->position: (%d, %d), end2->position: (%d, %d)\n",
//     //        end1->position.x, end1->position.y,
//     //        end2->position.x, end2->position.y);
//     // printf("anglesample_for_gap_removal(end1): (%d, %d)\n",
//     //        angle_sample_for_gap_removal(end1).x, angle_sample_for_gap_removal(end1).y);
//     float direction1 = double_angle_atan(end1->position, angle_sample_for_gap_removal(end1));
//     // printf("gapDirection: %f, direction1: %f\n", gapDirection, direction1);
//     // printf("double_angle_distance(direction1, double_angle_opposite(gapDirection)): %f\n",double_angle_distance(direction1, double_angle_opposite(gapDirection)));   
    
//     if (double_angle_distance(direction1, double_angle_opposite(gapDirection)) > MAX_GAP_ANGLE)
//         return false;

//     float direction2 = double_angle_atan(end2->position, angle_sample_for_gap_removal(end2));
//     // printf("direction2: %f\n", direction2);
//     // printf("double_angle_distance(direction2, gapDirection): %f\n",double_angle_distance(direction2, gapDirection));
//     if (double_angle_distance(direction2, gapDirection) > MAX_GAP_ANGLE)
//         return false;

//     return true;
// }

// void apply_skeleton_gap_filter(Skeleton* skeleton) {
//     SkeletonGap queue[1000];
//     int queue_size = 0;

//     for (int i = 0; i < skeleton->count; ++i) {
//         SkeletonMinutia* end1 = skeleton->minutiae[i];
//         if (end1->ridge_count == 1 && end1->ridges[0]->point_count >= SHORTEST_JOINED_ENDING) {
//             for (int j = 0; j < skeleton->count; ++j) {
//                 SkeletonMinutia* end2 = skeleton->minutiae[j];
//                 // printf("Checking gap between (%d, %d) and (%d, %d)\n",
//                 //        end1->position.x, end1->position.y,
//                 //        end2->position.x, end2->position.y);
//                 // printf("end1==end2: %d \n", end1 == end2);
//                 // printf("end2->ridge_count: %d \n", end2->ridge_count);
//                 // printf("end1->ridges[0]->endMinutia!= end2: %d \n", end1->ridges[0]->endMinutia != end2);
//                 // printf("end2->ridges[0]->point_count: %d \n",
//                 //        end2->ridges[0]->point_count);
//                 // printf("SHORTEST_JOINED_ENDING: %d \n", SHORTEST_JOINED_ENDING);
//                 // printf("is_within_gap_limits: %d \n", is_within_gap_limits(end1, end2));

//                 if (end1!=end2 &&
//                     end2->ridge_count == 1 &&
//                     end1->ridges[0]->endMinutia != end2 &&
//                     end2->ridges[0]->point_count >= SHORTEST_JOINED_ENDING &&
//                     is_within_gap_limits(end1, end2)) {

//                     SkeletonGap gap;
//                     IntPoint diff = subtract_points(end1->position, end2->position);
//                     gap.distance = diff.x * diff.x + diff.y * diff.y;
//                     gap.end1 = end1;
//                     gap.end2 = end2;

//                     queue[queue_size++] = gap;
//                 }
//             }
//         }
//     }

//     printf("Gap filter: Found %d gaps\n", queue_size);
//     for(int i=0;i<queue_size;i++)
//     {
//         SkeletonGap* gap = &queue[i];
//         printf("Gap %d: (%d, %d) to (%d, %d) with distance %d\n",
//                i, gap->end1->position.x, gap->end1->position.y,
//                gap->end2->position.x, gap->end2->position.y,
//                gap->distance);
//     }

//     qsort(queue, queue_size, sizeof(SkeletonGap), compare_gaps);

//     BooleanMatrix* shadow = skeleton_shadow(skeleton, skeleton->size);  // You must define this helper

//     for (int i = 0; i < queue_size; ++i) {
//         SkeletonGap* gap = &queue[i];
//         if (gap->end1->ridge_count == 1 && gap->end2->ridge_count == 1) {
//             IntPointArray* line = line_to(gap->end1->position, gap->end2->position);
//             if (!is_ridge_overlapping(line, shadow))
//                 add_gap_ridge(shadow, gap, line);
//             free(line->data);
//             free(line);
//         }
//     }

//     printf("Before gap filter's knot filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             // if(r->startMinutia && r->endMinutia)
//                 printf(" Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//             for (int k = 0; k < r->point_count; ++k)
//             {
//                 printf("(%d, %d) ", ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//             }
//             printf("\n");
//         }
//     }

//     apply_skeleton_knot_filter(skeleton);  // Implemented earlier
//     // TransparencySink logging omitted in C version


//     printf("After gap filter's knot filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     printf("After gap filter's knot filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             // if(r->startMinutia && r->endMinutia)
//                 printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//             for (int k = 0; k < r->point_count; ++k)
//             {
//                 printf("(%d, %d) ", ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//             }
//             printf("\n");
//         }
//     }

// }

// /// TailFIlter //////////////

// void apply_skeleton_tail_filter(Skeleton* skeleton) {
//     for (int i = 0; i < skeleton->count; ++i) {
//         SkeletonMinutia* minutia = skeleton->minutiae[i];
//         if (minutia->ridge_count == 1) {
//             SkeletonRidge* ridge = minutia->ridges[0];
//             SkeletonMinutia* end = ridge->endMinutia;
//             if (end != NULL && end->ridge_count >= 3) {
//                 if (ridge->point_count < MIN_TAIL_LENGTH) {
//                     ridge_detach(ridge);
//                 }
//             }
//         }
//     }

//     apply_skeleton_dot_filter(skeleton);
//     apply_skeleton_knot_filter(skeleton);

//     // TransparencySink.current().logSkeleton("removed-tails", skeleton);
//     // Logging or debugging output can be added here if needed.
// }

// void apply_skeleton_fragment_filter(Skeleton* skeleton) {
//     for (int i = 0; i < skeleton->count; ++i) {
//         SkeletonMinutia* minutia = skeleton->minutiae[i];

//         if (minutia->ridge_count == 1) {
//             SkeletonRidge* ridge = minutia->ridges[0];
//             SkeletonMinutia* end = ridge->endMinutia;

//             printf("Checking minutia at (%d, %d) with end->ridge_count %d and ridge->point_count %d\n",
//                    minutia->position.x, minutia->position.y, end ? end->ridge_count : 0, ridge->point_count);

//             if (end != NULL && end->ridge_count == 1 && ridge->point_count < MIN_FRAGMENT_LENGTH) {
//                 printf("Detaching fragment ridge from minutia at (%d, %d) with end at (%d, %d) and  ridge->count %d\n",
//                        minutia->position.x, minutia->position.y,
//                        end->position.x, end->position.y, ridge->point_count);
//                 ridge_detach(ridge);
//             }
//         }
//     }

//     printf("Before fragment filter's dot filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             // if(r->startMinutia && r->endMinutia)
//                 printf(" Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//             for (int k = 0; k < r->point_count; ++k)
//             {
//                 printf("(%d, %d) ", ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//             }
//             printf("\n");
//         }
//     }

//     apply_skeleton_dot_filter(skeleton);

//     printf("After fragment filter's dot filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             // if(r->startMinutia && r->endMinutia)
//                 printf(" Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//             for (int k = 0; k < r->point_count; ++k)
//             {
//                 printf("(%d, %d) ", ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//             }
//             printf("\n");
//         }
//     }

//     // Transparency logging equivalent, if needed:
//     // log_skeleton("removed-fragments", skeleton);
// }

// void apply_skeleton_filters(Skeleton* skeleton) {
//     #undef printf
//         #define printf printf
//     apply_skeleton_dot_filter(skeleton);
//     // log_skeleton("removed-dots", skeleton); // Optional: implement if you need logging like Java
//     printf("After dot filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             // if(r->startMinutia && r->endMinutia)
//                 printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//                 if(r->is_view==0) {
//                     for(int k = 0; k < r->point_count; ++k) {
//                         printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//                     }
//                 } else {
//                     SkeletonRidge* b = base_of(r);
//                     for(int k = 0; k < b->point_count; ++k) {
//                         printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                     }
//                 }
//                 printf("\n");
//         }
//     }


//     apply_skeleton_pore_filter(skeleton);
//     printf("After pore filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             // if(r->startMinutia && r->endMinutia)
//                 printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//                 if(r->is_view==0) {
//                     for(int k = 0; k < r->point_count; ++k) {
//                         printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//                     }
//                 } else {
//                     SkeletonRidge* b = base_of(r);
//                     for(int k = 0; k < b->point_count; ++k) {
//                         printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                     }
//                 }
//                 printf("\n");
//         }
//     }

//     apply_skeleton_gap_filter(skeleton);
//     printf("After gap filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             // if(r->startMinutia && r->endMinutia)
//                 printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//                 if(r->is_view==0) {
//                     for(int k = 0; k < r->point_count; ++k) {
//                         printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//                     }
//                 } else {
//                     SkeletonRidge* b = base_of(r);
//                     for(int k = 0; k < b->point_count; ++k) {
//                         printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                     }
//                 }
//                 printf("\n");
//         }
//     }


//     apply_skeleton_tail_filter(skeleton);
//     printf("After tail filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             // if(r->startMinutia && r->endMinutia)
//             if(r->is_view==0) {
//                 for(int k = 0; k < r->point_count; ++k) {
//                     printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//                 }
//             } else {
//                 SkeletonRidge* b = base_of(r);
//                 for(int k = 0; k < b->point_count; ++k) {
//                     printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                 }
//             }
//             printf("\n");
//         }
//     }

//     apply_skeleton_fragment_filter(skeleton);
//     printf("After fragment filter: Number of minutiae: %d minutiae\n", skeleton->count);
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             // if(r->startMinutia && r->endMinutia)
//             if(r->is_view==0) {
//                 for(int k = 0; k < r->point_count; ++k) {
//                     printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//                 }
//             } else {
//                 SkeletonRidge* b = base_of(r);
//                 for(int k = 0; k < b->point_count; ++k) {
//                     printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                 }
//             }
//             printf("\n");
//         }
//     }

//     // // #define printf(...)
// }


// Skeleton* Skeletons_create(BooleanMatrix binary, SkeletonType type) {
//     // Log the input binary skeleton
//     // char label[256];
//     // snprintf(label, sizeof(label), "%sbinarized-skeleton", type.prefix);
//     // log_transparency(label, binary);

//     // Thinning
//     BooleanMatrix thinned = thin(&binary, type);

//     // printf("Thinned skeleton: width=%d, height=%d\n", thinned.width, thinned.height);
//     // for (int i = 0; i < thinned.height; ++i) {
//     //     for (int j = 0; j < thinned.width; ++j) {
//     //         printf("%d ", get_boolean_matrix(&thinned, j, i));
//     //     }
//     //     printf("\n");
//     // }

//     // Skeleton* skeleton;

//     // // Tracing
//     Skeleton* skeleton = trace(&thinned, type);
//     #undef printf
//         #define printf printf
//     printf("After trace: Number of minutiae: %d minutiae\n", skeleton->count);
//     // // #define printf(...)
//     free(thinned.cells);

//     #undef printf
//     #define printf printf    
//     for (int i = 0; i < skeleton->count; ++i)
//     {
//         SkeletonMinutia* m = skeleton->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//                 if(r->is_view==0) {
//                     for(int k = 0; k < r->point_count; ++k) {
//                         printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//                     }
//                 } else {
//                     SkeletonRidge* b = base_of(r);
//                     for(int k = 0; k < b->point_count; ++k) {
//                         printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                     }
//                 }
//                 printf("\n");
//         }
//     }
//     // // #define printf(...)

//     // // Optional: Free thinned if not needed anymore
//     // free_boolean_matrix(&thinned);

//     // Filtering
//     apply_skeleton_filters(skeleton);

//     return skeleton;
// }

// /////////////// Minutiacollector ///////////////////

// typedef enum {
//     MINUTIA_ENDING,
//     MINUTIA_BIFURCATION
// } MinutiaType;    

// typedef struct {
//     IntPoint position;
//     float direction;
//     MinutiaType type;
// } FeatureMinutia;

// typedef struct {
//     FeatureMinutia* data;
//     int size;
//     int capacity;
// } FeatureMinutiaArray;

// void init_feature_minutia_array(FeatureMinutiaArray* arr) {
//     arr->size = 0;
//     arr->capacity = 8;
//     arr->data = malloc(arr->capacity * sizeof(FeatureMinutia));
// }

// void push_feature_minutia(FeatureMinutiaArray* arr, FeatureMinutia value) {
//     if (arr->size == arr->capacity) {
//         // arr->capacity *= 2;
//         arr->capacity = arr->capacity * 3 / 2 + 1;

//         arr->data = realloc(arr->data, arr->capacity * sizeof(FeatureMinutia));
//     }
//     arr->data[arr->size++] = value;
//     printf("arr->size: %d\n",arr->size);
// }



// // Direction function for ridge
// float ridge_direction(SkeletonRidge* ridge) {
//     int first = RIDGE_DIRECTION_SKIP;
//     int last = RIDGE_DIRECTION_SKIP + RIDGE_DIRECTION_SAMPLE - 1;

//     if (last >= ridge->point_count) {
//         int shift = last - ridge->point_count + 1;
//         last -= shift;
//         first -= shift;
//     }

//     if (first < 0)
//         first = 0;

//     return (float)(atan_from_points(ridge_point_at(ridge, first), ridge_point_at(ridge, last)));
//     // return double_angle_atan(ridge->points[first], ridge->points[last]);
// }


// void collect_minutiae(FeatureMinutiaArray* out, Skeleton* skeleton, MinutiaType type) {
//     for (int i = 0; i < skeleton->count; ++i) {
//         SkeletonMinutia* sminutia = skeleton->minutiae[i];
//         // SkeletonMinutia* sminutia = &skeleton->minutiae[i];
//         printf("sminutia->ridge_count: %d\n",sminutia->ridge_count);
//         if (sminutia->ridge_count == 1) {
//             FeatureMinutia fminutia;
//             fminutia.position = sminutia->position;
//             fminutia.direction = ridge_direction(sminutia->ridges[0]);
//             fminutia.type = type;
//             printf("Adding fminutia.direction: %f\n",fminutia.direction);
//             push_feature_minutia(out, fminutia);
//         }
//     }
// }

// FeatureMinutiaArray collect_all_minutiae(Skeleton* ridges, Skeleton* valleys) {
//     FeatureMinutiaArray result;
//     init_feature_minutia_array(&result);
//     printf("COllecting all\n");
//     collect_minutiae(&result, ridges, MINUTIA_ENDING);
//     collect_minutiae(&result, valleys, MINUTIA_BIFURCATION);
//     return result;
// }

// typedef struct {
//     IntPoint size;
//     FeatureMinutiaArray minutiae;
// } FeatureTemplate;

// FeatureTemplate* create_feature_template(IntPoint size, FeatureMinutiaArray minutiae) {
//     FeatureTemplate* template = malloc(sizeof(FeatureTemplate));
//     template->size = size;
//     template->minutiae = minutiae;
//     return template;
// }

// void FeatureTemplate_free(FeatureTemplate* ft) {
//     if (!ft) return;

//     // Free the owned minutiae buffer
//     free(ft->minutiae.data);
//     ft->minutiae.data = NULL;
//     ft->minutiae.size = 0;
//     ft->minutiae.capacity = 0;

//     // Free the struct
//     free(ft);
// }


// IntPoint double_matrix_size(DoubleMatrix *matrix) {
//     IntPoint size;
//     size.x = matrix->width;
//     size.y = matrix->height;
//     return size;
// }

// /////////// InnerMinutiaeFilter //////////////

// IntPoint int_point_add(IntPoint a, IntPoint b) {
//     IntPoint result;
//     result.x = a.x + b.x;
//     result.y = a.y + b.y;
//     return result;
// }


// void inner_minutiae_filter_apply(FeatureMinutiaArray* minutiae, BooleanMatrix* mask) {
//     int dst = 0;
//     for (int src = 0; src < minutiae->size; ++src) {
//         FeatureMinutia m = minutiae->data[src];
//         DoublePoint vec = to_vector(m.direction);
//         DoublePoint displacement = multiply_doublepoint(vec, -MASK_DISPLACEMENT);
//         IntPoint arrow = round_doublepoint(displacement);
//         IntPoint displaced = int_point_add(m.position, arrow);
//         if(boolean_matrix_get_fallback(mask, displaced.x, displaced.y, false))
//         {
//             minutiae->data[dst++] = m;
//         }
//     }
//     minutiae->size = dst;
// }

// /////////////////// CloudFilter //////////////////////

// int int_point_length_sq(IntPoint p) {
//     return p.x * p.x + p.y * p.y;
// }

// IntPoint int_point_subtract(IntPoint a, IntPoint b) {
//     IntPoint result = { a.x - b.x, a.y - b.y };
//     return result;
// }

// void remove_feature_minutia_at(FeatureMinutiaArray* array, int index) {
//     for (int i = index + 1; i < array->size; ++i)
//         array->data[i - 1] = array->data[i];
//     array->size--;
// }

// void apply_minutia_cloud_filter(FeatureMinutiaArray* minutiae, int radius) {
//     int radius_sq = radius * radius;

//     // Mark which minutiae to remove
//     bool* remove_flags = calloc(minutiae->size, sizeof(bool));

//     for (int i = 0; i < minutiae->size; ++i) {
//         int count = 0;
//         for (int j = 0; j < minutiae->size; ++j) {
//             if (i == j) continue;
//             IntPoint diff = int_point_subtract(minutiae->data[j].position, minutiae->data[i].position);
//             if (int_point_length_sq(diff) <= radius_sq)
//                 count++;
//         }
//         if (count > MAX_CLOUD_SIZE)
//             remove_flags[i] = true;
//     }

//     // Remove in reverse to preserve indices
//     for (int i = minutiae->size - 1; i >= 0; --i) {
//         if (remove_flags[i])
//             remove_feature_minutia_at(minutiae, i);
//     }

//     free(remove_flags);
// }

// ///////////////////// TopMinutiaeFilter ///////////////////////

// typedef struct {
//     FeatureMinutia minutia;
//     int sort_key;
// } SortableMinutia;

// int compare_sortable_minutiae_desc(const void* a, const void* b) {
//     const SortableMinutia* ma = (const SortableMinutia*)a;
//     const SortableMinutia* mb = (const SortableMinutia*)b;
//     return mb->sort_key - ma->sort_key; // Descending order
// }

// int compute_sort_key(FeatureMinutia* m, FeatureMinutia* all, int size) {
//     int* distances = malloc(size * sizeof(int));
//     for (int i = 0; i < size; ++i) {
//         IntPoint delta = int_point_subtract(m->position, all[i].position);
//         distances[i] = int_point_length_sq(delta);
//     }

//     // Simple sort (e.g., insertion sort since array is small)
//     for (int i = 1; i < size; ++i) {
//         int key = distances[i];
//         int j = i - 1;
//         while (j >= 0 && distances[j] > key) {
//             distances[j + 1] = distances[j];
//             j--;
//         }
//         distances[j + 1] = key;
//     }

//     int result = (SORT_BY_NEIGHBOR < size)
//         ? distances[SORT_BY_NEIGHBOR]
//         : INT_MAX;

//     free(distances);
//     return result;
// }


// FeatureMinutiaArray* apply_top_minutiae_filter(const FeatureMinutiaArray* input) {
//     if (input->size <= MAX_MINUTIAE) {
//         FeatureMinutiaArray* result = input; // return as is
//         return result;
//     }

//     SortableMinutia* sortable = malloc(input->size * sizeof(SortableMinutia));
//     for (int i = 0; i < input->size; ++i) {
//         sortable[i].minutia = input->data[i];
//         sortable[i].sort_key = compute_sort_key(&input->data[i], input->data, input->size);
//     }

//     qsort(sortable, input->size, sizeof(SortableMinutia), compare_sortable_minutiae_desc);

//     FeatureMinutiaArray* result=(FeatureMinutiaArray*)malloc(sizeof(FeatureMinutiaArray));
//     result->size = MAX_MINUTIAE;
//     result->capacity = MAX_MINUTIAE;
//     result->data = malloc(result->capacity * sizeof(FeatureMinutia));

//     for (int i = 0; i < result->size; ++i) {
//         result->data[i] = sortable[i].minutia;
//     }

//     free(sortable);
//     return result;
// }


// const char* minutia_type_to_string(MinutiaType type) {
//     switch (type) {
//         case MINUTIA_ENDING: return "ENDING";
//         case MINUTIA_BIFURCATION: return "BIFURCATION";
//         default: return "UNKNOWN";
//     }
// }

// void print_feature_minutia_array(const FeatureMinutiaArray* array) {
//     printf("After TopMinutiaeFilter: \n");
//     for (int i = 0; i < array->size; ++i) {
//         FeatureMinutia* m = &array->data[i];
//         printf("Minutia %d:\n", i);
//         printf("  Position: (%d, %d)\n", m->position.x, m->position.y);
//         printf("  Direction: %.3f radians\n", m->direction);
//         printf("  Type: %s\n", minutia_type_to_string(m->type));
//     }
// }


// ///////////////// FeatureTemplate ///////////////////////



// FeatureTemplate* create_feature_template_from_list(IntPoint size, FeatureMinutiaArray* source) {
//     FeatureTemplate* ft = malloc(sizeof(FeatureTemplate));
//     if (!ft) return NULL;

//     ft->size = size;
//     ft->minutiae.size = source->size;
//     ft->minutiae.capacity = source->size;

//     ft->minutiae.data = malloc(sizeof(FeatureMinutia) * source->size);
//     if (!ft->minutiae.data) {
//         free(ft);
//         return NULL;
//     }

//     memcpy(ft->minutiae.data, source->data, sizeof(FeatureMinutia) * source->size);
//     return ft;
// }

// void free_feature_template(FeatureTemplate* ft){
//     if (ft) {
//         if (ft->minutiae.data) {
//             free(ft->minutiae.data);
//         }
//         free(ft);
//     }
// }


// void print_feature_template(const FeatureTemplate* ft) {
//     printf("FeatureTemplate:\n");
//     printf("  Size: (%d, %d)\n", ft->size.x, ft->size.y);
//     printf("  Minutiae count: %d\n", ft->minutiae.size);

//     for (int i = 0; i < ft->minutiae.size; ++i) {
//         FeatureMinutia* m = &ft->minutiae.data[i];
//         const char* type_str = (m->type == MINUTIA_ENDING) ? "ENDING" : "BIFURCATION";
//         printf("    Minutia %d: position=(%d, %d), direction=%.2f, type=%s\n",
//                i, m->position.x, m->position.y, m->direction, type_str);
//     }
// }

// ////////////////////////////
// FeatureTemplate* extract(DoubleMatrix raw, int dpi)
// {
//     IntPoint pixels;
//     pixels.x = raw.width;
//     pixels.y = raw.height;

//     BlockMap blocks = create_block_map(pixels.x, pixels.y, 20);   // PARAMTERS.BLOCK_SIZE=15
//     printf("After create_block_map:\n");
//     // print_sram_usage();
//     // sleep_ms(8000); 

//     printf("blocks.pixels.x: %d, blocks.pixels.y: %d\n", blocks.pixels.x, blocks.pixels.y);
    
//     printf("blocks.primary.blocks.x: %d, blocks.primary.blocks.y: %d\n", blocks.primary.blocks.x, blocks.primary.blocks.y);
//     printf("blocks.primary.corners.x: %d, blocks.primary.corners.y: %d\n", blocks.primary.corners.x, blocks.primary.corners.y);
//     for(int i=0;i<blocks.primary.corners.x;i++)
//     {
//         printf("blocks.primary.x[%d]: %d\n",i,blocks.primary.x[i]);
//     }
//     for(int i=0;i<blocks.primary.corners.y;i++)
//     {
//         printf("blocks.primary.y[%d]: %d\n",i,blocks.primary.y[i]);
//     }   

//     printf("blocks.secondary.blocks.x: %d, blocks.secondary.blocks.y: %d\n", blocks.secondary.blocks.x, blocks.secondary.blocks.y);
//     printf("blocks.secondary.corners.x: %d, blocks.secondary.corners.y: %d\n", blocks.secondary.corners.x, blocks.secondary.corners.y);
//     for(int i=0;i<blocks.secondary.corners.x;i++)
//     {
//         printf("blocks.secondary.x[%d]: %d\n",i,blocks.secondary.x[i]);
//     }
//     for(int i=0;i<blocks.secondary.corners.y;i++)
//     {   
//         printf("blocks.secondary.y[%d]: %d\n",i,blocks.secondary.y[i]);
//     }

//     /////////// HISTOGRAMCUBE ////////////////////
//     HistogramCube histogram = create_histogram_cube_from_point(blocks.primary.blocks, 256);
//     printf("After create_histogram_cube_from_point:\n");
//     // print_sram_usage();
//     // sleep_ms(8000); 
    
//     // Fill the histogram using image data
//     for (int by = 0; by < blocks.primary.blocks.y; ++by) {
//         for (int bx = 0; bx < blocks.primary.blocks.x; ++bx) {
//             IntPoint block = {bx, by};
//             IntRect area = blockgrid_block_point(&blocks.primary, block);
//             IntPoint topLeft = {area.x, area.y};
//             IntPoint bottomRight = {area.x + area.width, area.y + area.height};

//             for (int y = topLeft.y; y < bottomRight.y; ++y) {
//                 for (int x = topLeft.x; x < bottomRight.x; ++x) {
//                     float pixel = get(&raw,x,y); // grayscale in [0, 1)
//                     int depth = (int)(pixel * histogram.bins);
//                     depth = histogram_cube_constrain(&histogram, depth);
//                     histogram_cube_increment_at(&histogram, block, depth);
//                     printf("Incrementing histgram at: %d, %d, %d\n",block.x, block.y, depth);
//                 }
//             }
//         }
//     }
    
//     print_histogram_cube(&histogram);
//     printf("-----------------------------------\n");

//     HistogramCube smoothHistogram = histogramcube_smooth(&blocks, &histogram);  
//     print_histogram_cube(&smoothHistogram);

//     /////////////// SEGMENTATIONMASK //////////////////

//     BooleanMatrix mask = compute_mask(blocks, histogram);
//     free(histogram.counts);
//     printf("Freed histogram.counts\n");
//     DoubleMatrix equalized = equalize_image(blocks, raw, smoothHistogram, mask);
//     free(smoothHistogram.counts);

//     printf("equalized.width: %d, equalized.height: %d\n", equalized.width, equalized.height);
//     // for(int i=0;i<equalized.height;i++)
//     // {
//     //     for(int j=0;j<equalized.width;j++)
//     //     {
//     //         printf("%f ",double_matrix_get(&equalized,j,i));
//     //     }
//     //     printf("\n");
//     // }

//     // for(int i=0;i<blocks.primary.corners.x;i++)
//     // {
//     //     printf("BBBlocks.primary.x[%d]: %d\n",i,blocks.primary.x[i]);
//     // }
//     // for(int i=0;i<blocks.primary.corners.y;i++)
//     // {
//     //     printf("BBBlocks.primary.y[%d]: %d\n",i,blocks.primary.y[i]);
//     // }

//     // BlockOrientation.compute(equalized, mask, blocks);
//     DoubleMatrix orientation = compute_orientation(equalized, mask, blocks);
//     printf("Before smooth- orientation.width: %d, orientation.height: %d\n", orientation.width, orientation.height);
//     // OrientedSmoothing.parallel(equalized, orientation, mask, blocks)

//     DoubleMatrix smoothed = oriented_smoothing_parallel(equalized, orientation,mask,&blocks);
//     printf("smoothed.width: %d, smoothed.height: %d\n", smoothed.width, smoothed.height);
//     // for(int i=0;i<smoothed.height;i++)
//     // {
//     //     for(int j=0;j<smoothed.width;j++)
//     //     {   
//     //         printf("%f ",double_matrix_get(&smoothed,j,i));
//     //     }
//     //     printf("\n");
//     // }

//     free(equalized.data);

//     DoubleMatrix orthogonal = oriented_smoothing_orthogonal(smoothed, orientation, mask, &blocks);
//     free(orientation.data);

//     printf("orthogonal.width: %d, orthogonal.height: %d\n", orthogonal.width, orthogonal.height);
//     // for(int i=0;i<orthogonal.height;i++)
//     // {
//     //     for(int j=0;j<orthogonal.width;j++)
//     //     {   
//     //         printf("%f ",double_matrix_get(&orthogonal,j,i));
//     //     }
//     //     printf("\n");
//     // }

//     // Binarization
//     BooleanMatrix binary = binarize(&smoothed, &orthogonal, &mask, &blocks);
//     free(orthogonal.data);
//     free(smoothed.data);

//     printf("binary.width: %d, binary.height: %d\n", binary.width, binary.height);
//     // for(int i = 0; i < binary.height; ++i) {
//     //     for (int j = 0; j < binary.width; ++j) {
//     //         printf("%d ", get_boolean(&binary, j, i));
//     //     }
//     //     printf("\n");
//     // }

//     BooleanMatrix pixelMask = pixelwise(&mask, &blocks);
//     free(mask.cells);
//     free(blocks.primary.x); free(blocks.primary.y); free(blocks.secondary.x); free(blocks.secondary.y);

//     printf("pixelMask.width: %d, pixelMask.height: %d\n", pixelMask.width, pixelMask.height);
//     // for(int i = 0; i < pixelMask.height; ++i) {
//     //     for (int j = 0; j < pixelMask.width; ++j) {
//     //         printf("%d ", get_boolean(&pixelMask, j, i));
//     //     }
//     //     printf("\n");
//     // }

//     binarize_cleanup(&binary, &pixelMask);

//     BooleanMatrix inverted = invert(&binary, &pixelMask);
//     printf("inverted.width: %d, inverted.height: %d\n", inverted.width, inverted.height);
//     // for(int i = 0; i < inverted.height; ++i) {
//     //     for (int j = 0; j < inverted.width; ++j) {
//     //         printf("%d ", get_boolean(&inverted, j, i));
//     //     }
//     //     printf("\n");
//     // }

//     // for(int i = 0; i < innerMask.height; ++i) {
//     //     for (int j = 0; j < innerMask.width; ++j) {
//     //         printf("%d ", get_boolean(&innerMask, j, i));
//     //     }
//     //     printf("\n");
//     // }

//     BooleanMatrix innerMask = inner(&pixelMask);
//     free(pixelMask.cells);

//     Skeleton* ridges = Skeletons_create(binary, SKELETON_RIDGES);
//     free(binary.cells);

//     #undef printf
//     #define printf printf
//     printf("After ridges, Skeletons.create: Ridges created with %d minutiae\n", ridges->count);
//     // // // #define printf(...)

//     for (int i = 0; i < ridges->count; ++i)
//     {
//         SkeletonMinutia* m = ridges->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//                 if(r->is_view==0) {
//                     for(int k = 0; k < r->point_count; ++k) {
//                         printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//                     }
//                 } else {
//                     SkeletonRidge* b = base_of(r);
//                     for(int k = 0; k < b->point_count; ++k) {
//                         printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                     }
//                 }
//                 printf("\n");
//         }
//     }

//     // sleep_ms(8000);
//     // // #define printf(...)

//     Skeleton* valleys = Skeletons_create(inverted, SKELETON_VALLEYS);

//     #undef printf
//         #define printf printf
//     printf("After valleys, Skeletons.create: Valleys created with %d minutiae\n", valleys->count);
//     for (int i = 0; i < valleys->count; ++i)
//     {
//         SkeletonMinutia* m = valleys->minutiae[i];
//         printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
//         for (int j = 0; j < m->ridge_count; ++j)
//         {
//             SkeletonRidge* r = m->ridges[j];
//             printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
//                    r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
//                    r->endMinutia->position.x, r->endMinutia->position.y);
//                 if(r->is_view==0) {
//                     for(int k = 0; k < r->point_count; ++k) {
//                         printf("(%d, %d) ",ridge_point_at(r, k).x, ridge_point_at(r, k).y);
//                     }
//                 } else {
//                     SkeletonRidge* b = base_of(r);
//                     for(int k = 0; k < b->point_count; ++k) {
//                         printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
//                     }
//                 }
//                 printf("\n");
//         }
//     }

//     // sleep_ms(8000);
//     // // #define printf(...)

//     /////////////////////// MinutiaCollector //////////////////////////

//     IntPoint size = double_matrix_size(&raw);  // Equivalent of raw.size()

//     // free(raw.data);

//     printf("Before collect minutia\n");

//     FeatureMinutiaArray minutiae = collect_all_minutiae(ridges, valleys);  // MinutiaCollector.collect(...)
//     printf("minutia.size: %d\n",minutiae.size);

//     // free_skeleton(ridges);
//     // free_skeleton(valleys);
    
//     FeatureTemplate* template = create_feature_template(size, minutiae);
    
//     printf("Template Size: (%d, %d)\n", template->size.x, template->size.y);
//     printf("Number of Minutiae: %d\n", template->minutiae.size);
    
//     for (int i = 0; i < template->minutiae.size; ++i) {
//         FeatureMinutia m = template->minutiae.data[i];
//         const char* type_str = (m.type == MINUTIA_ENDING) ? "ENDING" :
//                                (m.type == MINUTIA_BIFURCATION) ? "BIFURCATION" : "UNKNOWN";
        
//         printf("Minutia %d: ", i);
//         printf("Position- (%d, %d); ", m.position.x, m.position.y);
//         printf("Direction- %.2f radians; ", m.direction);
//         printf("Type- %s\n", type_str);
//     }

//     /////////////// InnerMinutiaeFilter ///////////////////////////////

//     inner_minutiae_filter_apply(&template->minutiae, &innerMask);
//     printf("After InnerMinutiaeFilter - Template Size: (%d, %d)\n", template->size.x, template->size.y);
//     printf("Number of Minutiae: %d\n", template->minutiae.size);
    
//     for (int i = 0; i < template->minutiae.size; ++i) {
//         FeatureMinutia m = template->minutiae.data[i];
//         const char* type_str = (m.type == MINUTIA_ENDING) ? "ENDING" :
//                                (m.type == MINUTIA_BIFURCATION) ? "BIFURCATION" : "UNKNOWN";
        
//         printf("Minutia %d: ", i);
//         printf("Position- (%d, %d); ", m.position.x, m.position.y);
//         printf("Direction- %.2f radians; ", m.direction);
//         printf("Type- %s\n", type_str);
//     }

//     /////////////// MinutiaeCloudFilter ////////////////////

//     apply_minutia_cloud_filter(&template->minutiae, MINUTIA_CLOUD_RADIUS);
//     printf("After cloudFilter - Template Size: (%d, %d)\n", template->size.x, template->size.y);
//     printf("Number of Minutiae: %d\n", template->minutiae.size);
    
//     for (int i = 0; i < template->minutiae.size; ++i) {
//         FeatureMinutia m = template->minutiae.data[i];
//         const char* type_str = (m.type == MINUTIA_ENDING) ? "ENDING" :
//                                (m.type == MINUTIA_BIFURCATION) ? "BIFURCATION" : "UNKNOWN";
        
//         printf("Minutia %d: ", i);
//         printf("Position- (%d, %d); ", m.position.x, m.position.y);
//         printf("Direction- %.2f radians; ", m.direction);
//         printf("Type- %s\n", type_str);
//     }

//     /////////////// TopMinutiaeFilter ////////////////////////////

//     FeatureMinutiaArray* top_minutiae_filter_result = apply_top_minutiae_filter(&template->minutiae);

//     printf("After topMinutiae - Template Size: (%d, %d)\n", template->size.x, template->size.y);
//     printf("Number of Minutiae: %d\n", template->minutiae.size);
    
//     for (int i = 0; i < template->minutiae.size; ++i) {
//         FeatureMinutia m = template->minutiae.data[i];
//         const char* type_str = (m.type == MINUTIA_ENDING) ? "ENDING" :
//                                (m.type == MINUTIA_BIFURCATION) ? "BIFURCATION" : "UNKNOWN";
        
//         printf("Minutia %d: ", i);
//         printf("Position- (%d, %d); ", m.position.x, m.position.y);
//         printf("Direction- %.2f radians; ", m.direction);
//         printf("Type- %s\n", type_str);
//     }

//     print_feature_minutia_array(top_minutiae_filter_result);

//     //////////// FeatureTemplate /////////////////

//     FeatureTemplate* template_final = create_feature_template_from_list(template->size, top_minutiae_filter_result);
//     print_feature_template(template_final);

//     return template_final;

// }
// //////////// SearchTemplate /////////////////////

// /////// Search Minutaie //////
// typedef struct {
//     short x;
//     short y;
//     float direction;
//     MinutiaType type;
// } SearchMinutia;

// SearchMinutia create_search_minutia(const FeatureMinutia* feature) {
//     SearchMinutia sm;
//     sm.x = (short)feature->position.x;
//     sm.y = (short)feature->position.y;
//     sm.direction = feature->direction;
//     sm.type = feature->type;
//     return sm;
// }

// FeatureMinutia to_feature_minutia(const SearchMinutia* sm) {
//     FeatureMinutia fm;
//     fm.position.x = sm->x;
//     fm.position.y = sm->y;
//     fm.direction = sm->direction;
//     fm.type = sm->type;
//     return fm;
// }


// size_t search_minutia_memory() {
//     return 2 * sizeof(short) + sizeof(float) + sizeof(MinutiaType);
//     // If you want to mimic Java object overhead + reference: add sizeof(void*) as REFERENCE
// }

// ///// MemoryEstimates ///////


// typedef struct {
//     int BITNESS;
//     int REFERENCE;
//     int MARK;
//     int OBJECT_HEADER;
//     int ARRAY_HEADER;
//     int PADDING;
// } MemoryEstimates;

// static inline int detect_bitness() {
// #if defined(__x86_64__) || defined(_M_X64) || defined(__aarch64__)
//     return 64;
// #elif defined(__i386__) || defined(_M_IX86) || defined(__arm__) || defined(__MIPSEL__)
//     return 32;
// #else
//     return sizeof(void*) * 8; // fallback
// #endif
// }

// // Padding utility
// static inline int pad(int padding, int size) {
//     return ((size + padding - 1) / padding) * padding;
// }

// static inline int default_pad(int size) {
//     return pad(8, size); // 8 is default alignment
// }

// // Assume compressed references (4 bytes) even on 64-bit (like in Java)
// static inline void init_memory_estimates(MemoryEstimates* m) {
//     m->BITNESS = detect_bitness();
//     m->REFERENCE = 4;
//     m->MARK = m->BITNESS / 8;
//     m->OBJECT_HEADER = m->MARK + m->REFERENCE;
//     m->PADDING = 8;
//     m->ARRAY_HEADER = m->OBJECT_HEADER + 4;
// }

// // Memory for object with `fields` bytes, aligned to largest field `alignment`
// static inline int memory_estimates_object(MemoryEstimates* m, int fields, int alignment) {
//     return default_pad(pad(alignment, m->OBJECT_HEADER) + fields);
// }

// // Memory for array of `count` elements of `component` bytes each
// static inline int memory_estimates_array(MemoryEstimates* m, int component, int count) {
//     return default_pad(pad(component, m->ARRAY_HEADER) + component * count);
// }

// ////// Edge Shape //////

// // const int POLAR_DISTANCE_CACHE[POLAR_CACHE_SIZE] __in_flash() = { 0 };
// // const float POLAR_ANGLE_CACHE[POLAR_CACHE_SIZE]    __in_flash() = { 0.0f };

// // static int POLAR_DISTANCE_CACHE [POLAR_CACHE_SIZE];
// // static float POLAR_ANGLE_CACHE[POLAR_CACHE_SIZE];

// // Precompute caches
// void init_edge_shape_cache(int* POLAR_DISTANCE_CACHE, float* POLAR_ANGLE_CACHE) {
//     for (int y = 0; y < POLAR_CACHE_RADIUS; ++y) {
//         for (int x = 0; x < POLAR_CACHE_RADIUS; ++x) {
//             int index = y * POLAR_CACHE_RADIUS + x;
//             POLAR_DISTANCE_CACHE[index] = java_round(sqrt(x * x + y * y));
//             if (y > 0 || x > 0)
//                 POLAR_ANGLE_CACHE[index] = atan2f((float)y, (float)x);  // equivalent to DoubleAngle.atan
//             else
//                 POLAR_ANGLE_CACHE[index] = 0.0f;
//         }
//     }
// }


// typedef struct {
//     short length;
//     float referenceAngle;
//     float neighborAngle;
// } EdgeShape;



// float float_angle_difference(float a, float b) {
//     float angle = a-b;
//     printf("float_angle_difference: first=%.2f, second=%.2f, angle=%.2f\n", a, b, angle);
//     return angle>=0 ? angle : angle + 2 * M_PI; // Normalize to [0, 2π)
// }

// float float_angle_opposite(float angle) {
//     return angle < M_PI ? angle + M_PI : angle - M_PI; 
// }

// // float float_angle_distance(float first, float second) {
// //     float delta = fabsf(first - second);
// //     return (delta <= M_PI) ? delta : 2 * M_PI - delta;
// // }

// float float_angle_distance(float first, float second) {
//     printf("In float_angle_distance: first=%.2f, second=%.2f\n", first, second);
//     float delta = fabsf(first - second);
//     printf("delta: %.2f\n", delta);
//     // delta = fmodf(delta, 2.0f * (float)M_PI); // Normalize to [0, 2π)

//     return (delta <= (float)M_PI) ? delta : (2.0f * (float)M_PI - delta);
// }

// // Constructor from two SearchMinutiae
// EdgeShape* create_edge_shape(SearchMinutia reference, SearchMinutia neighbor) {
//     int POLAR_DISTANCE_CACHE[POLAR_CACHE_SIZE]= { 0 };
//     float POLAR_ANGLE_CACHE[POLAR_CACHE_SIZE]  = { 0.0f };

//     init_edge_shape_cache(POLAR_DISTANCE_CACHE, POLAR_ANGLE_CACHE);

//     float quadrant = 0.0f;
//     int x = neighbor.x - reference.x;
//     int y = neighbor.y - reference.y;
//     printf("create_edge_shape: x=%d, y=%d\n", x, y);

//     if (y < 0) {
//         x = -x;
//         y = -y;
//         quadrant = M_PI;
//     }
//     printf("new x=%d, y=%d, quadrant=%.2f\n", x, y, quadrant);

//     if (x < 0) {
//         int tmp = -x;
//         x = y;
//         y = tmp;
//         quadrant += HALF_PI;
//     }

//     printf("2 new x=%d, y=%d, quadrant=%.2f\n", x, y, quadrant);

//     unsigned int combined = (x | y) >> POLAR_CACHE_BITS;
//     printf("combined: %d\n", combined);
//     int shift = (combined == 0) ? 0 : 32 - __builtin_clz(combined);
//     printf("shift: %d\n", shift);

//     int offset = ((y >> shift) * POLAR_CACHE_RADIUS) + (x >> shift);
//     printf("offset: %d\n", offset);
//     int cached_distance = POLAR_DISTANCE_CACHE[offset];
//     printf("cached_distance: %d\n", cached_distance);
//     float angle = POLAR_ANGLE_CACHE[offset] + quadrant;
//     printf("angle: %.2f\n", angle);
//     printf("reference.direction: %.2f, neighbor.direction: %.2f\n", reference.direction, neighbor.direction);
//     printf("float_angle_opposite(angle): %.2f\n", float_angle_opposite(angle));

//     EdgeShape* shape= (EdgeShape*)malloc(sizeof(EdgeShape));
//     shape->length = (short)(cached_distance << shift);
//     printf("length: %d\n", shape->length);
//     shape->referenceAngle = float_angle_difference(reference.direction, angle);
//     printf("referenceAngle: %.3f\n", shape->referenceAngle);
//     shape->neighborAngle = float_angle_difference(neighbor.direction, float_angle_opposite(angle));
//     printf("neighborAngle: %.3f\n", shape->neighborAngle);

//     // printf("EdgeShape created: length=%d, reference_angle=%.3f, neighbor_angle=%.3f\n",
//     //        shape->length, shape->referenceAngle, shape->neighborAngle);
//     return shape;
// }

// ////// NeighborEdge ///////////

// typedef struct {
//     EdgeShape* shape;
//     short neighbor;
// } NeighborEdge;

// NeighborEdge* NeighborEdge_new(SearchMinutia* minutiae, int reference, int neighbor) {
//     NeighborEdge* edge = malloc(sizeof(NeighborEdge));
//     edge->shape = create_edge_shape(minutiae[reference], minutiae[neighbor]);
//     edge->neighbor = (short)neighbor;
//     return edge;
// }

// // Comparison function for qsort
// static int compare_edge_length(const void* a, const void* b) {
//     float len_a = ((NeighborEdge*)a)->shape->length;
//     float len_b = ((NeighborEdge*)b)->shape->length;
//     return (len_a > len_b) - (len_a < len_b);
// }

// // Comparator function: sort by length, then neighbor
// int compare_edges(const void* a, const void* b) {
//     const NeighborEdge* e1 = (const NeighborEdge*)a;
//     const NeighborEdge* e2 = (const NeighborEdge*)b;

//     if (e1->shape->length != e2->shape->length)
//         return (e1->shape->length > e2->shape->length) - (e1->shape->length < e2->shape->length);
    
//     return (e1->neighbor > e2->neighbor) - (e1->neighbor < e2->neighbor);
// }

// int compare_ints(const int* a, const int* b) {
//     return (*a) - (*b);
// }

// NeighborEdge** build_table(const SearchMinutia* minutiae, int count, int* edge_count) {
//     NeighborEdge** edges = malloc(count * sizeof(NeighborEdge*));
//     int* sq_distances = malloc(count * sizeof(int));
//     NeighborEdge* star = malloc(count * sizeof(NeighborEdge)); // temporary array

//     for (int reference = 0; reference < count; ++reference) {
//         const SearchMinutia* rminutia = &minutiae[reference];
//         int maxSqDistance = INT_MAX;

//         // evaluated maxSqDistance
//         if (count - 1 > EDGE_TABLE_NEIGHBORS) {
//             for (int neighbor = 0; neighbor < count; ++neighbor) {
//                 const SearchMinutia* nminutia = &minutiae[neighbor];
//                 sq_distances[neighbor] = sq(rminutia->x - nminutia->x) + sq(rminutia->y - nminutia->y);
//             }
//             // sort copy of sq_distances
//             int* sorted = malloc(count * sizeof(int));
//             memcpy(sorted, sq_distances, count * sizeof(int));
//             qsort(sorted, count, sizeof(int), compare_ints);
//             maxSqDistance = sorted[EDGE_TABLE_NEIGHBORS];
//             free(sorted);
//         }

//         printf("maxSqDistance for reference %d: %d\n", reference, maxSqDistance);

//         int star_size = 0;
//         for (int neighbor = 0; neighbor < count; ++neighbor) {
//             if (neighbor == reference)
//                 continue;
//             int dist = sq(rminutia->x - minutiae[neighbor].x) + sq(rminutia->y - minutiae[neighbor].y);
//             if (dist <= maxSqDistance) {
//                 printf("neighbour: %d, distance: %d\n", neighbor, dist);
//                 star[star_size].shape = create_edge_shape(*rminutia, minutiae[neighbor]);
//                 star[star_size].neighbor = (short)neighbor;
//                 ++star_size;
//             }
//         }

//         qsort(star, star_size, sizeof(NeighborEdge), compare_edges);

//         if (star_size > EDGE_TABLE_NEIGHBORS)
//             star_size = EDGE_TABLE_NEIGHBORS;

//         edges[reference] = malloc(star_size * sizeof(NeighborEdge));
//         memcpy(edges[reference], star, star_size * sizeof(NeighborEdge));
//         // You may want to store size info externally or in a struct

//         edge_count[reference] = star_size;
//     }

//     free(sq_distances);
//     free(star);
//     return edges;
// }

// void free_table(NeighborEdge** edges, int count) {
//     if (!edges) return;

//     for (int i = 0; i < count; i++) {
//         if (edges[i]) {
//             free(edges[i]);  // free each neighbor list
//         }
//     }
//     free(edges); // free the outer pointer array
// }


// int NeighborEdge_memory() {
//     MemoryEstimates* m = (MemoryEstimates*)(malloc(sizeof(MemoryEstimates)));
//     return memory_estimates_object(m, 2 * sizeof(short) + 2 * sizeof(float), sizeof(float));
// }

// ///// SearchTemplate //////

// #define PRIME 1610612741

// typedef struct {
//     short width;
//     short height;
//     SearchMinutia* minutiae;
//     int minutiae_count;
//     NeighborEdge** edges; // edges[i] is an array of NeighborEdge
//     int* edge_counts;     // lengths of each edges[i]
// } SearchTemplate;

// // Empty constant (equivalent to SearchTemplate.EMPTY)
// SearchTemplate* SearchTemplate_empty() {
//     SearchTemplate* st = (SearchTemplate*)calloc(1, sizeof(SearchTemplate));
//     st->width = 1;
//     st->height = 1;
//     st->minutiae = NULL;
//     st->minutiae_count = 0;
//     st->edges = NULL;
//     st->edge_counts = NULL;
//     return st;
// }

// // Comparison function for qsort
// int compare_search_minutia(const void* a, const void* b) {
//     const SearchMinutia* m1 = (const SearchMinutia*)a;
//     const SearchMinutia* m2 = (const SearchMinutia*)b;

//     int hash1 = ((m1->x * PRIME) + m1->y) * PRIME;
//     int hash2 = ((m2->x * PRIME) + m2->y) * PRIME;

//     if (hash1 != hash2)
//         return (hash1 > hash2) - (hash1 < hash2); // avoids overflow

//     if (m1->x != m2->x)
//         return (m1->x > m2->x) - (m1->x < m2->x);

//     if (m1->y != m2->y)
//         return (m1->y > m2->y) - (m1->y < m2->y);

//     if (m1->direction != m2->direction)
//         return (m1->direction > m2->direction) - (m1->direction < m2->direction);

//     return m1->type - m2->type; // assuming enum values are ordered
// }


// SearchTemplate* SearchTemplate_new(const FeatureTemplate* features) {
//     if (!features) return NULL;

//     SearchTemplate* st = (SearchTemplate*)malloc(sizeof(SearchTemplate));
//     if (!st) return NULL;

//     st->width = (short)features->size.x;
//     st->height = (short)features->size.y;

//     st->minutiae_count = features->minutiae.size;
//     st->minutiae = (SearchMinutia*)malloc(sizeof(SearchMinutia) * st->minutiae_count);
//     st->edge_counts = (int*)malloc(sizeof(int) * st->minutiae_count);

//     if (!st->minutiae) {
//         free(st);
//         return NULL;
//     }

//     // creating the searchtemplate's minutiae from original template's minutaie's
//     for (int i = 0; i < st->minutiae_count; ++i)
//         st->minutiae[i] = create_search_minutia(&features->minutiae.data[i]);

//     qsort(st->minutiae, st->minutiae_count, sizeof(SearchMinutia), compare_search_minutia);

//     for(int i=0;i<st->minutiae_count;i++)
//     {
//         printf("Minutia %d: x=%d, y=%d, direction=%.2f, type=%s\n",
//                i, st->minutiae[i].x, st->minutiae[i].y, st->minutiae[i].direction, minutia_type_to_string(st->minutiae[i].type));
//     }

//     // Build edge table and get edge counts per minutia
//     st->edges = build_table(st->minutiae, st->minutiae_count, st->edge_counts);
//     if (!st->edges) {
//         free(st->minutiae);
//         free(st);
//         return NULL;
//     }

//     return st;
// }

// void SearchTemplate_free(SearchTemplate* st) {
//     if (!st) return;

//     // Free the edge table if it has its own allocations
//     if (st->edges) {
//         free_table(st->edges, st->minutiae_count);  
//     }

//     // Free arrays allocated in SearchTemplate_new
//     free(st->minutiae);
//     free(st->edge_counts);

//     // Finally free the struct itself
//     free(st);
// }

// // Convert back to FeatureTemplate
// FeatureTemplate* SearchTemplate_to_feature(const SearchTemplate* st) {
//     FeatureTemplate* ft = (FeatureTemplate*)malloc(sizeof(FeatureTemplate));
//     ft->size = (IntPoint){ st->width, st->height };
//     ft->minutiae.size = st->minutiae_count;
//     ft->minutiae.data = (FeatureMinutia*)malloc(sizeof(FeatureMinutia) * ft->minutiae.size);
//     for (int i = 0; i < ft->minutiae.size; ++i)
//         ft->minutiae.data[i] = to_feature_minutia(&st->minutiae[i]);
//     return ft;
// }

// // Memory estimate
// int SearchTemplate_memory(const SearchTemplate* st) {
//     MemoryEstimates* m= (MemoryEstimates*)(malloc(sizeof(MemoryEstimates)));
//     init_memory_estimates(m);

//     int mem = memory_estimates_object(m, 2 * sizeof(short) + 2 * m->REFERENCE,  m->REFERENCE);
//     mem += memory_estimates_array(m, m->REFERENCE, st->minutiae_count);
//     mem += st->minutiae_count * search_minutia_memory();

//     mem += memory_estimates_array( m, m->REFERENCE, st->minutiae_count);
//     for (int i = 0; i < st->minutiae_count; ++i) {
//         mem +=memory_estimates_array( m, m->REFERENCE, st->edge_counts[i]);
//         mem += st->edge_counts[i] * NeighborEdge_memory();
//     }
//     return mem;
// }


// void print_search_template(SearchTemplate* template) {
//     printf("SearchTemplate:\n");
//     printf("Minutiae Count: %d\n", template->minutiae_count);

//     for (int i = 0; i < template->minutiae_count; ++i) {
//         SearchMinutia m = template->minutiae[i];
//         printf("  Minutia[%d]: x=%d, y=%d, direction=%.2f, type=%s\n",
//                i, m.x, m.y, m.direction,  minutia_type_to_string(m.type));
//     }

//     for (int i = 0; i < template->minutiae_count; ++i) {
//         printf("  Edges[%d] (%d neighbors):\n", i, template->edge_counts[i]);
//         for (int j = 0; j < template->edge_counts[i]; ++j) {
//             NeighborEdge e = template->edges[i][j];
//             printf("    → Neighbor=%d, length=%hd, referenceAngle=%.2f, neighborAngle=%.2f\n",
//                    e.neighbor, e.shape->length, e.shape->referenceAngle, e.shape->neighborAngle);
//         }
//     }

//     // FILE* file = fopen("minutiae_C_file.txt", "a"); // open in append mode
//     // if (!file) {
//     //     perror("Failed to open file");
//     //     return;
//     // }

//     // fprintf(file, "SearchTemplate:\n");
//     // fprintf(file, "Minutiae Count: %d\n", template->minutiae_count);

//     // for (int i = 0; i < template->minutiae_count; ++i) {
//     //     SearchMinutia m = template->minutiae[i];
//     //     fprintf(file, "  Minutia[%d]: x=%d, y=%d, direction=%.2f, type=%s\n",
//     //             i, m.x, m.y, m.direction, minutia_type_to_string(m.type));
//     // }

//     // for (int i = 0; i < template->minutiae_count; ++i) {
//     //     fprintf(file, "  Edges[%d] (%d neighbors):\n", i, template->edge_counts[i]);
//     //     for (int j = 0; j < template->edge_counts[i]; ++j) {
//     //         NeighborEdge e = template->edges[i][j];
//     //         fprintf(file, "    → Neighbor=%d, length=%hd, referenceAngle=%.2f, neighborAngle=%.2f\n",
//     //                 e.neighbor, e.shape->length, e.shape->referenceAngle, e.shape->neighborAngle);
//     //     }
//     // }

//     // // fprintf(file, "\n"); // add a blank line for readability

//     // fclose(file);
// }

// ////////// EdgeHashes ///////////////
// #include "khash.h"

// #define MAX_DISTANCE_ERROR 13       // Example value (use actual)
// float MAX_ANGLE_ERROR = (float)(M_PI)/180*10; // Example value (use actual)
// // #define MAX_ANGLE_ERROR ((float)(M_PI)/180*10)      // Example value (use actual)

// typedef struct {
//     char reference;
//     char neighbor;
//     EdgeShape* shape;  // Assuming you want to store EdgeShape info as well
// } IndexedEdge;

// typedef struct {
//     IndexedEdge* data;
//     int size;
//     int capacity;
// } IndexedEdgeList;

// void IndexedEdge_init(IndexedEdge* edge, const SearchMinutia* minutiae, int reference, int neighbor) {
//     edge->shape = create_edge_shape(minutiae[reference], minutiae[neighbor]);
//     edge->reference = (char)reference;
//     edge->neighbor = (char)neighbor;
// }

// KHASH_INIT(edge_map, int, IndexedEdgeList*, 1, kh_int_hash_func, kh_int_hash_equal)
// typedef khash_t(edge_map) EdgeHashMap;

// void indexed_edge_list_init(IndexedEdgeList* list) {
//     list->size = 0;
//     list->capacity = 4;
//     list->data = malloc(sizeof(IndexedEdge) * list->capacity);
// }

// void indexed_edge_list_add(IndexedEdgeList* list, IndexedEdge edge) {
//     if (list->size >= list->capacity) {
//         list->capacity *= 2;
//         // list->capacity = list->capacity * 3 / 2+1; // Grow by 1.5x
//         list->data = realloc(list->data, sizeof(IndexedEdge) * list->capacity);
//     }
//     list->data[list->size++] = edge;
// }

// float complementary(float angle) {
//     float complement = PI2 - angle;
//     return (complement < PI2) ? complement : (complement - PI2);
// }

// float float_angle_add(float start, float delta) {
//     float angle = start + delta;
//     printf("float_angle_add: start=%.3f, delta=%.3f, angle=%.3f\n", start, delta, angle);
//     return (angle < PI2) ? angle : (angle - PI2);
// }

// int hash_edge_shape(EdgeShape* edge) {
//     int lengthBin = edge->length / MAX_DISTANCE_ERROR;
//     int referenceAngleBin = (int)(edge->referenceAngle / MAX_ANGLE_ERROR);
//     int neighborAngleBin = (int)(edge->neighborAngle / MAX_ANGLE_ERROR);
//     return (referenceAngleBin << 24) + (neighborAngleBin << 16) + lengthBin;
// }

// bool matching(EdgeShape probe, EdgeShape candidate) {
//     printf("Matching: probe.length=%d, candidate.length=%d, probe.referenceAngle=%.3f, candidate.referenceAngle=%.3f\n",
//            probe.length, candidate.length, probe.referenceAngle, candidate.referenceAngle);
//     int lengthDelta = probe.length - candidate.length;
//     if (lengthDelta >= -MAX_DISTANCE_ERROR && lengthDelta <= MAX_DISTANCE_ERROR) {
//         float refDelta = float_angle_difference(probe.referenceAngle, candidate.referenceAngle);
//         float compAngleError = complementary(MAX_ANGLE_ERROR);
//         if (refDelta <= MAX_ANGLE_ERROR || refDelta >= compAngleError) {
//             float neighDelta = float_angle_difference(probe.neighborAngle, candidate.neighborAngle);
//             if (neighDelta <= MAX_ANGLE_ERROR || neighDelta >= compAngleError)
//             {
//                 printf("Matching successful: lengthDelta=%d, referenceDelta=%.3f, neighborDelta=%.3f\n",
//                        lengthDelta, refDelta, neighDelta);
//                 return true;
//             }
//         }
//     }
//     printf("Matching failed\n");
//     return false;
// }

// int* coverage(EdgeShape* edge, int* outSize) {
//     printf("EdgeShape: length=%d, referenceAngle=%.3f, neighborAngle=%.3f\n",
//            edge->length, edge->referenceAngle, edge->neighborAngle);
//     printf("Maxdistance error: %d, Max angle error: %.3f\n", MAX_DISTANCE_ERROR, MAX_ANGLE_ERROR);
//     int minLengthBin = (edge->length - MAX_DISTANCE_ERROR) / MAX_DISTANCE_ERROR;
//     int maxLengthBin = (edge->length + MAX_DISTANCE_ERROR) / MAX_DISTANCE_ERROR;
//     int angleBins = (int)ceilf((float)(2.0f * M_PI) / MAX_ANGLE_ERROR);

//     float f1 = float_angle_difference(edge->referenceAngle, MAX_ANGLE_ERROR);
//     int minReferenceBin = (int)(f1/ MAX_ANGLE_ERROR);
//     f1=float_angle_add(edge->referenceAngle, MAX_ANGLE_ERROR);
//     int maxReferenceBin = (int)(f1 / MAX_ANGLE_ERROR);
//     int endReferenceBin = (maxReferenceBin + 1) % angleBins;

//     f1=float_angle_difference(edge->neighborAngle, MAX_ANGLE_ERROR);
//     int minNeighborBin = (int)(f1 / MAX_ANGLE_ERROR);
//     f1=float_angle_add(edge->neighborAngle, MAX_ANGLE_ERROR);
//     int maxNeighborBin = (int)(f1 / MAX_ANGLE_ERROR);
//     int endNeighborBin = (maxNeighborBin + 1) % angleBins;

//     printf("minLengthBin: %d, maxLengthBin: %d\n", minLengthBin, maxLengthBin);
//     printf("minReferenceBin: %d, maxReferenceBin: %d, endReferenceBin: %d\n",
//            minReferenceBin, maxReferenceBin, endReferenceBin);
//     printf("minNeighborBin: %d, maxNeighborBin: %d, endNeighborBin: %d\n",
//            minNeighborBin, maxNeighborBin, endNeighborBin);
//     printf("angleBins: %d\n", angleBins);

//     // Estimate max size
//     int maxSize = (maxLengthBin - minLengthBin + 1) * angleBins * angleBins;
//     int* result = (int*)malloc(maxSize * sizeof(int));
//     int count = 0;

//     for (int lengthBin = minLengthBin; lengthBin <= maxLengthBin; ++lengthBin) {
//         for (int referenceBin = minReferenceBin;
//              referenceBin != endReferenceBin;
//              referenceBin = (referenceBin + 1) % angleBins) {

//             printf("lengthBin: %d, referenceBin: %d\n", lengthBin, referenceBin);
//             for (int neighborBin = minNeighborBin;
//                  neighborBin != endNeighborBin;
//                  neighborBin = (neighborBin + 1) % angleBins) {

//                 int code = (referenceBin << 24) + (neighborBin << 16) + lengthBin;

//                 printf("coverage[%d]: ReferenceBin=%d, NeighborBin=%d, LengthBin=%d, fin: %d\n",
//                        count, referenceBin, neighborBin, lengthBin, code);
//                 result[count++] = code;
//             }
//         }
//     }

//     printf("Edge coverage: %d hashes\n", count);
//     for(int i = 0; i < count; ++i) {
//         printf("Hash %d: ReferenceBin=%d, NeighborBin=%d, LengthBin=%d\n",
//                result[i], 
//                (result[i] >> 24) & 0xFF, 
//                (result[i] >> 16) & 0xFF, 
//                result[i] & 0xFFFF);
//     }

//     *outSize = count;
//     return result;
// }


// EdgeHashMap* build_edge_map(const SearchTemplate* template) {
//     // Uses a khash map from int → IndexedEdgeList*
//     // typedef khash_t(edge_map) EdgeHashMap;
//     EdgeHashMap* map = kh_init(edge_map);

//     for (int reference = 0; reference < template->minutiae_count; ++reference) {
//         for (int neighbor = 0; neighbor < template->minutiae_count; ++neighbor) {
//             if (reference != neighbor) {
//                 IndexedEdge* edge = (IndexedEdge*)malloc(sizeof(IndexedEdge));
//                 IndexedEdge_init(edge, template->minutiae, reference, neighbor);

//                 int hash_count;
//                 int* hashes = coverage(edge->shape, &hash_count);  // You already have this

//                 // for(int i = 0; i < hash_count; ++i) {
//                 //     printf("hash: %d for edge (%d, %d)\n", hashes[i], reference, neighbor);
//                 // }

//                 for (int i = 0; i < hash_count; ++i) {
//                     printf("hash: %d for edge (%d, %d)\n", hashes[i], reference, neighbor);
//                     // extract k corresponding to hash index from map
//                     // kh_get() returns an iterator k to the map location, or kh_end(map) if not found.
//                     khiter_t k = kh_get(edge_map, map, hashes[i]); // Use hashes[i] instead of hash
//                     IndexedEdgeList* list;

//                     if (k == kh_end(map)) {
//                         // Not found, create new list
//                         list = malloc(sizeof(IndexedEdgeList));
//                         list->data = malloc(4 * sizeof(IndexedEdge)); // initial capacity
//                         list->size = 0;
//                         list->capacity = 4;

//                         // putting empty initialized list into the map
//                         int ret;
//                         k = kh_put(edge_map, map, hashes[i], &ret);
//                         kh_value(map, k) = list;
//                         printf("Created new list for hash %d\n", hashes[i]);
//                         for(int j=0;j<list->size;j++)
//                         {
//                             printf("list[%d] = (%d, %d)\n", j, list->data[j].reference, list->data[j].neighbor);
//                         }
//                     } else {
//                         // Found
//                         list = kh_value(map, k);
//                         printf("Got list for hash %d\n", hashes[i]);
//                         for(int j=0;j<list->size;j++)
//                         {
//                             printf("list[%d] = (%d, %d)\n", j, list->data[j].reference, list->data[j].neighbor);
//                         }
//                     }

//                     // Append edge to list
//                     if (list->size == list->capacity) {
//                         list->capacity *= 2;
//                         // list->capacity = list->capacity * 3 / 2 + 1; // Grow by 1.5x
//                         list->data = realloc(list->data, list->capacity * sizeof(IndexedEdge));
//                     }

//                     // list->data[list->size++] = *edge;

//                     IndexedEdge* dest = &list->data[list->size++]; // 
//                     memcpy(dest, edge, sizeof(IndexedEdge));  // copy value (shallow first)

//                     if (edge->shape) {
//                         dest->shape = malloc(sizeof(EdgeShape));  // allocate new EdgeShape
//                         if (!dest->shape) {
//                             fprintf(stderr, "Failed to allocate EdgeShape\n");
//                             exit(1);
//                         }
//                         memcpy(dest->shape, edge->shape, sizeof(EdgeShape));  // deep copy contents
//                     } else {
//                         dest->shape = NULL;
//                     }

//                     printf("Appended edge (%d, %d) to list for hash %d\n", dest->reference, dest->neighbor, hashes[i]);
//                     printf("List after append: ");
//                     for(int j=0;j<list->size;j++)
//                     {
//                         printf("(%d, %d) ", list->data[j].reference, list->data[j].neighbor);
//                     }
//                     printf("\n");

//                 }

//                 free(hashes);
//                 printf("--------------------------------\n");
//             }
//         }
//     }

//     // for (khiter_t k = kh_begin(map); k != kh_end(map); ++k) {
//     //     // printf("Key: %d\n", kh_key(map, k));
//     //     if (kh_exist(map, k)) {
//     //         int hash = kh_key(map, k);
//     //         IndexedEdgeList* list = kh_value(map, k);

//     //         printf("Hash: %d\n", hash);
//     //         for (int i = 0; i < list->size; ++i) {
//     //             IndexedEdge* edge = &list->data[i];
//     //             printf("  → Ref: %d, Nbr: %d, Distance: %d, RefAngle: %.2f, NbrAngle: %.2f\n",
//     //                    edge->reference,
//     //                    edge->neighbor,
//     //                    edge->shape->length,
//     //                    edge->shape->referenceAngle,
//     //                    edge->shape->neighborAngle);
//     //         }
//     //     }
//     // }

//     // TransparencySink.current().logEdgeHash(map); // optional logging
//     return map;
// }
// // EdgeHashMap* build_edge_map(const SearchTemplate* template) {
// //     EdgeHashMap* map = kh_init(edge_map);

// //     for (int reference = 0; reference < template->minutiae_count; ++reference) {
// //         for (int neighbor = 0; neighbor < template->minutiae_count; ++neighbor) {
// //             if (reference != neighbor) {
// //                 IndexedEdge* edge = (IndexedEdge*)malloc(sizeof(IndexedEdge));
// //                 IndexedEdge_init(edge, template->minutiae, reference, neighbor);

// //                 int hash_count;
// //                 int* hashes = coverage(edge->shape, &hash_count);  // You already have this

// //                 for (int i = 0; i < hash_count; ++i) {
// //                     // extract k corresponding to hash index from map
// //                     khiter_t k = kh_get(edge_map, map, hashes[i]); // Use hashes[i] instead of hash
// //                     IndexedEdgeList* list;

// //                     if (k == kh_end(map)) {
// //                         // Not found, create new list
// //                         list = malloc(sizeof(IndexedEdgeList));
// //                         list->data = malloc(4 * sizeof(IndexedEdge)); // initial capacity
// //                         list->size = 0;
// //                         list->capacity = 4;

// //                         // putting empty initialized list into the map
// //                         int ret;
// //                         k = kh_put(edge_map, map, hashes[i], &ret);
// //                         kh_value(map, k) = list;
// //                     } else {
// //                         // Found
// //                         list = kh_value(map, k);
// //                     }

// //                     // Append edge to list
// //                     if (list->size == list->capacity) {
// //                         list->capacity *= 2;
// //                         list->data = realloc(list->data, list->capacity * sizeof(IndexedEdge));
// //                     }

// //                     list->data[list->size++] = *edge;
// //                 }

// //                 free(hashes);
// //             }
// //         }
// //     }

// //     // TransparencySink.current().logEdgeHash(map); // optional logging
// //     return map;
// // }


// void free_edge_map(EdgeHashMap* map) {
//     for (khiter_t k = kh_begin(map); k != kh_end(map); ++k) {
//         if (kh_exist(map, k)) {
//             IndexedEdgeList* list = kh_value(map, k);
//             free(list->data);
//             free(list);
//         }
//     }
//     kh_destroy(edge_map, map);
// }

// // If ridge is reversed and base 
// static void destroy_ridge_once(SkeletonRidge* r) {
//     if (!r) return;
//     printf("r->is_view: %d\n", r->is_view);

//     SkeletonRidge* b = base_of(r);
//     printf("b->freed: %d\n", b->freed);

//     if (!b || b->freed) return;     // already freed, do nothing
//     b->freed = 1;

//     free(b->points);
//     b->points = NULL;
//     b->point_count = b->point_capacity = 0;

//     if (b->reversed) {
//         SkeletonRidge* v = b->reversed;

//         // Defensive: if legacy code ever allocated v->points, free it
//         // if (v->points) { free(v->points); v->points = NULL; }

//         // b->reversed = NULL;          // break the back-link first
//         // v->reversed = NULL;

//         free(v);
//     }

//     free(b);
// }

// void free_skeleton(Skeleton* skel) {
//     if (!skel) return;

//     // Free ridges once
//     for (int i = 0; i < skel->count; ++i) {
//         SkeletonMinutia* m = skel->minutiae[i];
//         if (!m) continue;
//         for (int j = 0; j < m->ridge_count; ++j) {
//             printf("\nMinutia %d, Ridge %d: Freeing ridge at %p\n", i, j, (void*)m->ridges[j]);
//             destroy_ridge_once(m->ridges[j]);
//             m->ridges[j] = NULL; // optional: avoid accidental reuse
//         }
//     }

//     // Free minutiae (just the arrays + structs)
//     for (int i = 0; i < skel->count; ++i) {
//         SkeletonMinutia* m = skel->minutiae[i];
//         if (!m) continue;
//         free(m->ridges);
//         free(m);
//         skel->minutiae[i] = NULL;
//     }

//     free(skel->minutiae);
//     free(skel);
// }


// typedef struct {
//     int key;
//     IndexedEdgeList* value;
// } SortedEntry;

// // Comparison function for qsort
// int compare_keys(const void* a, const void* b) {
//     const SortedEntry* ea = (const SortedEntry*)a;
//     const SortedEntry* eb = (const SortedEntry*)b;
//     return ea->key - eb->key;
// }

// void print_edge_hash_map(EdgeHashMap* map) {
//     // printf("EdgeHashMap contents:\n");
//     // if (kh_size(map) == 0) {
//     //     printf("  (empty)\n");
//     //     return;
//     // }
//     // for (khiter_t k = kh_begin(map); k != kh_end(map); ++k) {
//     //     printf("Key: %d\n", kh_key(map, k));
//     //     if (kh_exist(map, k)) {
//     //         int hash = kh_key(map, k);
//     //         IndexedEdgeList* list = kh_value(map, k);

//     //         printf("Hash: %d\n", hash);
//     //         for (int i = 0; i < list->size; ++i) {
//     //             IndexedEdge* edge = &list->data[i];
//     //             printf("  → Ref: %d, Nbr: %d, Distance: %d, RefAngle: %.2f, NbrAngle: %.2f\n",
//     //                    edge->reference,
//     //                    edge->neighbor,
//     //                    edge->shape->length,
//     //                    edge->shape->referenceAngle,
//     //                    edge->shape->neighborAngle);
//     //         }
//     //     }
//     // }

//     int count = 0;
//     // First count entries
//     for (khiter_t k = kh_begin(map); k != kh_end(map); ++k) {
//         if (kh_exist(map, k)) count++;
//     }

//     // Allocate array for sorting
//     SortedEntry* entries = malloc(count * sizeof(SortedEntry));
//     int i = 0;

//     // Fill the array
//     for (khiter_t k = kh_begin(map); k != kh_end(map); ++k) {
//         if (kh_exist(map, k)) {
//             entries[i].key = kh_key(map, k);
//             entries[i].value = kh_value(map, k);
//             i++;
//         }
//     }

//     // Sort the entries by key
//     qsort(entries, count, sizeof(SortedEntry), compare_keys);

//     // FILE *file = fopen("hash_map_C.txt", "w");

//     // fprintf(file, "EdgeHashMap - Size of keys: %d\n", count);
//     // // Print sorted
//     // for (int j = 0; j < count; ++j) {
//     //     int hash = entries[j].key;
//     //     IndexedEdgeList* list = entries[j].value;

//     //     fprintf(file, "Hash: %d\n", hash);
//     //     for (int i = 0; i < list->size; ++i) {
//     //         IndexedEdge* edge = &list->data[i];
//     //         fprintf(file, "  → Ref: %d, Nbr: %d, Distance: %d, RefAngle: %.3f, NbrAngle: %.3f\n",
//     //                edge->reference,
//     //                edge->neighbor,
//     //                edge->shape->length,
//     //                edge->shape->referenceAngle,
//     //                edge->shape->neighborAngle);
//     //     }
//     // }

//     // fclose(file);

//     free(entries);
// }

// /////////// Probe ///////////////
// // Placeholder EMPTY template (define properly)
// SearchTemplate EMPTY_SearchTemplate = {0};

// // ----- Probe struct -----
// typedef struct {
//     SearchTemplate template;
//     EdgeHashMap* hash;
// } Probe;

// // ----- NULL static instance -----
// Probe Probe_NULL;

// void Probe_init_null() {
//     Probe_NULL.template = EMPTY_SearchTemplate;
//     Probe_NULL.hash = kh_init(edge_map);  // Initializes empty hash map
// }

// // ----- Constructor with parameters -----
// void Probe_init(Probe* probe, const SearchTemplate* template, EdgeHashMap* edgeHash) {
//     memcpy(&probe->template, template, sizeof(SearchTemplate));
//     probe->hash = edgeHash;
// }

// static inline void Probe_destroy(Probe* p, int free_hash) {
//     if (!p) return;
//     if (free_hash && p->hash) {
//         // EdgeHashMap_free(p->hash);
//         p->hash = NULL;
//     }
//     // DO NOT free p->templ here unless Probe owns it.
//     free(p);
// }

// #define MEMORY_ESTIMATES_REFERENCE 4
// #define INT_BYTES sizeof(int)

// // // ----- Memory estimator -----
// // int Probe_memory(const Probe* probe) {
// //     int size = 0;
// //     MemoryEstimates* m = (MemoryEstimates*)(malloc(sizeof(MemoryEstimates)));

// //     size += memory_estimates_object(m, 2 * MEMORY_ESTIMATES_REFERENCE, MEMORY_ESTIMATES_REFERENCE); // 'object(2ref, 1ref)'
// //     size += SearchTemplate_memory(&probe->template);

// //     size += memory_estimates_object(m, 10 * MEMORY_ESTIMATES_REFERENCE, MEMORY_ESTIMATES_REFERENCE);
// //     int hash_size = kh_size(probe->hash);
// //     size += memory_estimates_array(m, INT_BYTES, hash_size * 3 / 2);
// //     size += memory_estimates_array(m, MEMORY_ESTIMATES_REFERENCE, hash_size * 3 / 2);

// //     for (khiter_t k = kh_begin(probe->hash); k != kh_end(probe->hash); ++k) {
// //         if (!kh_exist(probe->hash, k)) continue;
// //         IndexedEdgeList* list = kh_value(probe->hash, k);
// //         int list_size = list->size;

// //         size += memory_estimates_object(m, INT_BYTES + MEMORY_ESTIMATES_REFERENCE, MEMORY_ESTIMATES_REFERENCE);
// //         size += memory_estimates_array(m, MEMORY_ESTIMATES_REFERENCE, list_size * 3 / 2 > 10 ? list_size * 3 / 2 : 10);
// //         size += list_size * IndexedEdge_memory();
// //     }

// //     return size;
// // }

// ////////// Match /////////////

// /// MInutiaPair ////
// typedef struct MinutiaPair {
//     int probe;
//     int candidate;
//     int probeRef;
//     int candidateRef;
//     int distance;
//     int supportingEdges;
// } MinutiaPair;

// // To string representation (similar to Java's toString)
// void minutia_pair_to_string(const MinutiaPair* pair, char* buffer, size_t buffer_size) {
//     snprintf(buffer, buffer_size, "%d<->%d @ %d<->%d #%d",
//              pair->probe, pair->candidate,
//              pair->probeRef, pair->candidateRef,
//              pair->supportingEdges);
// }

// /// MinutiaPairPool ////
// typedef struct MinutiaPairPool{
//     MinutiaPair** pool;
//     int pooled;
//     int capacity;
// } MinutiaPairPool;

// MinutiaPairPool* create_minutia_pair_pool() {
//     MinutiaPairPool* pool = malloc(sizeof(MinutiaPairPool));
//     pool->capacity = 1;
//     pool->pooled = 0;
//     pool->pool = malloc(pool->capacity * sizeof(MinutiaPair*));
//     return pool;
// }

// MinutiaPair* allocate_minutia_pair(MinutiaPairPool* pool) {
//     if (pool->pooled > 0) {
//         // printf("pool->pooled>0: pool->pooled = %d, pool->capacity = %d\n", pool->pooled, pool->capacity);
//         MinutiaPair* pair = pool->pool[--pool->pooled];  // Pop from pool
//         pool->pool[pool->pooled] = NULL;  // Clear reference
//         return pair;  // Reuse existing pair
//     } else {
//         // printf("pool->pooled = %d, pool->capacity = %d\n", pool->pooled, pool->capacity);
//         MinutiaPair* new_pair = calloc(1, sizeof(MinutiaPair));  // New zero-initialized
//         return new_pair;
//     }
// }

// void release_minutia_pair(MinutiaPairPool* pool, MinutiaPair* pair) {
//     // printf("In release_minutia_pair: pool->pooled = %d, pool->capacity = %d\n", pool->pooled, pool->capacity);
//     // printf("pair: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d, supportingEdges=%d\n",pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance, pair->supportingEdges);
//     if (pool->pooled >= pool->capacity) {
//         // float the pool capacity
//         pool->capacity *= 2;
//         // pool->capacity = pool->capacity * 3 / 2 + 1; // Grow by 1.5x
//         pool->pool = realloc(pool->pool, pool->capacity * sizeof(MinutiaPair*));
//     }
//     // Reset the fields
//     memset(pair, 0, sizeof(MinutiaPair));
//     pool->pool[pool->pooled++] = pair;
//     //printf("MinutiaPair released and added back to pool. New pool size: %d\n", pool->pooled);
// }

// void free_minutia_pair_pool(MinutiaPairPool* pool) {
//     for (int i = 0; i < pool->pooled; ++i) {
//         free(pool->pool[i]);
//     }
//     free(pool->pool);
//     free(pool);
// }

// ///// RootList /////

// #define MAX_TRIED_ROOTS 70  // Replace with Parameters.MAX_TRIED_ROOTS if defined
// KHASH_INIT(intset, int, int, 0, kh_int_hash_func, kh_int_hash_equal)
// typedef khash_t(intset) IntSet;

// typedef struct {
//     MinutiaPairPool* pool;
//     int count;
//     MinutiaPair* pairs[MAX_TRIED_ROOTS];
//     khash_t(intset)* duplicates;
// } RootList;

// void RootList_init(RootList** list, MinutiaPairPool* pool) {
//     *list = (RootList*)malloc(sizeof(RootList));
//     (*list)->pool = pool;
//     (*list)->count = 0;
//     memset((*list)->pairs, 0, sizeof((*list)->pairs));
//     (*list)->duplicates = kh_init(intset);
// }

// void RootList_add(RootList* list, MinutiaPair* pair) {
//     if (list->count < MAX_TRIED_ROOTS) {
//         list->pairs[list->count++] = pair;
//     }
// }

// void release_minutia_pair(MinutiaPairPool* pool, MinutiaPair* pair);  // assume implemented

// void RootList_discard(RootList* list) {
//     for (int i = 0; i < list->count; ++i) {
//         release_minutia_pair(list->pool, list->pairs[i]);
//         list->pairs[i] = NULL;
//     }
//     list->count = 0;
//     kh_clear(intset, list->duplicates);
// }

// void RootList_destroy(RootList* list) {
//     RootList_discard(list);
//     kh_destroy(intset, list->duplicates);
// }

// ////// RootENumerator ///////
// void RootEnumerator_enumerate(Probe* probe, const SearchTemplate* candidate, RootList* roots) {
//     // printf("Inside RootEnumerator_enumerate: roots->pooled = %d, roots->capacity = %d\n", roots->pool->pooled, roots->pool->capacity);
//     // cminutiae are list of minutiae in the candidate template
//     const SearchMinutia* cminutiae = candidate->minutiae;
//     int minutia_count = candidate->minutiae_count;
//     // lookups is counter ot limit number of hash lookups
//     int lookups = 0;
//     // counter to limit number of potential roots tried
//     int tried = 0;

//     // Two passes:
//     // shortEdges = 0: long edges (length ≥ MIN_ROOT_EDGE_LENGTH)
//     // shortEdges = 1: short edges (length < MIN_ROOT_EDGE_LENGTH)
//     // Purpose: try more reliable long edges first.
//     for (int shortEdges = 0; shortEdges <= 1; ++shortEdges) {
//         printf("shortEdges = %d\n", shortEdges);

//         // Loops generate diverse edge pairs:
//         // creference: the reference minutia
//         // cneighbor: the neighbor minutia
//         // Not all pairs are tested
//         for (int period = 1; period < minutia_count; ++period) {
//             printf("period = %d\n", period);
//             for (int phase = 0; phase <= period; ++phase) {
//                 printf("phase = %d\n", phase);
//                 for (int creference = phase; creference < minutia_count; creference += period + 1) {
//                     printf("creference = %d\n", creference);
//                     int cneighbor = (creference + period) % minutia_count;

//                     EdgeShape* cedge = create_edge_shape(cminutiae[creference], cminutiae[cneighbor]);

//                     // Build the edge (angle, length, etc.).
//                     // Only proceed if the edge fits the current pass (long/short) using XOR:
//                     // If shortEdges = 0, accept only long edges.
//                     // If shortEdges = 1, accept only short edges.
//                     if ((cedge->length >= MIN_ROOT_EDGE_LENGTH) ^ shortEdges) {
//                         // generate hash for this edge
//                         int hash = hash_edge_shape(cedge);

//                         // Lookup in hash table
//                         // Try to find that hash in the probe hash table (map from int hash → list of probe edges(IndexedEdgeList*)).
//                         EdgeHashMap* map = probe->hash;
//                         khiter_t k = kh_get(edge_map, map, hash);

//                         // If hash of this exists in probe hash table, get list of all other edges in probe with same hash
//                         if (k != kh_end(map)) {
//                             IndexedEdgeList* matches = kh_val(map, k);

//                             for (int i = 0; i < matches->size; ++i) {
//                                 IndexedEdge* match = &matches->data[i];
//                                 printf("match reference = %d, neighbor = %d\n", match->reference, match->neighbor);
//                                 printf("match length = %d, referenceAngle = %.2f, neighborAngle = %.2f\n",
//                                        match->shape->length, match->shape->referenceAngle, match->shape->neighborAngle);

//                                 // Check if edge shapes match despite same hash
//                                 if (matching(*(match->shape), *cedge)) {
//                                     // Construct a unique duplicateKey from the current probe and candidate indices.
//                                     // Use roots->duplicates (a khash_t(intset)) to avoid repeating the same pair.
//                                     int duplicateKey = (match->reference << 16) | creference;

//                                     khash_t(intset)* set = roots->duplicates;
//                                     if (!set) {
//                                         fprintf(stderr, "roots->duplicates is NULL!\n");
//                                         exit(1);
//                                     }

//                                     int ret;
//                                     khiter_t k = kh_put(intset, set, duplicateKey, &ret);
//                                     if (ret < 0) { // insertion failed (likely OOM)
//                                         fprintf(stderr, "kh_put failed (OOM?)\n");
//                                         exit(1);
//                                     }

//                                     if (ret > 0) { // newly added -> equivalent to roots.duplicates.add(...) == true
//                                         printf("duplicateKey = %d\n", duplicateKey);

//                                         MinutiaPair* pair = allocate_minutia_pair(roots->pool);
//                                         pair->probe = match->reference;
//                                         pair->candidate = creference;
//                                         RootList_add(roots, pair);
//                                     }

//                                     // Stop if too many roots have been tried
//                                     ++tried;
//                                     if (tried >= MAX_TRIED_ROOTS)
//                                         return;
//                                     // printf("duplicateKey = %d\n", duplicateKey);

//                                     // khash_t(intset)* set = roots->duplicates;

//                                     // if (!set) {
//                                     //     printf("roots->duplicates is NULL!\n");
//                                     //     exit(1);
//                                     // }

//                                     // khiter_t k = kh_get(intset, set, duplicateKey);
//                                     // if (k == kh_end(set)) {
//                                     //     int ret;
//                                     //     // Insert the newly unique duplicateKey into the set
//                                     //     k = kh_put(intset, set, duplicateKey, &ret);
//                                     //     if (ret == -1) {
//                                     //         printf("kh_put failed (OOM?)\n");
//                                     //         exit(1);
//                                     //     }

//                                     //     // kh_val(set, k) = 1; // mark key as present

//                                     //     // Create a new MinutiaPair and add it to the roots list
//                                     //     MinutiaPair* pair = allocate_minutia_pair(roots->pool);
//                                     //     pair->probe = match->reference;
//                                     //     pair->candidate = creference;
//                                     //     RootList_add(roots, pair);
//                                     // }

//                                     // // Stop if too many roots have been tried
//                                     // ++tried;
//                                     // if (tried >= MAX_TRIED_ROOTS)
//                                     //     return;
//                                 }
//                             }
//                         }

//                         // Stop if too many lookups have been performed
//                         ++lookups;
//                         if (lookups >= MAX_ROOT_EDGE_LOOKUPS)
//                             return;
//                     }
//                 }
//             }
//         }
//     }
// }

// ///// PairingGraph //////

// typedef struct {
//     MinutiaPairPool* pool;
//     int count;

//     MinutiaPair** tree; int tree_length;
//     MinutiaPair** byProbe; int byProbe_length;
//     MinutiaPair** byCandidate; int byCandidate_length;

//     MinutiaPair** support;
//     int support_size;
//     int support_capacity;

//     bool support_enabled;
// } PairingGraph;

// #define INITIAL_CAPACITY 1

// PairingGraph* create_pairing_graph(MinutiaPairPool* pool) {
//     PairingGraph* graph = calloc(1, sizeof(PairingGraph));
//     graph->pool = pool;
//     graph->tree = calloc(INITIAL_CAPACITY, sizeof(MinutiaPair*));
//     graph->byProbe = calloc(INITIAL_CAPACITY, sizeof(MinutiaPair*));
//     graph->byCandidate = calloc(INITIAL_CAPACITY, sizeof(MinutiaPair*));
//     graph->support = NULL;
//     graph->support_size = 0;
//     graph->support_capacity = 0;
//     graph->support_enabled = false;
//     graph->tree_length = 1;
//     graph->byCandidate_length = 1;
//     graph->byProbe_length = 1;

//     for(int i=0;i<graph->byProbe_length;i++)
//     {
//         graph->byProbe[i] = NULL;
//     }

//     for(int i=0;i<graph->byCandidate_length;i++)
//     {
//         graph->byCandidate[i] = NULL;
//     }
    
//     return graph;
// }

// void reserve_probe(PairingGraph* graph, const Probe* probe) {
//     int capacity = probe->template.minutiae_count;
//     if (capacity > graph->tree_length) {
//         graph->tree = realloc(graph->tree, capacity * sizeof(MinutiaPair*));
//         graph->byProbe = realloc(graph->byProbe, capacity * sizeof(MinutiaPair*));
//         for(int i=0;i<capacity;i++)
//         {
//             graph->byProbe[i] = NULL; // Initialize to NULL
//         }
//         graph->tree_length = capacity;
//         graph->byProbe_length = capacity;
//     }
// }

// void reserve_candidate(PairingGraph* graph, const SearchTemplate* candidate) {
//     int capacity = candidate->minutiae_count;
//     if (capacity > graph->byCandidate_length) {
//         graph->byCandidate = realloc(graph->byCandidate, capacity * sizeof(MinutiaPair*));
//         for(int i=0;i<capacity;i++)
//         {
//             graph->byCandidate[i] = NULL; // Initialize to NULL
//         }
//         graph->byCandidate_length = capacity;
//     }
// }

// void add_pair(PairingGraph* graph, MinutiaPair* pair) {
//     printf("In add_pair - adding edge: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
//            pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);
//     graph->tree[graph->count] = pair;
//     graph->byProbe[pair->probe] = pair;
//     graph->byCandidate[pair->candidate] = pair;
//     graph->count++;
// }

// void support_pair(PairingGraph* graph, MinutiaPair* pair) {
//     printf("In support - supporting edge: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
//            pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);
//     printf("supportEnabled = %d\n", graph->support_enabled);
//     MinutiaPair* existing = graph->byProbe[pair->probe];
//     if (existing && existing->candidate == pair->candidate) {
//         existing->supportingEdges++;
//         graph->byProbe[pair->probeRef]->supportingEdges++;

//         if (graph->support_enabled) {
//             if (graph->support_size == graph->support_capacity) {
//                 graph->support_capacity = graph->support_capacity > 0 ? graph->support_capacity * 2 : 8;
//                 graph->support = realloc(graph->support, graph->support_capacity * sizeof(MinutiaPair*));
//             }
//             graph->support[graph->support_size++] = pair;
//         } else {
//             release_minutia_pair(graph->pool, pair);
//         }
//     } else {
//         release_minutia_pair(graph->pool, pair);
//     }
// }

// void clear_pairing_graph(PairingGraph* graph) {
//     for (int i = 0; i < graph->count; ++i) {
//         MinutiaPair* pair = graph->tree[i];
//         graph->byProbe[pair->probe] = NULL;
//         graph->byCandidate[pair->candidate] = NULL;

//         if (i > 0)
//             release_minutia_pair(graph->pool, pair);
//         else
//             pair->supportingEdges = 0;

//         graph->tree[i] = NULL;
//     }

//     graph->count = 0;
//     graph->byCandidate_length=0;
//     graph->byProbe_length=0;
//     graph->tree_length = 0;

//     if (graph->support_enabled) {
//         for (int i = 0; i < graph->support_size; ++i) {
//             release_minutia_pair(graph->pool, graph->support[i]);
//         }
//         graph->support_size = 0;
//     }
// }

// void free_pairing_graph(PairingGraph* graph) {
//     free(graph->tree);
//     free(graph->byProbe);
//     free(graph->byCandidate);
//     free(graph->support);
//     free(graph);
// }

// //////////// 


// ///////// ScoringData //////////

// #define MINUTIA_SCORE 0.032
// #define MINUTIA_FRACTION_SCORE 8.98
// #define MIN_SUPPORTING_EDGES 1
// #define SUPPORTED_MINUTIA_SCORE 0.193
// #define EDGE_SCORE 0.265
// #define MINUTIA_TYPE_SCORE 0.629
// #define DISTANCE_ERROR_FLATNESS 0.69
// #define ANGLE_ERROR_FLATNESS 0.27
// #define DISTANCE_ACCURACY_SCORE 9.9
// #define ANGLE_ACCURACY_SCORE 2.79

// #define THRESHOLD_FMR_MAX  8.48
// #define THRESHOLD_FMR_2 11.12
// #define THRESHOLD_FMR_10 14.15
// #define THRESHOLD_FMR_100 18.22
// #define THRESHOLD_FMR_1000 22.39
// #define THRESHOLD_FMR_10_000 27.24
// #define THRESHOLD_FMR_100_000 32.01


// typedef struct {
// 	int minutiaCount;
// 	float minutiaScore;
// 	float minutiaFractionInProbe;
// 	float minutiaFractionInCandidate;
// 	float minutiaFraction;
// 	float minutiaFractionScore;
// 	int supportingEdgeSum;
// 	int edgeCount;
// 	float edgeScore;
// 	int supportedMinutiaCount;
// 	float supportedMinutiaScore;
// 	int minutiaTypeHits;
// 	float minutiaTypeScore;
// 	int distanceErrorSum;
// 	int distanceAccuracySum;
// 	float distanceAccuracyScore;
// 	float angleErrorSum;
// 	float angleAccuracySum;
// 	float angleAccuracyScore;
// 	float totalScore;
// 	float shapedScore;
// } ScoringData;

// float scoring_interpolate(float raw, float min, float max, float start, float length) {
//     return (raw - min) / (max - min) * length + start;
// }

// float shape(float raw) {
//     if (raw < THRESHOLD_FMR_MAX)
//         return 0;
//     if (raw < THRESHOLD_FMR_2)
//         return scoring_interpolate(raw, THRESHOLD_FMR_MAX, THRESHOLD_FMR_2, 0, 3);
//     if (raw < THRESHOLD_FMR_10)
//         return scoring_interpolate(raw, THRESHOLD_FMR_2, THRESHOLD_FMR_10, 3, 7);
//     if (raw < THRESHOLD_FMR_100)
//         return scoring_interpolate(raw, THRESHOLD_FMR_10, THRESHOLD_FMR_100, 10, 10);
//     if (raw < THRESHOLD_FMR_1000)
//         return scoring_interpolate(raw, THRESHOLD_FMR_100, THRESHOLD_FMR_1000, 20, 10);
//     if (raw < THRESHOLD_FMR_10_000)
//         return scoring_interpolate(raw, THRESHOLD_FMR_1000, THRESHOLD_FMR_10_000, 30, 10);
//     if (raw < THRESHOLD_FMR_100_000)
//         return scoring_interpolate(raw, THRESHOLD_FMR_10_000, THRESHOLD_FMR_100_000, 40, 10);
//     return (raw - THRESHOLD_FMR_100_000) / (THRESHOLD_FMR_100_000 - THRESHOLD_FMR_100) * 30 + 50;
// }

// int find_max(int a, int b) {
//     return (a > b) ? a : b;
// }

// float find_max_f(float a, float b) {
//     return (a > b) ? a : b;
// }

// void compute_score(const SearchTemplate* probe, const SearchTemplate* candidate, const PairingGraph* pairing, ScoringData* score) {
//     const SearchMinutia* pminutiae = probe->minutiae;
//     const SearchMinutia* cminutiae = candidate->minutiae;

//     score->minutiaCount = pairing->count;
//     score->minutiaScore = MINUTIA_SCORE * score->minutiaCount;
//     score->minutiaFractionInProbe = (float)pairing->count / probe->minutiae_count;
//     score->minutiaFractionInCandidate = (float)pairing->count / candidate->minutiae_count;
//     score->minutiaFraction = 0.5 * (score->minutiaFractionInProbe + score->minutiaFractionInCandidate);
//     score->minutiaFractionScore = MINUTIA_FRACTION_SCORE * score->minutiaFraction;
//     score->supportingEdgeSum = 0;
//     score->supportedMinutiaCount = 0;
//     score->minutiaTypeHits = 0;

//     for (int i = 0; i < pairing->count; ++i) {
//         MinutiaPair* pair = pairing->tree[i];
//         score->supportingEdgeSum += pair->supportingEdges;
//         if (pair->supportingEdges >= MIN_SUPPORTING_EDGES)
//             ++score->supportedMinutiaCount;
//         if (pminutiae[pair->probe].type == cminutiae[pair->candidate].type)
//             ++score->minutiaTypeHits;
//     }

//     score->edgeCount = pairing->count + score->supportingEdgeSum;
//     score->edgeScore = EDGE_SCORE * score->edgeCount;
//     score->supportedMinutiaScore = SUPPORTED_MINUTIA_SCORE * score->supportedMinutiaCount;
//     score->minutiaTypeScore = MINUTIA_TYPE_SCORE * score->minutiaTypeHits;

//     int innerDistanceRadius = (int)java_round(DISTANCE_ERROR_FLATNESS * MAX_DISTANCE_ERROR);
//     float innerAngleRadius = (float)(ANGLE_ERROR_FLATNESS * MAX_ANGLE_ERROR);

//     score->distanceErrorSum = 0;
//     score->angleErrorSum = 0;

//     for (int i = 1; i < pairing->count; ++i) {
//         MinutiaPair* pair = pairing->tree[i];
//         EdgeShape* probeEdge = create_edge_shape(pminutiae[pair->probeRef], pminutiae[pair->probe]);
//         EdgeShape* candidateEdge = create_edge_shape(cminutiae[pair->candidateRef], cminutiae[pair->candidate]);

//         printf("innerAngleRadius: %.3f\n",innerAngleRadius);
//         printf("probeEdge.referenceAngle: %.3f, candidateEdge.referenceAngle: %.3f\n",
//                probeEdge->referenceAngle, candidateEdge->referenceAngle);
//         printf("probeEdge.neighborAngle: %.3f, candidateEdge.neighborAngle: %.3f\n",
//                probeEdge->neighborAngle, candidateEdge->neighborAngle);

//         score->distanceErrorSum += find_max(innerDistanceRadius, abs(probeEdge->length - candidateEdge->length));
        
//         float f1 = float_angle_distance(probeEdge->referenceAngle, candidateEdge->referenceAngle);
//         score->angleErrorSum += find_max_f(innerAngleRadius, f1);
//         printf("First angleErrorSum: %.3f\n", score->angleErrorSum);
//         float f2 = float_angle_distance(probeEdge->neighborAngle, candidateEdge->neighborAngle);
//         score->angleErrorSum += find_max_f(innerAngleRadius, f2);
//         printf("Second angleErrorSum: %.3f\n", score->angleErrorSum);
//     }

//     int distanceErrorPotential = MAX_DISTANCE_ERROR * find_max(0, pairing->count - 1);
//     score->distanceAccuracySum = distanceErrorPotential - score->distanceErrorSum;
//     score->distanceAccuracyScore = DISTANCE_ACCURACY_SCORE * (distanceErrorPotential > 0 ? (float)score->distanceAccuracySum / distanceErrorPotential : 0);

//     float angleErrorPotential = MAX_ANGLE_ERROR * find_max(0, pairing->count - 1) * 2;
//     score->angleAccuracySum = angleErrorPotential - score->angleErrorSum;
//     score->angleAccuracyScore = ANGLE_ACCURACY_SCORE * (angleErrorPotential > 0 ? score->angleAccuracySum / angleErrorPotential : 0);

//     score->totalScore = score->minutiaScore +
//                         score->minutiaFractionScore +
//                         score->supportedMinutiaScore +
//                         score->edgeScore +
//                         score->minutiaTypeScore +
//                         score->distanceAccuracyScore +
//                         score->angleAccuracyScore;

//     score->shapedScore = shape(score->totalScore);

//     printf("score->minutiaCount = %d\n", score->minutiaCount);
//     printf("score->minutiaScore = %.3f\n", score->minutiaScore);
//     printf("score->minutiaFractionInProbe = %.3f\n", score->minutiaFractionInProbe);
//     printf("score->minutiaFractionInCandidate = %.3f\n", score->minutiaFractionInCandidate);
//     printf("score->minutiaFraction = %.3f\n", score->minutiaFraction);
//     printf("score->minutiaFractionScore = %.3f\n", score->minutiaFractionScore);
//     printf("score->supportingEdgeSum = %d\n", score->supportingEdgeSum);
//     printf("score->supportedMinutiaCount = %d\n", score->supportedMinutiaCount);
//     printf("score->supportedMinutiaScore = %.3f\n", score->supportedMinutiaScore);
//     printf("score->edgeCount = %d\n", score->edgeCount);
//     printf("score->edgeScore = %.3f\n", score->edgeScore);
//     printf("score->minutiaTypeHits = %d\n", score->minutiaTypeHits);
//     printf("score->minutiaTypeScore = %.3f\n", score->minutiaTypeScore);
//     printf("score->distanceErrorSum = %d\n", score->distanceErrorSum);
//     printf("score->angleErrorSum = %.3f\n", score->angleErrorSum);
//     printf("score->distanceAccuracySum = %d\n", score->distanceAccuracySum);
//     printf("score->distanceAccuracyScore = %.3f\n", score->distanceAccuracyScore);
//     printf("score->angleAccuracySum = %.3f\n", score->angleAccuracySum);
//     printf("score->angleAccuracyScore = %.3f\n", score->angleAccuracyScore);
//     printf("score->totalScore = %.3f\n", score->totalScore);
//     printf("score->shapedScore = %.3f\n", score->shapedScore);

// }

// ///// PriorityQueue /////

// typedef struct {
//     MinutiaPair** data;
//     int size;
//     int capacity;
// } MinutiaPairQueue;

// void swap(MinutiaPair** a, MinutiaPair** b) {
//     MinutiaPair* tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// void heapify_up(MinutiaPairQueue* q, int index) {
//     while (index > 0) {
//         int parent = (index - 1) / 2;
//         if (q->data[parent]->distance <= q->data[index]->distance)
//             break;
//         swap(&q->data[parent], &q->data[index]);
//         index = parent;
//     }
// }

// void heapify_down(MinutiaPairQueue* q, int index) {
//     while (1) {
//         int smallest = index;
//         int left = 2 * index + 1;
//         int right = 2 * index + 2;

//         if (left < q->size && q->data[left]->distance < q->data[smallest]->distance)
//             smallest = left;
//         if (right < q->size && q->data[right]->distance < q->data[smallest]->distance)
//             smallest = right;

//         if (smallest == index)
//             break;

//         swap(&q->data[index], &q->data[smallest]);
//         index = smallest;
//     }
// }

// MinutiaPairQueue* queue_create(int capacity) {
//     MinutiaPairQueue* q = malloc(sizeof(MinutiaPairQueue));
//     q->data = malloc(capacity * sizeof(MinutiaPair*));
//     q->size = 0;
//     q->capacity = capacity;
//     return q;
// }

// void queue_push(MinutiaPairQueue* q, MinutiaPair* pair) {
//     if (q->size >= q->capacity) {
//         q->capacity *= 2;
//         // q->capacity = q->capacity * 3 / 2 + 1; // Grow by 1.5x
//         q->data = realloc(q->data, q->capacity * sizeof(MinutiaPair*));
//     }
//     q->data[q->size] = pair;
//     heapify_up(q, q->size);
//     q->size++;
// }

// MinutiaPair* queue_pop(MinutiaPairQueue* q) {
//     if (q->size == 0)
//         return NULL;

//     MinutiaPair* top = q->data[0];
//     q->data[0] = q->data[--q->size];
//     heapify_down(q, 0);
//     return top;
// }

// int queue_empty(MinutiaPairQueue* q) {
//     return q->size == 0;
// }

// // void queue_free(MinutiaPairQueue* q) {
// //     free(q->data);
// //     free(q);
// // }

// ///// MatcherThread ////////

// typedef struct MatcherThread {
//     MinutiaPairPool* pool;
//     RootList* roots;
//     PairingGraph* pairing;
//     MinutiaPairQueue* queue; // Min-heap for MinutiaPair*
//     ScoringData* score;
// } MatcherThread;

// // Singleton for now, not real thread-local yet


// MatcherThread* matcher_thread_current(MatcherThread* thread_instance) {
//     // if (!thread_instance) {
//         thread_instance->pool = create_minutia_pair_pool(); 
//         RootList_init(&thread_instance->roots, thread_instance->pool);

//         thread_instance->pairing = create_pairing_graph(thread_instance->pool);

//         thread_instance->queue = queue_create(16); // This is your MinutiaPairQueue*
//         thread_instance->score = (ScoringData*)malloc(sizeof(ScoringData));
//     // }
//     return thread_instance;
// }

// void matcher_thread_kill(MatcherThread* thread_instance) {
//     if (!thread_instance)
//         return;

//     // Free queue
//     if (thread_instance->queue) {
//         // If queue holds dynamically allocated MinutiaPair*, free them
//         for (int i = 0; i < thread_instance->queue->size; ++i) {
//             free(thread_instance->queue->data[i]);
//         }
//         free(thread_instance->queue->data);
//         free(thread_instance->queue);
//     }

//     // Free pairing graph
//     if (thread_instance->pairing) {
//         free(thread_instance->pairing->tree); // assuming this is malloc'd
//         free(thread_instance->pairing->byProbe); // assuming this is malloc'd
//         free(thread_instance->pairing->byCandidate); // assuming this is malloc'd
//         free(thread_instance->pairing);
//     }

//     // Free minutia pair po
//     // Free pool
//     if (thread_instance->pool) {
//         free(thread_instance->pool);
//     }

//     // Free score
//     free(thread_instance->score);

//     // Finally free the thread object
//     free(thread_instance);
//     thread_instance = NULL;
// }

// //////// EdgeSpider //////////
// // Match pairs

// #define COMPLEMENTARY_MAX_ANGLE_ERROR complementary(MAX_ANGLE_ERROR)

// MinutiaPair** match_pairs(NeighborEdge* pstar, int pcount, NeighborEdge* cstar, int ccount, MinutiaPairPool* pool, int* out_count) {
//     MinutiaPair** results = malloc(sizeof(MinutiaPair*) * (pcount * ccount));
//     int result_count = 0;

//     int start = 0;
//     int end = 0;
//     for (int cindex = 0; cindex < ccount; ++cindex) {
//         NeighborEdge cedge = cstar[cindex];
//         printf("start: %d, end: %d, cedge.length: %d, cedge.referenceAngle: %.2f\n",
//                start, end, cedge.shape->length, cedge.shape->referenceAngle);

//         while (start < pcount && pstar[start].shape->length < cedge.shape->length - MAX_DISTANCE_ERROR)
//             ++start;
//         if (end < start)
//             end = start;
        
//         printf("start: %d, end: %d\n", start, end);
//         printf("pstar: \n");
//         for (int i = start; i < pcount; ++i) {
//             printf("pstar[%d]: length = %d, referenceAngle = %.2f, neighborAngle = %.2f\n",
//                    i, pstar[i].shape->length,pstar[i].shape->referenceAngle, pstar[i].shape->neighborAngle);
        
//         }

//         while (end < pcount && pstar[end].shape->length <= cedge.shape->length + MAX_DISTANCE_ERROR)
//             ++end;

//         for (int pindex = start; pindex < end; ++pindex) {
//             NeighborEdge pedge = pstar[pindex];
//             float rdiff = float_angle_difference(pedge.shape->referenceAngle, cedge.shape->referenceAngle);

//             if (rdiff <= MAX_ANGLE_ERROR || rdiff >= COMPLEMENTARY_MAX_ANGLE_ERROR) {
//                 float ndiff = float_angle_difference(pedge.shape->neighborAngle, cedge.shape->neighborAngle);

//                 if (ndiff <= MAX_ANGLE_ERROR || ndiff >= COMPLEMENTARY_MAX_ANGLE_ERROR) {
//                     MinutiaPair* pair = allocate_minutia_pair(pool);
//                     printf("Pair returned: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
//                            pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);
//                     pair->probe = pedge.neighbor;
//                     pair->candidate = cedge.neighbor;
//                     pair->distance = cedge.shape->length;
//                     results[result_count++] = pair;
//                     printf("Adding to results: probe=%d, candidate=%d, distance=%d\n",
//                            pair->probe, pair->candidate, pair->distance);
//                 }
//             }
//         }
//     }

//     printf("fin results: \n");
//     for (int i = 0; i < result_count; ++i) {
//         MinutiaPair* pair = results[i];
//         printf("results[%d]: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
//                i, pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);
//     }

//     *out_count = result_count;
//     return results;
// }

// void collect_edges(NeighborEdge** pedges, NeighborEdge** cedges, int* pedges_count, int* cedges_count, PairingGraph* pairing, MinutiaPairQueue* queue) {
//     MinutiaPair* reference = pairing->tree[pairing->count - 1];
//     NeighborEdge* pstar = pedges[reference->probe];
//     NeighborEdge* cstar = cedges[reference->candidate];
//     // pstar.length==pcount, cstar.length=ccount
//     int pcount = pedges_count[reference->probe];
//     int ccount = cedges_count[reference->candidate];

//     int match_count = 0;
//     MinutiaPair** matches = match_pairs(pstar, pcount, cstar, ccount, pairing->pool, &match_count);
//     // printf("Finnnn matches: \n"); // 
//     // for(int i = 0; i < match_count; ++i) {
//     //     MinutiaPair* pair = matches[i];
//     //     printf("matches[%d]: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
//     //            i, pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);
//     // }

//     for (int i = 0; i < match_count; ++i) {
//         MinutiaPair* pair = matches[i];
//         pair->probeRef = reference->probe;
//         pair->candidateRef = reference->candidate;
//         printf("---------------------- Adding pair: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
//                pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);

//         if (pairing->byCandidate[pair->candidate] == NULL && pairing->byProbe[pair->probe] == NULL) {
//             printf("Adding to queue: \n");
//             queue_push(queue, pair);
//             printf("Queue size: %d\n",queue->size);
//         } else {
//             support_pair(pairing, pair);
//         }
//     }
//     free(matches);
// }

// MinutiaPair* peek_pair(MinutiaPairQueue* queue) {
//     if (queue->size == 0) {
//         return NULL;
//     }
//     return queue->data[0]; // Root of min-heap
// }

// void skip_paired(PairingGraph* pairing, MinutiaPairQueue* queue) {
//     while (queue_empty(queue)== false) {
//         MinutiaPair* top = peek_pair(queue);
//         if (pairing->byCandidate[top->candidate] == NULL && pairing->byProbe[top->probe] == NULL)
//             break;
//         support_pair(pairing, queue_pop(queue));
//     }
// }

// void edge_spider_crawl(NeighborEdge** pedges, NeighborEdge** cedges, int* pedges_count, int* cedges_count, PairingGraph* pairing, MinutiaPair* root, MinutiaPairQueue* queue) {
//     queue_push(queue, root);
//     do {
//         MinutiaPair* pair = queue_pop(queue);
//         printf("probe=%d, candidate=%d, probeRef=%d\n", pair->probe, pair->candidate, pair->probeRef);
//         add_pair(pairing, pair);
//         collect_edges(pedges, cedges, pedges_count, cedges_count, pairing, queue);
//         skip_paired(pairing, queue);
//     } while (queue_empty(queue) == false);
// }

// ////// MatcherENgine ///////

// float matcher_engine_match(Probe* probe, SearchTemplate* candidate) {
//     MatcherThread* thread = (MatcherThread*)malloc(sizeof(MatcherThread));
//     matcher_thread_current(thread);
//     // printf("At start, thread->pool->pooled = %d, thread->pool->capacity = %d\n", thread->pool->pooled, thread->pool->capacity);

//     // reserve memory for probe and candidate minutiae edges
//     reserve_probe(thread->pairing, probe); 
//     reserve_candidate(thread->pairing, candidate);

//     // set supportEnabled if transparency accepts pairing
//     thread->pairing->support_enabled = false;

//     ///// Creating counts ////////
//     NeighborEdge** probe_edges = probe->template.edges;
//     NeighborEdge** candidate_edges = candidate->edges;

//     int* probe_counts = probe->template.edge_counts;
//     int* candidate_counts = candidate->edge_counts;

//     // int* probe_counts = malloc(probe->template.minutiae_count * sizeof(int));
//     // int* candidate_counts = malloc(candidate->minutiae_count * sizeof(int));

//     // for (int i = 0; i < probe->template.minutiae_count; ++i) {
//     //     probe_counts[i] = probe_edges[i]->shape->length;
//     // }
//     // for (int i = 0; i < candidate->minutiae_count; ++i) {
//     //     candidate_counts[i] = candidate_edges[i]->shape->length; // Updated to use shape->length
//     // }
//     //////////

//     // enumerate root pairs between probe and candidate
//     RootEnumerator_enumerate(probe, candidate, thread->roots);
//     printf("Root enumeration completed\n");

//     float high = 0.0;
//     int best = -1;

//     // void edge_spider_crawl(NeighborEdge** pedges, NeighborEdge** cedges, int* pedges_count, int* cedges_count, PairingGraph* pairing, MinutiaPair* root, MinutiaPairQueue* queue) {
//     for (int i = 0; i < thread->roots->count; ++i) {
//         edge_spider_crawl(
//             probe->template.edges,
//             candidate->edges,
//             probe_counts,
//             candidate_counts,
//             thread->pairing,
//             thread->roots->pairs[i],
//             thread->queue
//         );

//         compute_score(&probe->template, candidate, thread->pairing, thread->score);

//         float partial = thread->score->shapedScore;

//         if (best < 0 || partial > high) {
//             high = partial;
//             best = i;
//         }

//         clear_pairing_graph(thread->pairing);
//     }

//     if (best >= 0) {
//         thread->pairing->support_enabled = false;

//         edge_spider_crawl(
//             probe->template.edges,
//             candidate->edges,
//             probe_counts,
//             candidate_counts,
//             thread->pairing,
//             thread->roots->pairs[best],
//             thread->queue
//         );

//         compute_score(&probe->template, candidate, thread->pairing, thread->score);

//         clear_pairing_graph(thread->pairing);
//     }

//     RootList_discard(thread->roots);

//     return high;
// }


// //////////////////

// DoubleMatrix read_decoded_bytes(char* filepath)
// {
//     DoubleMatrix d;

//     FILE* file = fopen(filepath, "r");
//     if (!file) {
//         perror("fopen failed");
//         return d;
//     }

//     float* values = malloc(MAX_LINES * sizeof(float));
//     if (!values) {
//         perror("malloc failed");
//         fclose(file);
//         return d;
//     }

//     int count = 0;
//     while (fscanf(file, "%lf", &values[count]) == 1) {
//         count++;
//         if (count >= MAX_LINES) {
//             fprintf(stderr, "Exceeded max lines\n");
//             break;
//         }
//     }

//     fclose(file);

//     // Example: print first few
//     for (int i = 0; i < count; ++i) {
//         printf("Value[%d] = %f\n", i, values[i]);
//     }

//     d.width= (int)sqrt(count);
//     d.height=(int)sqrt(count);
//     d.data = (float*)malloc(d.width * d.height * sizeof(float));
    
//     for(int i=0;i<d.width;i++)
//     {
//         for(int j=0;j<d.height;j++)
//         {
//             d.data[i*d.width+j]=values[i*d.width+j];
//         }
//     }

//     free(values);


//     return d;
// }
// ////////////////////////

// #define MAX_FILES 1000

// #define PATHS_MAX 1000

// int ends_with_png(const char *filename) {
//     size_t len = strlen(filename);
//     return len >= 4 && strcmp(filename + len - 4, ".png") == 0;
// }

// int is_regular_file(const char *path) {
//     struct stat st;
//     return stat(path, &st) == 0 && S_ISREG(st.st_mode);
// }

// int compare_filenames(const void *a, const void *b) {
//     const char **fa = (const char **)a;
//     const char **fb = (const char **)b;
//     return strcmp(*fa, *fb); // Lexicographical order
// }

// int compare_strings(const void *a, const void *b) {
//     const char **sa = (const char **)a;
//     const char **sb = (const char **)b;
//     return strcmp(*sa, *sb);
// }

// // void strip_png_extension(char *filename) {
// //     size_t len = strlen(filename);
// //     if (len >= 4 && strcmp(filename + len - 4, ".png") == 0) {
// //         filename[len - 4] = '\0'; // Truncate the string
// //     }
// // }

// #define MAX_CLASSES 100
// #define MAX_CLASS_NAME 100

// typedef struct {
//     char name[MAX_CLASS_NAME];
//     float score;
// } ClassScore;

// KHASH_MAP_INIT_STR(str_dbl, float);

// void put_score(khash_t(str_dbl)* map, const char* key, float value) {
//     int ret;
//     khiter_t k = kh_put(str_dbl, map, key, &ret);  // key is copied
//     kh_value(map, k) = value;
// }

// float* get_score(khash_t(str_dbl)* map, const char* key) {
//     khiter_t k = kh_get(str_dbl, map, key);
//     if (k == kh_end(map)) return NULL;
//     return &kh_value(map, k);
// }

// // Returns pointer to last component of path
// const char* basename(const char* path) {
//     const char* base = strrchr(path, '/');
//     return base ? base + 1 : path;
// }

// char* get_class_name(char* path_copy) {
//     // Get the filename (e.g., "pixelsKshitjleftfinger_8.png")
//     char* filename = basename(path_copy);

//     // Duplicate to a temporary buffer so we can safely modify
//     char temp[256];
//     strncpy(temp, filename, sizeof(temp));
//     temp[sizeof(temp) - 1] = '\0';

//     // Remove the file extension
//     char* dot = strrchr(temp, '.');
//     if (dot) *dot = '\0';  // Now temp = "pixelsKshitjleftfinger_8"

//     // Find the last underscore and shift the digits left
//     char* underscore = strrchr(temp, '_');
//     if (underscore && *(underscore + 1)) {
//         // Move the digits after '_' over the underscore
//         memmove(underscore, underscore + 1, strlen(underscore + 1) + 1); // include null terminator
//     }

//     // Allocate and return a copy of the final result
//     return strdup(temp);  // Caller must free
// }

// typedef struct {
//     char* key;
//     float value;
// } Entry;

// int compare_entries_desc(const void* a, const void* b) {
//     float diff = ((Entry*)b)->value - ((Entry*)a)->value;
//     return (diff > 0) - (diff < 0);
// }

// void normalize_and_rank(khash_t(str_dbl)* classScores, khash_t(str_dbl)* countClass,
//                         const char* queryClass,
//                         float threshold, int* matchCount, int* passCount, int* false_positive_number) {
    
//     // Normalize each class score by its count
//     for (khiter_t k = kh_begin(classScores); k != kh_end(classScores); ++k) {
//         if (kh_exist(classScores, k)) {
//             const char* className = kh_key(classScores, k);
//             float score = kh_value(classScores, k);

//             khiter_t c = kh_get(str_dbl, countClass, className);
//             float count = (c != kh_end(countClass)) ? kh_value(countClass, c) : 1.0;

//             kh_value(classScores, k) = score / count;
//         }
//     }

//     // Create a sortable list of entries
//     int numEntries = kh_size(classScores);
//     Entry* entries = malloc(sizeof(Entry) * numEntries);
//     int index = 0;

//     for (khiter_t k = kh_begin(classScores); k != kh_end(classScores); ++k) {
//         if (kh_exist(classScores, k)) {
//             entries[index].key = kh_key(classScores, k);
//             entries[index].value = kh_value(classScores, k);
//             index++;
//         }
//     }

//     // Sort by score descending
//     qsort(entries, index, sizeof(Entry), compare_entries_desc);

//     // Print sorted entries
//     for (int i = 0; i < index; ++i) {
//         printf("Class: %s, Score: %.2f\n", entries[i].key, entries[i].value);
//     }

//     // Top match handling
//     if (index > 0) {
//         if (entries[0].value > threshold && strcmp(entries[0].key, queryClass) == 0) {
//             (*matchCount)++;
//         } else if (entries[0].value < threshold) {
//             (*passCount)++;
//         } else if (entries[0].value > threshold && strcmp(entries[0].key, queryClass) != 0) {
//             (*false_positive_number)++;
//         }

//         printf("Query: %-35s  TopMatch: %-35s  Score: %.2f  MatchCount: %d  PassCount: %d  False_positive_number: %d\n",
//             queryClass,
//             entries[0].key,
//             entries[0].value,
//             *matchCount,
//             *passCount,
//             *false_positive_number);
//     }

//     printf("--------------------------------------------------\n");

//     free(entries);
// }

// void print_stats(int matchCount, int passCount, int total) {
//     float accuracy = (float) matchCount / total;
//     float passRate = (float) passCount / total;

//     printf("\n==============================\n");
//     printf("Total images           : %d\n", total);
//     printf("Correct matches        : %d\n", matchCount);
//     printf("No-match (score < 40)  : %d\n", passCount);
//     printf("Accuracy               : %.2f%%\n", accuracy * 100);
//     printf("Pass (low-score) rate  : %.2f%%\n", passRate * 100);
// }
//  #include <errno.h>
// #include <sys/stat.h>
// #include <unistd.h>
// #include <limits.h>

// static void hexdump_tail(const char* s, size_t n) {
//     fprintf(stderr, "path tail hex: ");
//     size_t start = n > 16 ? n - 16 : 0;
//     for (size_t i = start; i < n; i++) fprintf(stderr, "%02X ", (unsigned char)s[i]);
//     fprintf(stderr, " | len=%zu\n", n);
// }

// // Pass in the errno you captured right after the failing call.
// static void diagnose_path_issue(const char* where, const char* path, int saved_errno) {
//     size_t len = strlen(path);
//     fprintf(stderr, "[%s] path='%s'\n", where, path);
//     hexdump_tail(path, len);

//     fprintf(stderr, "errno(at open)=%d (%s)\n", saved_errno, strerror(saved_errno));

//     struct stat st;
//     if (stat(path, &st) != 0) {
//         fprintf(stderr, "stat: %s (errno=%d)\n", strerror(errno), errno);
//         return;
//     }
//     fprintf(stderr, "stat: ok size=%lld mode=%o\n", (long long)st.st_size, st.st_mode & 0777);

//     if (access(path, R_OK) != 0)
//         fprintf(stderr, "access(R_OK): %s (errno=%d)\n", strerror(errno), errno);
//     else
//         fprintf(stderr, "access(R_OK): ok\n");

//     char canon[PATHS_MAX];
//     if (realpath(path, canon))
//         fprintf(stderr, "realpath: %s\n", canon);
//     else
//         fprintf(stderr, "realpath: %s (errno=%d)\n", strerror(errno), errno);
// }

// // Extract representation prefix: everything before the LAST '_' (ignores extension).
// // e.g., "pixelsKshitijleftthumb_2.png" -> "pixelsKshitijleftthumb"
// static void get_representation(const char *filename, char *out, size_t outsz) {
//     if (!filename || !out || outsz == 0) return;

//     // Make a writable copy
//     char tmp[1024];
//     strncpy(tmp, filename, sizeof(tmp) - 1);
//     tmp[sizeof(tmp) - 1] = '\0';

//     // Strip extension if present (find last '.')
//     char *dot = strrchr(tmp, '.');
//     if (dot) *dot = '\0';

//     // Find last underscore
//     char *us = strrchr(tmp, '_');
//     if (!us) {
//         // No underscore — treat the whole (no-ext) string as representation
//         strncpy(out, tmp, outsz - 1);
//         out[outsz - 1] = '\0';
//         return;
//     }

//     // Everything before the underscore is the representation
//     *us = '\0';
//     strncpy(out, tmp, outsz - 1);
//     out[outsz - 1] = '\0';
// }

// // Accumulator entry for a candidate representation
// typedef struct {
//     char rep[MAX_REP_LEN];
//     double sumScore;
//     int count;
// } RepScore;

// // Find index of representation in array; returns -1 if not found
// static int find_rep_index(RepScore *arr, int count, const char *rep) {
//     for (int i = 0; i < count; ++i) {
//         if (strcmp(arr[i].rep, rep) == 0) return i;
//     }
//     return -1;
// }

// // Extracts filename ending in .png from input string
// static void get_filename_from_log(const char *input, char *out, size_t outsz) {
//     const char *start = strrchr(input, '/');
//     if (!start) start = input;  // No slash found, use full string
//     else start++;               // Move past the '/'

//     const char *end = strstr(start, ".png");
//     if (!end) {
//         strncpy(out, start, outsz - 1);
//         out[outsz - 1] = '\0';
//         return;
//     }

//     size_t len = (size_t)(end - start) + 4; // ".png" is 4 chars
//     if (len >= outsz) len = outsz - 1;

//     strncpy(out, start, len);
//     out[len] = '\0';
// }


// int main()
// {
//     size_t size;
//     // unsigned char* data = read_all_bytes("/home/kshitij/SecurSi/read-write-data-from-uart-by-client/pixels_dir/pixelsKshitijleftindexfinger_0.png", &size);

//     // if (data != NULL) {
//     //     // Use the bytes...
//     //     free(data);
//     // }

//     // for(size_t i=0;i<size;i++)
//     // {
//     //     printf("%02x ",data[i]);
//     //     if((i+1)%16==0)
//     //     {
//     //         printf("\n");
//     //     }
//     // }

//     // DoubleMatrix decoded  = decode_image(data, size); 
//     // printf("decoded.width: %d\n", decoded.width);
//     // printf("decoded.height: %d\n", decoded.height);

//     //////////////////////////////////////////////////

//     const char *dir_path = "/home/kshitij/SecurSi/read-write-data-from-uart-by-client/test_pixels_dir";
//     // const char* dir_path = "/home/kshitij/SecurSi/read-write-data-from-uart-by-client/pixels_dir";
//     // const char *dir_path = "/home/kshitij/SecurSi/read-write-data-from-uart-by-client/check_encode_decode_png";

//     DIR *dir = opendir(dir_path);
//     if (!dir) {
//         perror("opendir failed");
//         return 1;
//     }

//     struct dirent *entry;
//     char *file_paths[MAX_FILES];
//     int count = 0;

//     while ((entry = readdir(dir)) != NULL && count < MAX_FILES) {
//         if (entry->d_type != DT_REG && entry->d_type != DT_UNKNOWN)
//             continue;

//         if (!ends_with_png(entry->d_name))
//             continue;

//         char full_path[PATHS_MAX];
//         snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

//         if (!is_regular_file(full_path))
//             continue;

//         file_paths[count] = strdup(full_path);  // store full path
//         if (!file_paths[count]) {
//             perror("strdup failed");
//             closedir(dir);
//             return 1;
//         }

//         count++;
//     }

//     closedir(dir);

//     if (count < 2) {
//         fprintf(stderr, "Need at least 2 matching images.\n");
//         return 1;
//     }

//     qsort(file_paths, count, sizeof(char *), compare_strings); // match Java sort order

//     for (int i = 0; i < count; i++) {
//         #undef printf
//         #define printf printf
//         printf("File %d: %s\n", i, file_paths[i]);
//         // // #define printf(...)
//         // free(file_paths[i]);  // cleanup
//     }

//     ////////////////////////////////////////

//     // char* path="/home/kshitij/SecurSi/read-write-data-from-uart-by-client/pixels_dir/pixelsKshitijleftindexfinger_0";
    
//     int* matchCount = (int*)malloc(sizeof(int));
//     int* passCount = (int*)malloc(sizeof(int));
//     int* false_positive_number = (int*)malloc(sizeof(int));

//     // for(int i=0;i<count;i++)
//     // {
//     //     strip_png_extension(file_paths[i]);
//     // }

//     // Open file for writing ("w" overwrites; use "a" to append)
//     FILE *file_sc = fopen("scores_file.txt", "a");
//     if (file_sc == NULL) {
//         perror("Error opening file");
//         return EXIT_FAILURE;
//     }

//     int matching = 0;
//     int false_positive = 0;
//     int passcount = 0;

//     char query_rep[MAX_REP_LEN];

//     // // Write text to file
//     // fprintf(file, "Hello, world!\n");
//     // fprintf(file, "This is another line.\n");

//     for(int i=0;i<count;i++)
//     {
//         // if(i<67)
//         //     continue;

//         // strip_png_extension(file_paths[i]);

//         // Restore printf only for one case
//         #undef printf
//         #define printf printf
//         printf("Image i: %d; \n", i);
//         // // // #define printf(...)
        
//         // unsigned char* png = NULL; size_t pnglen = 0;
//         // unsigned err = lodepng_load_file(&png, &pnglen, file_paths[i]);
//         // if (err) { 
//         //     #undef printf
//         //     #define printf printf
//         //     printf("load err=%u\n", err);
//         //     printf("load err=%u (%s) for %s\n", err, lodepng_error_text(err), file_paths[i]);
//         //     // // #define printf(...)
//         //     i--; continue; 
//         // }
//         // inspect_png_chunks(png, pnglen);
//         // free(png);

//         // ArgbImage img = {0};
//         // int rc = decode_png_file_to_argb32_javaish(i, &img);
//         // printf("After decoding\n");
//         // print_sram_usage();
//         // sleep_ms(8000); 

//         // if (rc != 0) {
//         //     #undef printf
//         //     #define printf printf
//         //     printf("decode err=%d\n", rc);
//         //     // // #define printf(...)

//         //     i--; continue;
//         // }

//         // printf("Decoded %dx%d (ARGB)\n", img.width, img.height);
//         #undef printf
//         #define printf printf
//         printf("QueryFile: %s\n",image_names[i]);
//         // // #define printf(...)

//         DoubleMatrix decoded;
//         decoded.width = IMG_W;
//         decoded.height = IMG_H;
//         decoded.data = (float*)malloc(decoded.width * decoded.height * sizeof(float));
//         printf("After float decoded.data creation\n");
//         // print_sram_usage();
//         // sleep_ms(8000); 

//         #undef printf
//         #define printf printf
//         printf("Decoded queryfile: %s\n",image_names[i]);
//         printf("\n");

//         for (int y = 0; y < decoded.height; y++) {
//             for (int x = 0; x < decoded.width; x++) {   
//                 unsigned int pixel = images[i][y*decoded.width+x];
//                 printf("%d ",pixel);
//             }
//             printf("\n");
//         }
//         printf("\n");
//         // // // #define printf(...)

        
//         for (int y = 0; y < decoded.height; y++) {
//             for (int x = 0; x < decoded.width; x++) {   
//                 // Fill matrix like in your Java code

//                 // unsigned int pixel = img.argb[y * img.width + x];
//                 unsigned int pixel = images[i][y*decoded.width+x];
//                 int r = (pixel >> 16) & 0xFF;
//                 int g = (pixel >> 8) & 0xFF;
//                 int b = (pixel) & 0xFF;
//                 int color = r + g + b;

//                 decoded.data[y * decoded.width + x] = 1.0 - (color / (3.0 * 255.0));

//                 #undef printf
//                 #define printf printf
//                 printf("%.2f ", decoded.data[y * decoded.width + x]);
//                 // // #define printf(...)
//             }
            
//             #undef printf
//             #define printf printf
//             printf("\n");
//             // // #define printf(...)
//         }

//         // free(img.argb);
//         printf("decoded.width: %d\n", decoded.width);
//         printf("decoded.height: %d\n", decoded.height);

//         // DoubleMatrix resized_decoded_matrix = resize_dpi(decoded, 500);

//         DoubleMatrix resized_decoded_matrix = decoded;
//         printf("Before extract\n");
//         FeatureTemplate* featureTemplate = extract(resized_decoded_matrix,500);

//         SearchTemplate* inner = SearchTemplate_new(featureTemplate);
//         print_search_template(inner);

//         //////////

//         EdgeHashMap* edge_map = build_edge_map(inner);
//         print_edge_hash_map(edge_map);
//         printf("Matcher created\n");
        
//         Probe* probe = (Probe*)malloc(sizeof(Probe));
//         Probe_init(probe, inner, edge_map);

//         khash_t(str_dbl) *classScores = kh_init(str_dbl);
//         khash_t(str_dbl) *countClass = kh_init(str_dbl);

//         char* queryClass = get_class_name(file_paths[i]);       

//         for (int j = 0; j < count; j++) {
//             if (i == j) continue; // Skip self-comparison

//             printf("Candidate file: %s\n",image_names[j]);

//             // // strip_png_extension(file_paths[i]);
//             // #undef printf
//             // #define printf printf
//             // printf("j: %d; DEcoding candidateFile: %s\n", j, file_paths[j]);
//             // // // #define printf(...)

//             // unsigned char* png_2 = NULL; size_t pnglen_2 = 0;
//             // unsigned err = lodepng_load_file(&png_2, &pnglen_2, file_paths[j]);
//             // int saved_errno = errno;  
//             // if (err) { 
//             //     #undef printf
//             //     #define printf printf
//             //     printf("load err=%u\n", err); 
//             //     printf("load err=%u (%s) for %s\n", err, lodepng_error_text(err), file_paths[j]);
//             //     diagnose_path_issue("candidate", file_paths[j], saved_errno);
//             //     // // #define printf(...)
//             //     free(png_2);  // Free the allocated memory
//             //     j--; continue; 
//             // }
//             // inspect_png_chunks(png_2, pnglen_2);
//             // free(png_2);

//             // ArgbImage img_2 = {0};
//             // int rc = decode_png_file_to_argb32_javaish(j, &img_2);
//             // if (rc != 0) {
                
//             //     #undef printf
//             //     #define printf printf
//             //     printf("decode err=%d\n", rc); 
//             //     // // #define printf(...)
//             //     j--; continue;
//             // }

//             // printf("Decoded %dx%d (ARGB)\n", img_2.width, img_2.height);

//             DoubleMatrix candidate_decoded;
//             candidate_decoded.width = IMG_W;
//             candidate_decoded.height = IMG_H;
//             candidate_decoded.data = (float*)malloc( candidate_decoded.width *  candidate_decoded.height * sizeof(float));

//             #undef printf
//             #define printf printf
//             printf("Decoded candidateFile: %s\n",image_names[j]);
//             printf("\n");

//             for (int y = 0; y < candidate_decoded.width; y++) {
//                 for (int x = 0; x < candidate_decoded.height; x++) {   
//                     unsigned int pixel = images[j][y*decoded.width+x];
//                     printf("%d ",pixel);
//                 }
//                 printf("\n");
//             }
//             printf("\n");
//             // // // #define printf(...)

//             for (int y = 0; y < candidate_decoded.height; y++) {
//                 for (int x = 0; x < candidate_decoded.width; x++) {   
//                     // Fill matrix like in your Java code

//                     // unsigned int pixel = img_2.argb[y * img_2.width + x];
//                     unsigned int pixel = images[j][y*candidate_decoded.width+x];
//                     int r = (pixel >> 16) & 0xFF;
//                     int g = (pixel >> 8) & 0xFF;
//                     int b = (pixel) & 0xFF;
//                     int color = r + g + b;

//                     candidate_decoded.data[y * candidate_decoded.width + x] = 1.0 - (color / (3.0 * 255.0));

//                     // #undef printf
//                     // #define printf printf
//                     // printf("%.2f ", candidate_decoded.data[y * candidate_decoded.width + x]);
//                     // // // #define printf(...)
//                 }
                
//                 // #undef printf
//                 // #define printf printf
//                 // printf("\n");
//                 // // // #define printf(...)
//             }

//             // free(img_2.argb);

//             // DoubleMatrix candidate_decoded = read_decoded_bytes(file_paths[j]);
//             printf("candidate_decoded.width: %d\n", candidate_decoded.width);
//             printf("candidate_decoded.height: %d\n", candidate_decoded.height);
//             // DoubleMatrix resized_candidate_matrix = resize_dpi(candidate_decoded, 500);
//             DoubleMatrix resized_candidate_matrix = candidate_decoded;
//             FeatureTemplate* candidate_feature_template = extract(resized_candidate_matrix, 500);
//             SearchTemplate* candidate = SearchTemplate_new(candidate_feature_template);
//             print_search_template(candidate);

//             double score = matcher_engine_match(probe, candidate);

//             #undef printf
//             #define printf printf
//             printf("Score between %s and %s: %.2f\n", file_paths[i], file_paths[j], score);
//             // // #define printf(...)

//             fprintf(file_sc, "Score between %s and %s: %.2f\n", file_paths[i], file_paths[j], score);
//             fflush(file_sc);

//             // free(candidate_decoded.data);
//             SearchTemplate_free(candidate);
//             FeatureTemplate_free(candidate_feature_template);
//             // free_argb(img_2.argb);
//             resized_candidate_matrix.data=NULL;

//             // // Extract candidate representation
//             // char cand_rep[MAX_REP_LEN];
//             // char clean_cand_filename[512];
//             // get_filename_from_log(file_paths[j], clean_cand_filename, sizeof(clean_cand_filename));
//             // get_representation(clean_cand_filename, cand_rep, sizeof(cand_rep));


//             // // Add to that representation's running total
//             // int idx = find_rep_index(repScores, repCount, cand_rep);
//             // if (idx < 0) {
//             //     // New representation bucket
//             //     strncpy(repScores[repCount].rep, cand_rep, MAX_REP_LEN - 1);
//             //     repScores[repCount].rep[MAX_REP_LEN - 1] = '\0';
//             //     repScores[repCount].sumScore = score;
//             //     repCount++;
//             // } else {
//             //     repScores[idx].sumScore += score;
//             //     repScores[idx].count += 1;
//             // }

//             // char* currentMatchClass = get_class_name(file_paths[j]);

//             // khint_t k = kh_get(str_dbl, classScores, currentMatchClass);
//             // double old_score = 0.0;

//             // if (k != kh_end(classScores)) {
//             //     old_score = kh_val(classScores, k);
//             // }

//             // // Insert or update
//             // int ret;
//             // k = kh_put(str_dbl, classScores, strdup(currentMatchClass), &ret);
//             // kh_val(classScores, k) = old_score + score;

//             // // Update count
//             // khint_t count_k = kh_get(str_dbl, countClass, currentMatchClass);
//             // if (count_k == kh_end(countClass)) {
//             //     k = kh_put(str_dbl, countClass, strdup(currentMatchClass), &ret);
//             //     kh_val(countClass, k) = 1; // Initialize count to 1
//             // } else {    
//             //     kh_val(countClass, count_k) += 1; // Increment count
//             // }

//         }

//         free(decoded.data);
//         SearchTemplate_free(inner);
//         FeatureTemplate_free(featureTemplate);
//         // free_argb(img.argb);
//         // free(resized_decoded_matrix.data);
//         resized_decoded_matrix.data = NULL;
//         // free(img.argb);

//         Probe_destroy(probe, 0);                              // NEW (implement)
//         // EdgeHashMap_free(edge_map); 
    
//         // // normalize_and_rank(classScores, countClass, queryClass, 1, &matchCount, &passCount, &false_positive_number);

//         // // --- Find the highest total score and its representation ---
//         // double bestScore = INT_MIN;
//         // int bestIdx = -1;
//         // for (int i = 0; i < repCount; ++i) {
//         //     if (repScores[i].count > 0) {
//         //         double normalizedScore = repScores[i].sumScore / (double)repScores[i].count;
//         //         if (normalizedScore > bestScore) {
//         //             bestScore = normalizedScore;
//         //             bestIdx = i;
//         //         }
//         //     }
//         // }

//         // const char *pred_rep = (bestIdx >= 0) ? repScores[bestIdx].rep : "";

//         // // --- Metrics update per your rules ---
//         // // 1) Match if predicted representation == query representation (regardless of threshold)
//         // if (bestIdx >= 0 && strcmp(pred_rep, query_rep) == 0) {
//         //     matching += 1;
//         // }

//         // // 2) If highest total score < threshold => pass
//         // if (bestIdx < 0 || bestScore < threshold) {
//         //     passcount += 1;
//         // } else {
//         //     // 3) Else, if they don't match and score > threshold => false positive
//         //     if (strcmp(pred_rep, query_rep) != 0) {
//         //         false_positive += 1;
//         //     }
//         // }

//         // free(repScores);

//     }

//     // Close the file
//     if (fclose(file_sc) != 0) {
//         perror("Error closing file");
//         return EXIT_FAILURE;
//     }

//      // --- Final metrics ---
//     // Use double to avoid integer division
//     double total = (double)count;
//     double accuracy = (total > 0.0) ? ((double)matching) / total : 0.0;
//     double false_positive_rate = (total > 0.0) ? ((double)false_positive) / total : 0.0;
//     double pass_rate = (total > 0.0) ? ((double)passcount) / total : 0.0;

//     #undef printf
//     #define printf printf
//     printf("Queries: %d\n", count);
//     printf("Matches: %d, False Positives: %d, Passes: %d\n", matching, false_positive, passcount);
//     printf("Accuracy: %.6f\n", accuracy);
//     printf("False Positive Rate: %.6f\n", false_positive_rate);
//     printf("Pass Rate: %.6f\n", pass_rate);
//     // // #define printf(...)

//     // print_stats(*matchCount, *passCount, count);

    
// }





#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "lodepng.h"

#include <png.h>

#include <stdlib.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#include <stdint.h>
#include <stddef.h>

#include <limits.h>



#define MAX_REP_LEN 100

double threshold = 4.5;

// //////////////////////
// #if __has_include(<malloc.h>)
//   #include <malloc.h>
// #endif
// #if __has_include(<unistd.h>)
//   #include <unistd.h>   // for sbrk(0) if provided by your C library
// #endif

// // Linker symbols provided by the Pico SDK linker scripts.
// // Names are the same on RP2040 & RP2350 builds.
// extern char __StackTop;      // initial stack pointer (top of stack region, higher address)
// extern char __StackLimit;    // bottom of stack region (lower address)
// extern char __bss_start__, __bss_end__;
// extern char __data_start__, __data_end__;

// // --- Segment sizes (link-time fixed parts) ---
// static inline uint32_t data_size(void) {
//     return (uint32_t)((uintptr_t)&__data_end__ - (uintptr_t)&__data_start__);
// }
// static inline uint32_t bss_size(void) {
//     return (uint32_t)((uintptr_t)&__bss_end__ - (uintptr_t)&__bss_start__);
// }

// // --- Heap accounting ---
// static inline uint32_t heap_total_region(void) {
//     // Heap grows up from end of .bss toward __StackLimit
//     return (uint32_t)((uintptr_t)&__StackLimit - (uintptr_t)&__bss_end__);
// }

// static inline uint32_t heap_used_runtime(void) {
// #if defined(__GLIBC__) || defined(__NEWLIB__)
//   #if __has_include(<malloc.h>)
//     // mallinfo is common on embedded newlib; if mallinfo2 exists you can switch to it.
//     struct mallinfo mi = mallinfo();
//     return (uint32_t)mi.uordblks; // bytes currently allocated on the heap
//   #else
//     return 0u;
//   #endif
// #else
//     return 0u;
// #endif
// }

// // Current program break (end of heap) if sbrk available:
// static inline uintptr_t heap_brk(void) {
// #if __has_include(<unistd.h>)
//     void *brk = sbrk(0);
//     return (uintptr_t)brk;
// #else
//     // Fallback estimate: end of .bss + heap_used (works if allocator is linear)
//     return (uintptr_t)&__bss_end__ + heap_used_runtime();
// #endif
// }

// // --- Stack accounting ---
// static inline uint32_t stack_capacity(void) {
//     // Stack region is [__StackLimit, __StackTop], grows downward from __StackTop
//     return (uint32_t)((uintptr_t)&__StackTop - (uintptr_t)&__StackLimit);
// }

// static inline uint32_t stack_used_now(void) {
//     volatile char sp_probe;                 // lives on the current stack frame
//     uintptr_t sp = (uintptr_t)&sp_probe;    // current stack pointer approx
//     uintptr_t top = (uintptr_t)&__StackTop; // initial SP (top of stack)
//     // Because stack grows down, bytes used = top - current_sp
//     return (uint32_t)(top - sp);
// }

// // --- Convenience: free space between heap and current stack ---
// static inline uint32_t free_between_heap_and_stack(void) {
//     volatile char sp_probe;
//     uintptr_t sp  = (uintptr_t)&sp_probe;
//     uintptr_t brk = heap_brk();
//     if (sp > brk) {
//         return (uint32_t)(sp - brk);
//     } else {
//         // Heap/stack collision (or estimate failure)
//         return 0u;
//     }
// }

// void print_sram_usage(void) {
//     uint32_t data   = data_size();
//     uint32_t bss    = bss_size();
//     uint32_t heap_u = heap_used_runtime();
//     uint32_t heap_T = heap_total_region();
//     uint32_t stk_u  = stack_used_now();
//     uint32_t stk_T  = stack_capacity();
//     uint32_t gap    = free_between_heap_and_stack();

//     printf("SRAM usage breakdown (bytes):\n");
//     printf("  .data:                 %u\n", data);
//     printf("  .bss:                  %u\n", bss);
//     printf("  Heap used:             %u\n", heap_u);
//     printf("  Heap total region:     %u\n", heap_T);
//     printf("  Stack used (current):  %u\n", stk_u);
//     printf("  Stack capacity:        %u\n", stk_T);
//     printf("  Free (heap<->stack):   %u\n", gap);

//     // Optional: total 'currently used' estimate (excludes unused part of heap/stack regions)
//     uint32_t est_used_now = data + bss + heap_u + stk_u;
//     printf("  ----\n");
//     printf("  Estimated used now:    %u\n", est_used_now);
// }

/////////////////////

#include <time.h>

#define DEBUG_UART uart0    // UART0 for printf debugging
#define SENSOR_UART uart1   // UART1 for fingerprint sensor

#define BAUD_RATE 115200    // Debug UART baud rate
#define SENSOR_BAUD 19200   // Fingerprint sensor baud rate
// max 200 fingerprints in R502

// UART0 (for printf)
#define UART0_TX_PIN 0
#define UART0_RX_PIN 1

// UART1 (for fingerprint sensor)
#define UART1_TX_PIN 4
#define UART1_RX_PIN 5

// #define FINGER_IRQ_PIN 6
// #define FINGER_EN_PIN 7

#define TRUE          1
#define FALSE         0

// Basic response message definition
#define ACK_SUCCESS            0x00
#define ACK_FAIL               0x01
#define ACK_FULL               0x04
#define ACK_NO_USER            0x05
#define ACK_TIMEOUT            0x08
#define ACK_GO_OUT             0x0F     // The center of the fingerprint is out of alignment with sensor

// User information definition
#define ACK_ALL_USER           0x00
#define ACK_GUEST_USER         0x01
#define ACK_NORMAL_USER        0x02
#define ACK_MASTER_USER        0x03

#define USER_MAX_CNT           1000        // Maximum fingerprint number

// Command definition
#define CMD_HEAD               0xF5
#define CMD_TAIL               0xF5
#define CMD_ADD_1              0x01
#define CMD_ADD_2              0x02
#define CMD_ADD_3              0x03
#define CMD_MATCH              0x0C
#define CMD_UPLOAD_EIGEN_VALUES 0x31
#define CMD_ACQUIRE_IMAGE_AND_UPLOAD 0x24
#define CMD_GET_EIGEN_VALUES_OF_FINGER 0x23
#define CMD_COMPARE_EIGEN_VALUES_OF_FINGER 0x44
#define CMD_COMPARE_EIGEN_VALUES_WITH_ALL_USERS 0x43
#define CMD_DEL                0x04
#define CMD_DEL_ALL            0x05
#define CMD_USER_CNT           0x09
#define CMD_COM_LEV            0x28
#define CMD_LP_MODE            0x2C
#define CMD_TIMEOUT            0x2E

#define CMD_FINGER_DETECTED    0x14

// uint8_t Finger_SleepFlag    = 0; 

uint8_t g_rx_buf [10000] = {0};

uint8_t fingerprint_eigen_database[193]={0};

#define RING_BUFFER_SIZE 20000

// === Ring Buffer ===
volatile uint8_t ring_buffer[RING_BUFFER_SIZE];
volatile size_t head = 0;
volatile size_t tail = 0;

// void Auto_Verify_Finger()
// {
//     while(true)
//     {
//         /*
//         By default, Finger_SleepFlag is 0, which means the module is awake.
//         Using "CMD2", add multiple users first.
//         Then, use "CMD5" to put the module into sleep mode.
//         Then use Auto_Verify_Finger() to always check for fingerprint verification whenever user presses on top of sensor and now, all other CMDs except for "CMD6" won't work
//         If you want to add a new user, use "CMD6" to wake up the module. Now, Auto_Verify_Finger() will not longer work. Add new user using "CMD2" and then put module to sleep using "CM5" and now forever-loop for Auto_Verify_Finger() is back.
//         */
//         if(Finger_SleepFlag==1)
//         {
//             if (gpio_get(FINGER_WAKE_PIN))
//             {
//                 sleep_ms(10); 
//                 if(gpio_get(FINGER_WAKE_PIN))           // Finger is indeed pressed for verification?
//                 {
//                     gpio_put(FINGER_RST_PIN, 1);        // Temporary work will happen
//                     sleep_ms(250);
//                     printf("Waiting Finger......Please try to place the center of the fingerprint flat to sensor !\n");
//                     uint8_t r=VerifyUser();
//                     if(r==ACK_SUCCESS)
//                     {
//                         printf("Matching successful.\n");
//                     }
//                     else if(r==ACK_NO_USER)
//                     {
//                         printf("No matching fingerprint found.\n");
//                     }
//                     else if(r==ACK_TIMEOUT)
//                     {
//                         printf("Timeout occurred while matching fingerprint.\n");
//                     }
//                     else if(r==ACK_GO_OUT)
//                     {
//                         printf("Fingerprint is out of alignment with sensor.\n");
//                     }

//                     gpio_put(FINGER_RST_PIN, 0);

//                 }
//             }
//         }

//         sleep_ms(200);
//     }
// }

// int main() {
//     // // stdio_init_all();
//     // setup_uart0();  // Initialize UART0 for debugging
//     // printf("UART0 is done!\n");
//     // setup_uart1();  // Initialize UART1 for fingerprint sensor
//     // // // init_gpio();
//     // // printf("UART1 is done!\n");

//     // while(SetCompareLevel(5) != 5)
//     // {
//     //     printf("Set compare level failed, retrying...\n");
//     //     sleep_ms(1000);
//     // }

//     // // // multicore_launch_core1(Auto_Verify_Finger);  // Start the auto verification thread



//     // while(true)
//     // {
//     //     uart_puts(DEBUG_UART,"Commands:\n");
//     //     uart_puts(DEBUG_UART,"1: Query the number of existing fingerprints\n");
//     //     uart_puts(DEBUG_UART,"2: Register fingerprint\n");
//     //     uart_puts(DEBUG_UART,"3: Fingerprint matching\n");
//     //     uart_puts(DEBUG_UART,"4: Clear all fingerprints\n");
//     //     uart_puts(DEBUG_UART,"5: Get image for current finger\n");
//     //     uart_puts(DEBUG_UART,"6: Exit\n");

//     //     char input[100];
//     //     int i = 0;
//     //     while (i < 99) {
//     //         char c = uart_getc(DEBUG_UART);
//     //         uart_putc(DEBUG_UART, c);        // Echo back to terminal
//     //         if (c == '\r' || c == '\n') break;  // Stop on Enter key
//     //         input[i++] = c;
//     //     }
//     //     input[i] = '\0';

//     //     Analysis_PC_Command(input);
//     // }

//     // return 0;
// }

///////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"
// #include <stdlib.h>
#include <stdint.h>
// #include <stdio.h>

// #include <png.h>

// #include <stdlib.h>
// #include <math.h>

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <dirent.h>
// #include <sys/stat.h>

// #include <stdint.h>
#include <stddef.h>

#include <limits.h>

#define MASK_VOTE_RADIUS 7
#define MASK_VOTE_MAJORITY 0.51
#define MASK_VOTE_BORDER_DISTANCE 4
#define CLIPPED_CONTRAST 0.08
#define MIN_ABSOLUTE_CONTRAST  17 / 255.0
#define MASK_VOTE_RADIUS 7
#define MASK_VOTE_MAJORITY 0.51
#define MASK_VOTE_BORDER_DISTANCE 4
#define RELATIVE_CONTRAST_SAMPLE 168568
#define RELATIVE_CONTRAST_PERCENTILE 0.49
#define MIN_RELATIVE_CONTRAST 0.34

#define BLOCK_ERRORS_VOTE_RADIUS 1
#define BLOCK_ERRORS_VOTE_MAJORITY 0.7
#define BLOCK_ERRORS_VOTE_BORDER_DISTANCE 4
#define MASK_VOTE_RADIUS 7
#define MASK_VOTE_MAJORITY  0.51
#define MASK_VOTE_BORDER_DISTANCE 4

#define MAX_EQUALIZATION_SCALING  3.99
#define MIN_EQUALIZATION_SCALING  0.25

#define ORIENTATION_SPLIT 50
#define ORIENTATIONS_CHECKED 20
#define MIN_ORIENTATION_RADIUS 2
#define MAX_ORIENTATION_RADIUS 6
#define ORIENTATION_SMOOTHING_RADIUS 1

#define PARALLEL_SMOOTHING_RESOLUTION  32
#define PARALLEL_SMOOTHING_RADIUS  7
#define PARALLEL_SMOOTHING_STEP  1.59
#define ORTHOGONAL_SMOOTHING_RESOLUTION  11
#define ORTHOGONAL_SMOOTHING_RADIUS  4
#define ORTHOGONAL_SMOOTHING_STEP 1.11

#define M_PI 3.141592653589793
#define PI2 2*M_PI
#define INV_PI2 1.0/(PI2)// 1 / M_PI
#define HALF_PI 0.5*M_PI

#define INNER_MASK_BORDER_DISTANCE  14

#define BINARIZED_VOTE_RADIUS 2
#define BINARIZED_VOTE_MAJORITY 0.61
#define BINARIZED_VOTE_BORDER_DISTANCE 17

#define THINNING_ITERATIONS  26

#define MAX_PORE_ARM 41

#define TOLERATED_GAP_OVERLAP 2
#define GAP_ANGLE_OFFSET 22
#define MAX_RUPTURE_SIZE 5
#define MAX_GAP_SIZE 20
#define MAX_GAP_ANGLE (M_PI / 4.0)  // 45 degrees in radians
#define TOLERATED_GAP_OVERLAP 2
#define SHORTEST_JOINED_ENDING 7
#define MIN_TAIL_LENGTH 21
#define MIN_FRAGMENT_LENGTH 22

#define RIDGE_DIRECTION_SKIP 1
#define RIDGE_DIRECTION_SAMPLE 21

#define MASK_DISPLACEMENT 10.06

#define MINUTIA_CLOUD_RADIUS 20
#define MAX_CLOUD_SIZE  4

#define MAX_MINUTIAE 100

#define SORT_BY_NEIGHBOR  5

#define POLAR_CACHE_BITS 8
#define POLAR_CACHE_RADIUS (1 << POLAR_CACHE_BITS)
#define POLAR_CACHE_SIZE (POLAR_CACHE_RADIUS * POLAR_CACHE_RADIUS)

#define EDGE_TABLE_NEIGHBORS 9

#define MIN_ROOT_EDGE_LENGTH 58

#define MAX_ROOT_EDGE_LOOKUPS 1633

int smooth_hist_array[8*8*256];

// // #define printf(...)   

typedef struct { int width, height; uint32_t* argb; } ArgbImage;

// sRGB encoding: linear [0..1] -> sRGB [0..1]
static inline uint8_t linear_to_srgb_u8(float L) {
    if (L <= 0.0031308f) L = 12.92f * L;
    else                 L = 1.055f * powf(L, 1.0f/2.4f) - 0.055f;
    int out = (int)lroundf(fmaxf(0.f, fminf(1.f, L)) * 255.f);
    return (uint8_t)out;
}

static void free_argb(ArgbImage* img) {
    if (!img) return;
    // free(img->argb);
    img->argb = NULL;
    img->width = img->height = 0;
}

static void inspect_png_chunks(const unsigned char* png, size_t len) {
    LodePNGState st; lodepng_state_init(&st);
    unsigned w=0,h=0;
    unsigned err = lodepng_inspect(&w,&h,&st,png,len);
    // if (err) {
    //     printf("inspect error=%u\n", err);
    // } else {
    //     printf("PNG %ux%u  sRGB=%u  gAMA_defined=%u  iCCP=%u\n",
    //            w,h, st.info_png.srgb_defined, st.info_png.gama_defined
    //           , st.info_png.iccp_defined);
    // }
    lodepng_state_cleanup(&st);
}
// Decode and try to match Java ImageIO getRGB() on grayscale PNGs with no profile
static int decode_png_file_to_argb32_javaish(ArgbImage* out, int k) {
    // Load file
    unsigned char* png = NULL; size_t pnglen = 0;
    // unsigned err = lodepng_load_file(&png, &pnglen, path);

    // #undef printf
    // #define printf printf
    // printf("Decoding PNG file: %s; pnglen: %d\n", path, (int)pnglen);
    // for(int i=0; i<pnglen; i++) {
    //     printf("%d ", png[i]);
    // }
    // printf("\n");
    // // #define printf(...)

    // if (err) return (int)err;

    // // Inspect chunks
    // LodePNGState st; lodepng_state_init(&st);
    // unsigned w=0,h=0;
    // err = lodepng_inspect(&w,&h,&st,png,pnglen);
    // if (err) { lodepng_state_cleanup(&st); free(png); return (int)err; }
    // int is_gray = (st.info_png.color.colortype == LCT_GREY);
    // int has_profile = st.info_png.srgb_defined || st.info_png.gama_defined || st.info_png.iccp_defined;
    // lodepng_state_cleanup(&st);

    // // Decode
    // unsigned char* gray = NULL;
    // unsigned char* rgba = NULL;
    // if (is_gray) {
    //     LodePNGState st2; lodepng_state_init(&st2);
    //     st2.info_raw.colortype = LCT_GREY;
    //     st2.info_raw.bitdepth  = 8;
    //     err = lodepng_decode(&gray, &w, &h, &st2, png, pnglen);
    //     lodepng_state_cleanup(&st2);

    //     #undef printf
    //     #define printf printf
    //     printf("Decoded gray image: %dx%d  has_profile=%d  err=%d\n", (int)w, (int)h, has_profile, err);
    //     for(int i=0;i<h;i++)
    //     {
    //         for(int j=0;j<w;j++)
    //         {
    //             printf("%d ",gray[i*w+j]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    //     // #define printf(...)
    // } else {
    //     err = lodepng_decode32(&rgba, &w, &h, png, pnglen);
    // }
    // free(png);
    // if (err) return (int)err;

    size_t n = (size_t)IMG_W * IMG_H;
    uint32_t* argb = (uint32_t*)malloc(n * sizeof(uint32_t));
    // if (!argb) { free(gray); free(rgba); return 100; }

                                                                // is_gray=1
    // Build linear->sRGB LUT once
    static uint8_t lut[256];
    static int lut_init = 0;
    if (!lut_init) {                                                            // lut_init=1
        for (int v = 0; v < 256; v++) {
            float L = v / 255.0f;           // interpret stored gray as linear
            lut[v] = linear_to_srgb_u8(L);  // encode to sRGB
        }
        lut_init = 1;
    }

    // No profile: assume linear gray -> sRGB to match ImageIO.getRGB() brightness
    for (size_t i = 0; i < n; i++) {
        uint8_t g = lut[images[k][i]];
        argb[i] = 0xFF000000u | (g<<16) | (g<<8) | g;
    }
        
    out->width  = (int)IMG_W;
    out->height = (int)IMG_H;
    out->argb   = argb;

    #undef printf
    #define printf printf
    for (size_t i = 0; i < n; i++) {
        printf("argb[%d]: %u; ",i,argb[i]);
    }
    printf("\n");
    // #define printf(...)

    return 0;
}

/////////////////////
// BlockGrid and BlockMap structures

typedef struct {
    int x;
    int y;
} IntPoint;

typedef struct {
    IntPoint blocks;
    IntPoint corners;
    int* x;  // size = blocks.x + 1
    int* y;  // size = blocks.y + 1
} BlockGrid;

typedef struct{
	IntPoint pixels;
	BlockGrid primary;
	BlockGrid secondary;
} BlockMap;


// typedef struct {
// 	IntPoint topLeft;
// 	IntPoint bottomRight;
// } IntRect;
typedef struct {
    int x;
    int y;
    int width;
    int height;
} IntRect;

// Constant: ZERO = (0, 0)
const IntPoint INTPOINT_ZERO = {0, 0};

// Constant array: EDGE_NEIGHBORS
const IntPoint EDGE_NEIGHBORS[4] = {
	{ 0, -1}, // top
	{-1,  0}, // left
	{ 1,  0}, // right
	{ 0,  1}  // bottom
};

// Constant array: CORNER_NEIGHBORS
const IntPoint CORNER_NEIGHBORS[8] = {
	{-1, -1}, // top-left
	{ 0, -1}, // top
	{ 1, -1}, // top-right
	{-1,  0}, // left
	{ 1,  0}, // right
	{-1,  1}, // bottom-left
	{ 0,  1}, // bottom
	{ 1,  1}  // bottom-right
};


BlockGrid create_block_grid(IntPoint size) {
	BlockGrid grid;
	grid.blocks = size;
	grid.corners.x = size.x + 1;
	grid.corners.y = size.y + 1;

	grid.x = (int*)malloc(sizeof(int) * grid.corners.x);
	grid.y = (int*)malloc(sizeof(int) * grid.corners.y);

	return grid;
}

BlockGrid create_block_grid_from_dimensions(int width, int height) {
	IntPoint size = {width, height};
	return create_block_grid(size);
}

IntPoint blockgrid_corner(const BlockGrid* grid, int atX, int atY) {
	IntPoint pt = { grid->x[atX], grid->y[atY] };
	return pt;
}

IntPoint blockgrid_corner_point(const BlockGrid* grid, IntPoint at) {
	return blockgrid_corner(grid, at.x, at.y);
}

IntPoint intpoint_negate(IntPoint p) {
    IntPoint result;
    result.x = -p.x;
    result.y = -p.y;
    return result;
}

bool intpoint_equal(IntPoint a, IntPoint b) {
    return a.x == b.x && a.y == b.y;
}

bool contains_intpoint(IntPoint* array, int size, IntPoint value) {
    for (int i = 0; i < size; ++i) {
        if (intpoint_equal(array[i], value))
            return true;
    }
    return false;
}

IntRect create_intrect(int x, int y, int width, int height) {
    IntRect rect;
    rect.x = x;
    rect.y = y;
    rect.width = width;
    rect.height = height;
    return rect;
}

IntRect intrect_between(IntPoint a, IntPoint b) {
    int x = a.x;
    int y = a.y;
    int width = b.x - a.x;
    int height = b.y - a.y;
    return create_intrect(x, y, width, height);
}

IntRect move_rect(IntRect rect, IntPoint delta) {
    IntRect result;
    result.x = rect.x + delta.x;
    result.y = rect.y + delta.y;
    result.width = rect.width;
    result.height = rect.height;
    return result;
}

IntRect intersect_rect(IntRect a, IntRect b) {
    int left = fmax(a.x, b.x);
    int top = fmax(a.y, b.y);
    int right = fmin(a.x + a.width, b.x + b.width);
    int bottom = fmin(a.y + a.height, b.y + b.height);

    IntRect result;
    result.x = left;
    result.y = top;
    result.width = right > left ? right - left : 0;
    result.height = bottom > top ? bottom - top : 0;

    return result;
}



IntRect blockgrid_block(const BlockGrid* grid, int atX, int atY) {
	IntPoint topLeft = blockgrid_corner(grid, atX, atY);
	IntPoint bottomRight = blockgrid_corner(grid, atX + 1, atY + 1);
	return intrect_between(topLeft, bottomRight);
}

IntRect blockgrid_block_point(const BlockGrid* grid, IntPoint at) {
	return blockgrid_block(grid, at.x, at.y);
}


// --- Helper functions ---
static inline int round_up_div(int a, int b) {
	return (a + b - 1) / b;
}

void free_block_grid(BlockGrid* grid) {
	free(grid->x);
	free(grid->y);
}

// Emulate primary.block(x,y).center()
IntPoint block_center(BlockGrid* grid, int x, int y) {
	int center_x = (grid->x[x] + grid->x[x + 1]) / 2;
	int center_y = (grid->y[y] + grid->y[y + 1]) / 2;
	IntPoint center = {center_x, center_y};
	return center;
}

BlockMap create_block_map(int width, int height, int maxBlockSize) {
	BlockMap map;
	map.pixels.x = width;
	map.pixels.y = height;
    // printf("width: %d, height: %d, maxBlockSize: %d\n", width, height, maxBlockSize);

	IntPoint primary_blocks = {
		round_up_div(width, maxBlockSize),
		round_up_div(height, maxBlockSize)
	};

    // printf("primary_blocks.x: %d, primary_blocks.y: %d\n", primary_blocks.x, primary_blocks.y);

	map.primary = create_block_grid(primary_blocks);

	for (int y = 0; y <= primary_blocks.y; ++y)
		map.primary.y[y] = y * height / primary_blocks.y;

	for (int x = 0; x <= primary_blocks.x; ++x)
		map.primary.x[x] = x * width / primary_blocks.x;

	map.secondary = create_block_grid(map.primary.corners);

	map.secondary.y[0] = 0;
	for (int y = 0; y < primary_blocks.y; ++y)
		map.secondary.y[y + 1] = block_center(&map.primary, 0, y).y;
	map.secondary.y[map.secondary.blocks.y] = height;

	map.secondary.x[0] = 0;
	for (int x = 0; x < primary_blocks.x; ++x)
		map.secondary.x[x + 1] = block_center(&map.primary, x, 0).x;
	map.secondary.x[map.secondary.blocks.x] = width;

	return map;
}

//////////////////

#define MAX_LINES 1000000

typedef struct {
    int width;
    int height;
    float* data;
} DoubleMatrix;

DoubleMatrix create_matrix(int width, int height) {
    DoubleMatrix mat;
    mat.width = width;
    mat.height = height;
    mat.data = calloc(width * height, sizeof(float));
    return mat;
}

void free_matrix(DoubleMatrix* mat) {
    free(mat->data);
    free(mat);
}

float get(DoubleMatrix* mat, int x, int y) {
    return mat->data[y * mat->width + x];
}

void set(DoubleMatrix* mat, int x, int y, float value) {
    mat->data[y * mat->width + x] = value;
}

// static inline int double_matrix_offset(const DoubleMatrix* matrix, int x, int y) {
//     return y * matrix->width + x;
// }

void double_matrix_add(DoubleMatrix* matrix, int x, int y, float value) {
    int index = double_matrix_offset(matrix, x, y);
    matrix->data[index] += value;
}

void double_matrix_add_point(DoubleMatrix* matrix, IntPoint at, float value) {
    double_matrix_add(matrix, at.x, at.y, value);
}

void double_matrix_multiply(DoubleMatrix* matrix, int x, int y, float value) {
    int index = double_matrix_offset(matrix, x, y);
    matrix->data[index] *= value;
}

void double_matrix_multiply_point(DoubleMatrix* matrix, IntPoint at, float value) {
    double_matrix_multiply(matrix, at.x, at.y, value);
}

DoubleMatrix resize_matrix(DoubleMatrix input, int newWidth, int newHeight) {
    if (newWidth == input.width && newHeight == input.height)
        return input;

    DoubleMatrix output = create_matrix(newWidth, newHeight);
    float scaleX = newWidth / (float)input.width;
    float scaleY = newHeight / (float)input.height;
    float descaleX = 1.0 / scaleX;
    float descaleY = 1.0 / scaleY;

    for (int y = 0; y < newHeight; ++y) {
        float y1 = y * descaleY;
        float y2 = y1 + descaleY;
        int y1i = (int)y1;
        int y2i = fmin((int)ceil(y2), input.height);

        for (int x = 0; x < newWidth; ++x) {
            float x1 = x * descaleX;
            float x2 = x1 + descaleX;
            int x1i = (int)x1;
            int x2i = fmin((int)ceil(x2), input.width);
            float sum = 0.0;

            for (int oy = y1i; oy < y2i; ++oy) {
                float ry = fmin(oy + 1.0, y2) - fmax(oy * 1.0, y1);
                for (int ox = x1i; ox < x2i; ++ox) {
                    float rx = fmin(ox + 1.0, x2) - fmax(ox * 1.0, x1);
                    sum += rx * ry * get(&input, ox, oy);
                }
            }

            set(&output, x, y, sum * (scaleX * scaleY));
        }
    }

    return output;
}

DoubleMatrix resize_dpi(DoubleMatrix input, int dpi) {
    int newWidth = (int)round(500.0 / dpi * input.width);
    int newHeight = (int)round(500.0 / dpi * input.height);
    return resize_matrix(input, newWidth, newHeight);
}

// DoubleMatrix decode_image(const uint8_t* image_data, size_t size) {

//     // return d;
//     int width, height, channels;

//     printf("Size: %zu\n", size);
//     for (int i = 0; i < size; i++) {
//         printf("%02x ", image_data[i]);
//         if ((i + 1) % 16 == 0) printf("\n");
//     }

//     printf("(int)(size): %d\n", (int)(size));

//     // // Force 4 channels (RGBA)
//     // unsigned char* img = stbi_load_from_memory(image_data, (int)(size), &width, &height, &channels, 1);
//     uint8_t* img = stbi_load("/home/kshitij/SecurSi/read-write-data-from-uart-by-client/pixels_dir/pixelsKshitijleftindexfinger_0.png", &width, &height, &channels, 4);

//     // Allocate DoubleMatrix
//     DoubleMatrix decoded;
//     decoded.width = width;
//     decoded.height = height;
//     decoded.data = (float*)malloc(width * height * sizeof(float));

//     if (!img) {
//         fprintf(stderr, "Unsupported or invalid image format\n");
//         fprintf(stderr, "STB reason: %s\n", stbi_failure_reason());  // <-- add this here
//         return decoded;
//     }

//     printf("width: %d, height: %d, channels: %d\n", width, height, channels);

//     int *pixels = malloc(width * height * sizeof(int));
//     if (!pixels) {
//         perror("malloc failed");
//         exit(1);
//     }

//      for (int y = 0; y < height; ++y) {
//         for (int x = 0; x < width; ++x) {
//             int idx = (y * width + x) * 4;
//             uint8_t rr = img[idx + 0];
//             uint8_t g = img[idx + 1];
//             uint8_t b = img[idx + 2];
//             uint8_t a = img[idx + 3];

//             printf("rr:  %d, g: %d, b: %d, a: %d\n", rr, g, b, a);

//             // Match Java's ARGB pixel
//             uint32_t pixel = (a << 24) | (g << 16) | (g << 8) | g;

//             float px=g;
//             float intensity = 1-px*1.0/255;

//             // int color = (pixel & 0xff) + ((pixel >> 8) & 0xff) + ((pixel >> 16) & 0xff);
//             // float intensity = 1.0f - color * (1.0f / (3.0f * 255.0f));
//             // // float intensity = 1.0f - pow(r/255,2.2);

//             printf("Pixel at (y=%d, x=%d): 0x%08x, intensity: %.6f\n", y, x, pixel,intensity);

//             decoded.data[idx]=intensity;

//             // Use intensity as needed
//         }
//     }

//     stbi_image_free(img);
//     return decoded;
// }

unsigned char* read_all_bytes(const char* filepath, size_t* out_size) {
    FILE* file = fopen(filepath, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    // puts file pointer to end of file
    fseek(file, 0, SEEK_END);
    // gets position of file pointer
    size_t size = ftell(file);
    // moves file pointer again to start of file
    rewind(file);

    printf("size: %lu\n",size);

    unsigned char* buffer = (unsigned char*)malloc(size);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    // copy each byte of size 1 to destination buffer
    size_t read_size = fread(buffer, 1, size, file);

    fclose(file);

    if (read_size != size) {
        perror("Failed to read entire file");
        free(buffer);
        return NULL;
    }

    *out_size = size;
    return buffer;
}

typedef struct {
	int width;
	int height;
	int bins;
	int* counts;  // Array of size width * height * bins
} HistogramCube;

static int offset(const HistogramCube* cube, int x, int y, int z) {
	return (y * cube->width + x) * cube->bins + z;
}

void print_histogram_cube(const HistogramCube* cube) {
    #undef printf
    #define printf printf
	for (int y = 0; y < cube->height; ++y) {
		for (int x = 0; x < cube->width; ++x) {
			for (int bin = 0; bin < cube->bins; ++bin) {
				int value = histogram_cube_get(cube, x, y, bin);
				printf("%d ", value); // Print bins in same line
			}
			printf("\n"); // Newline between blocks
		}
	}

    #define printf(...)
}

HistogramCube create_histogram_cube(int width, int height, int bins) {
    printf("Inside create_histogram_cube, before creating cube\n");
    // print_sram_usage();
    // sleep_ms(8000); 
	HistogramCube cube;
	cube.width = width;
	cube.height = height;
	cube.bins = bins;
    printf("width: %d, height: %d, bins: %d\n", width, height, bins);
    printf("width * height * bins* sizeof(int): %d\n", width * height * bins* sizeof(int));
	cube.counts = (int*)calloc(width * height * bins, sizeof(int));
    printf("About to go outside create_histogram_cube");
    // print_sram_usage();
    // sleep_ms(8000);
	return cube;
}

HistogramCube create_histogram_cube_from_point(IntPoint size, int bins) {
    #undef printf
    #define printf printf
    printf("Creating histogram with size.x= %d, size.y=%d\n",size.x,size.y);
    #define printf(...)
	return create_histogram_cube(size.x, size.y, bins);
}

void free_histogram_cube(HistogramCube* cube) {
	free(cube->counts);
	cube->counts = NULL;
}

// Clamp z between 0 and bins-1
int histogram_cube_constrain(const HistogramCube* cube, int z) {
	if (z < 0) return 0;
	if (z >= cube->bins) return cube->bins - 1;
	return z;
}

int histogram_cube_get(const HistogramCube* cube, int x, int y, int z) {
	return cube->counts[offset(cube, x, y, z)];
}

int histogram_cube_get_at(const HistogramCube* cube, IntPoint at, int z) {
	return histogram_cube_get(cube, at.x, at.y, z);
}

int histogram_cube_sum(const HistogramCube* cube, int x, int y) {
	int sum = 0;
	for (int i = 0; i < cube->bins; ++i)
		sum += histogram_cube_get(cube, x, y, i);
	return sum;
}

int histogram_cube_sum_at(const HistogramCube* cube, IntPoint at) {
	return histogram_cube_sum(cube, at.x, at.y);
}

void histogram_cube_set(HistogramCube* cube, int x, int y, int z, int value) {
	cube->counts[offset(cube, x, y, z)] = value;
}

void histogram_cube_set_at(HistogramCube* cube, IntPoint at, int z, int value) {
	histogram_cube_set(cube, at.x, at.y, z, value);
}

void histogram_cube_add(HistogramCube* cube, int x, int y, int z, int value) {
	cube->counts[offset(cube, x, y, z)] += value;
}

void histogram_cube_add_at(HistogramCube* cube, IntPoint at, int z, int value) {
	histogram_cube_add(cube, at.x, at.y, z, value);
}

void histogram_cube_increment(HistogramCube* cube, int x, int y, int z) {
	histogram_cube_add(cube, x, y, z, 1);
}

void histogram_cube_increment_at(HistogramCube* cube, IntPoint at, int z) {
	histogram_cube_increment(cube, at.x, at.y, z);
}

IntPoint intpoint_add(IntPoint a, IntPoint b) {
    return (IntPoint){ a.x + b.x, a.y + b.y };
}

bool blockgrid_contains(const BlockGrid* grid, IntPoint p) {
    return p.x >= 0 && p.y >= 0 &&
           p.x < grid->blocks.x && p.y < grid->blocks.y;
}

HistogramCube histogramcube_smooth(const BlockMap* blocks, const HistogramCube* input) {
    
    // HistogramCube output = create_histogram_cube_from_point(blocks->secondary.blocks, input->bins);

    #undef printf
                #define printf printf
    printf("blocks->secondary.blocks.x: %d, blocks->secondary.blocks.y: %d\n",blocks->secondary.blocks.x,blocks->secondary.blocks.y);
    #define printf(...)

    HistogramCube output;
    output.width=8; output.height=8; output.bins=256;
    for(int i=0;i<8*8*256;i++)
    {
        smooth_hist_array[i]=0;
    }

    output.counts = smooth_hist_array;

    IntPoint blocksAround[] = {
        {0, 0}, {-1, 0}, {0, -1}, {-1, -1}
    };

    for (int y = 0; y < blocks->secondary.blocks.y; ++y) {
        for (int x = 0; x < blocks->secondary.blocks.x; ++x) {
            IntPoint corner = {x, y};

            for (int i = 0; i < 4; ++i) {
                IntPoint relative = blocksAround[i];
                IntPoint block = intpoint_add(corner, relative);

                // Check if the block in the neighborhood of the sencodary block, is within the primary blockgrid
                if (blockgrid_contains(&blocks->primary, block)) {
                    for (int bin = 0; bin < input->bins; ++bin) {
                        int value = histogram_cube_get_at(input, block, bin);
                        histogram_cube_add_at(&output, corner, bin, value);
                    }
                }
            }
        }
    }

    // Optional: Logging or visualization
    print_histogram_cube(&output); // if you want to inspect

    return output;
}

typedef struct {
    int width;
    int height;
    bool* cells;
} BooleanMatrix;

// Constructor from dimensions
BooleanMatrix create_boolean_matrix(int width, int height) {
    BooleanMatrix matrix;
    matrix.width = width;
    matrix.height = height;
    printf("Creating BooleanMatrix with width: %d, height: %d\n", width, height);
    matrix.cells = (bool*)(malloc(width * height * sizeof(bool)));
    for(int i=0;i<width*height;i++)
    {
        matrix.cells[i] = false;  // Initialize all cells to false
    }
    printf("Created matrix\n");
    return matrix;
}

// Constructor from dimensions
BooleanMatrix* create_boolean_matrix_pointer(int width, int height) {
    BooleanMatrix* matrix=(BooleanMatrix*)(malloc(sizeof(BooleanMatrix)));
    matrix->width = width;
    matrix->height = height;
    printf("Creating BooleanMatrix with width: %d, height: %d\n", width, height);
    matrix->cells = (bool*)(malloc(width * height * sizeof(bool)));
    for(int i=0;i<width*height;i++)
    {
        matrix->cells[i] = false;  // Initialize all cells to false
    }
    printf("Created matrix\n");
    return matrix;
}

// Constructor from IntPoint
BooleanMatrix create_boolean_matrix_from_point(IntPoint size) {
    return create_boolean_matrix(size.x, size.y);
}

// Copy constructor
BooleanMatrix copy_boolean_matrix(BooleanMatrix* other) {
    BooleanMatrix matrix = create_boolean_matrix(other->width, other->height);
    memcpy(matrix.cells, other->cells, other->width * other->height * sizeof(bool));
    return matrix;
}

// Offset helper
int boolean_matrix_offset(BooleanMatrix* m, int x, int y) {
    return y * m->width + x;
}

// Get
bool boolean_matrix_get(BooleanMatrix* m, int x, int y) {
    return m->cells[boolean_matrix_offset(m, x, y)];
}

bool boolean_matrix_get_point(BooleanMatrix* m, IntPoint at) {
    return boolean_matrix_get(m, at.x, at.y);
}

bool boolean_matrix_get_fallback(BooleanMatrix* m, int x, int y, bool fallback) {
    if (x < 0 || y < 0 || x >= m->width || y >= m->height)
        return fallback;
    return boolean_matrix_get(m, x, y);
}

bool boolean_matrix_get_point_fallback(BooleanMatrix* m, IntPoint at, bool fallback) {
    return boolean_matrix_get_fallback(m, at.x, at.y, fallback);
}

// Set
void boolean_matrix_set(BooleanMatrix* m, int x, int y, bool value) {
    m->cells[boolean_matrix_offset(m, x, y)] = value ? true : false;
    // printf("m->cells[%d] set to %s\n", boolean_matrix_offset(m, x, y), value ? "true" : "false");
}

void boolean_matrix_set_point(BooleanMatrix* m, IntPoint at, bool value) {
    boolean_matrix_set(m, at.x, at.y, value);
}

bool boolean_matrix_get_with_fallback(BooleanMatrix* matrix, int x, int y, bool fallback) {
    if (x < 0 || y < 0 || x >= matrix->width || y >= matrix->height)
        return fallback;
    return matrix->cells[y * matrix->width + x];
}


// Invert all cells
void boolean_matrix_invert(BooleanMatrix* m) {
    int total = m->width * m->height;
    for (int i = 0; i < total; ++i)
        m->cells[i] = !m->cells[i];
}

// Merge another matrix using OR
void boolean_matrix_merge(BooleanMatrix* m, BooleanMatrix* other) {
    if (m->width != other->width || m->height != other->height) {
        fprintf(stderr, "BooleanMatrix.merge: dimensions do not match!\n");
        exit(EXIT_FAILURE);
    }
    int total = m->width * m->height;
    for (int i = 0; i < total; ++i)
        m->cells[i] |= other->cells[i];
}

int histogram_offset(HistogramCube* cube, int x, int y, int z) {
    return (y * cube->width + x) * cube->bins + z;
}

int histogram_get(HistogramCube* cube, IntPoint at, int z) {
    return cube->counts[histogram_offset(cube, at.x, at.y, z)];
}

int histogram_sum(HistogramCube* cube, IntPoint at) {
    int sum = 0;
    for (int i = 0; i < cube->bins; ++i)
        sum += histogram_get(cube, at, i);
    return sum;
}

// C version of compute_clipped_contrast
DoubleMatrix compute_clipped_contrast(BlockMap blocks, HistogramCube histogram) {
    DoubleMatrix result;
    result.width = blocks.primary.blocks.x;
    result.height = blocks.primary.blocks.y;
    result.data = (float*)(malloc(result.width * result.height * sizeof(float)));
    printf("result.width: %d, result.height: %d\n", result.width, result.height);
    printf("blocks.primary.blocks.x: %d, blocks.primary.blocks.y: %d\n", blocks.primary.blocks.x, blocks.primary.blocks.y);

    for (int y = 0; y < result.height; ++y) {
        for (int x = 0; x < result.width; ++x) {
            IntPoint block = {x, y};
            printf("Computing contrast for block: %d, %d\n", block.x, block.y);
            printf("histogram.bins: %d, histogram.width: %d, histogram.height: %d\n", histogram.bins, histogram.width, histogram.height);
            int volume = histogram_sum(&histogram, block);
            printf("Volume for block %d, %d: %d\n", block.x, block.y, volume);
            int clipLimit = (int)round(volume * CLIPPED_CONTRAST);
            int accumulator = 0;
            int lowerBound = histogram.bins - 1;
            for (int i = 0; i < histogram.bins; ++i) {
                accumulator += histogram_get(&histogram, block, i);
                if (accumulator > clipLimit) {
                    lowerBound = i;
                    break;
                }
            }
            printf("Lower bound for block %d, %d: %d\n", block.x, block.y, lowerBound);
            accumulator = 0;
            int upperBound = 0;
            for (int i = histogram.bins - 1; i >= 0; --i) {
                accumulator += histogram_get(&histogram, block, i);
                if (accumulator > clipLimit) {
                    upperBound = i;
                    break;
                }
            }
            printf("Upper bound for block %d, %d: %d\n", block.x, block.y, upperBound);
            float contrast = (upperBound - lowerBound) * (1.0 / (histogram.bins - 1));
            result.data[y * result.width + x] = contrast;
        }
    }


    // log_transparency("contrast", &result);
    return result;
}

// C version of AbsoluteContrastMask.compute
BooleanMatrix compute_absolute_contrast_mask(DoubleMatrix contrast) {
    BooleanMatrix result = create_boolean_matrix(contrast.width, contrast.height);
    printf("Created boolean matrix with width: %d, height: %d\n", result.width, result.height);
    for (int y = 0; y < contrast.height; ++y) {
        for (int x = 0; x < contrast.width; ++x) {
            if (contrast.data[y * contrast.width + x] < MIN_ABSOLUTE_CONTRAST)
                boolean_matrix_set(&result, x, y, true);
        }
    }
    // log_transparency("absolute-contrast-mask", &result);
    return result;
}

int compare_doubles_desc(const void* a, const void* b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    if (fb > fa) return 1;
    else if (fb < fa) return -1;
    else return 0;
}

DoubleMatrix create_double_matrix(int width, int height) {
    DoubleMatrix matrix;
    matrix.width = width;
    matrix.height = height;
    matrix.data = calloc(width * height, sizeof(float));
    return matrix;
}

int double_matrix_offset(DoubleMatrix* matrix, int x, int y) {
    return y * matrix->width + x;
}

float double_matrix_get(DoubleMatrix* matrix, int x, int y) {
    return matrix->data[double_matrix_offset(matrix, x, y)];
}

void double_matrix_set(DoubleMatrix* matrix, int x, int y, float value) {
    matrix->data[double_matrix_offset(matrix, x, y)] = value;
}

int intpoint_area(IntPoint p) {
    return p.x * p.y;
}

BooleanMatrix compute_relative_contrast_mask(DoubleMatrix contrast, BlockMap blocks) {
    int total = contrast.width * contrast.height;
    float* sorted = malloc(total * sizeof(float));
    memcpy(sorted, contrast.data, total * sizeof(float));
    // Sort block contrast values in descending order
    qsort(sorted, total, sizeof(float), compare_doubles_desc);
    // pixelsPerBlock = number of pixels / number of blocks
    int pixelsPerBlock = intpoint_area(blocks.pixels) / (blocks.primary.blocks.x * blocks.primary.blocks.y);
    int sampleCount = RELATIVE_CONTRAST_SAMPLE / pixelsPerBlock;
    if (sampleCount > total) sampleCount = total;
    int considered = (int)round(sampleCount * RELATIVE_CONTRAST_PERCENTILE);
    if (considered < 1) considered = 1;

    float sum = 0;
    for (int i = 0; i < considered; ++i)
        sum += sorted[i];
    free(sorted);

    float average = sum / considered;
    float limit = average * MIN_RELATIVE_CONTRAST;

    BooleanMatrix result = create_boolean_matrix(contrast.width, contrast.height);
    
    for (int y = 0; y < contrast.height; ++y) {
        for (int x = 0; x < contrast.width; ++x) {
            IntPoint block = {x, y};
            if (double_matrix_get(&contrast, block.x, block.y) < limit)
            {
                // printf("Setting mask at (%d, %d) to true, contrast: %f, limit: %f\n", x, y, double_matrix_get(&contrast, block), limit);
                boolean_matrix_set(&result, x, y, true);
                printf("result.cells[%d] = %d\n", boolean_matrix_offset(&result, x, y), boolean_matrix_get(&result, x, y));
            }
        }
    }
    // log_transparency("relative-contrast-mask", &result);
    for(int i = 0; i < result.width * result.height; ++i) {
        printf("result.cells[%d] = %d\n", i, result.cells[i]);
    }

    return result;
}

typedef struct {
    int width;
    int height;
    int* data;
} IntMatrix;

IntMatrix create_int_matrix(int width, int height) {
    IntMatrix matrix;
    matrix.width = width;
    matrix.height = height;
    matrix.data = calloc(width * height, sizeof(int));
    return matrix;
}

int int_matrix_offset(IntMatrix* m, int x, int y) {
    return y * m->width + x;
}

int int_matrix_get(IntMatrix* m, int x, int y) {
    return m->data[int_matrix_offset(m, x, y)];
}

void int_matrix_set(IntMatrix* m, int x, int y, int value) {
    m->data[int_matrix_offset(m, x, y)] = value;
}

int* compute_thresholds(int radius, float majority, int* out_length) {
    int window_size = (2 * radius + 1) * (2 * radius + 1);
    *out_length = window_size + 1;
    int* thresholds = malloc(sizeof(int) * (*out_length));
    for (int i = 0; i <= window_size; ++i)
        thresholds[i] = (int)ceil(majority * i);
    return thresholds;
}

BooleanMatrix vote_filter(BooleanMatrix* input, BooleanMatrix* mask, int radius, float majority, int borderDistance) {
    printf("In vote_filter: input width=%d, height=%d\n", input->width, input->height);
    IntPoint size = { input->width, input->height };
    IntRect rect = { borderDistance, borderDistance, size.x - 2 * borderDistance, size.y - 2 * borderDistance };

    int threshold_len;
    int* thresholds = compute_thresholds(radius, majority, &threshold_len);

    IntMatrix counts = create_int_matrix(size.x, size.y);
    BooleanMatrix output = create_boolean_matrix(size.x, size.y);

    for (int y = rect.y; y < rect.y + rect.height; ++y) {
        int superTop = y - radius - 1;
        int superBottom = y + radius;
        int yMin = y - radius < 0 ? 0 : y - radius;
        int yMax = y + radius >= size.y ? size.y - 1 : y + radius;
        int yRange = yMax - yMin + 1;

        for (int x = rect.x; x < rect.x + rect.width; ++x) {
            if (!mask || boolean_matrix_get(mask, x, y)) {
                int left = (x > 0) ? int_matrix_get(&counts, x - 1, y) : 0;
                int top = (y > 0) ? int_matrix_get(&counts, x, y - 1) : 0;
                int diag = (x > 0 && y > 0) ? int_matrix_get(&counts, x - 1, y - 1) : 0;

                int xMin = x - radius < 0 ? 0 : x - radius;
                int xMax = x + radius >= size.x ? size.x - 1 : x + radius;
                int ones = 0;

                if (left > 0 && top > 0 && diag > 0) {
                    ones = top + left - diag - 1;
                    int superLeft = x - radius - 1;
                    int superRight = x + radius;

                    if (superLeft >= 0 && superTop >= 0 && boolean_matrix_get(input, superLeft, superTop))
                        ++ones;
                    if (superLeft >= 0 && superBottom < size.y && boolean_matrix_get(input, superLeft, superBottom))
                        --ones;
                    if (superRight < size.x && superTop >= 0 && boolean_matrix_get(input, superRight, superTop))
                        --ones;
                    if (superRight < size.x && superBottom < size.y && boolean_matrix_get(input, superRight, superBottom))
                        ++ones;
                } else {
                    for (int ny = yMin; ny <= yMax; ++ny)
                        for (int nx = xMin; nx <= xMax; ++nx)
                            if (boolean_matrix_get(input, nx, ny))
                                ++ones;
                }

                int_matrix_set(&counts, x, y, ones + 1);

                if (ones >= thresholds[yRange * (xMax - xMin + 1)])
                    boolean_matrix_set(&output, x, y, true);
            }
        }
    }

    free(thresholds);
    free(counts.data);
    return output;
}

BooleanMatrix apply_vote_filter(BooleanMatrix* input) {
    return vote_filter(
        input,
        NULL,
        BLOCK_ERRORS_VOTE_RADIUS,
        BLOCK_ERRORS_VOTE_MAJORITY,
        BLOCK_ERRORS_VOTE_BORDER_DISTANCE
    );
}


// C version of compute function
BooleanMatrix compute_mask(BlockMap blocks, HistogramCube histogram) {
    DoubleMatrix contrast = compute_clipped_contrast(blocks, histogram);
    printf("contrast.width: %d, contrast.height: %d\n", contrast.width, contrast.height);
    for(int i=0;i<contrast.height;i++)
    {
        for(int j=0;j<contrast.width;j++)
        {
            printf("%f ",i,j,contrast.data[i*contrast.width+j]);
        }
    }

    BooleanMatrix mask = compute_absolute_contrast_mask(contrast);
    printf("mask.width: %d, mask.height: %d\n", mask.width, mask.height);
    for(int i=0;i<mask.height;i++)
    {
        for(int j=0;j<mask.width;j++)   
        {
            printf("%d ",boolean_matrix_get(&mask,j,i));
        }
        printf("\n");
    }

    // BooleanMatrix mask2;

    BooleanMatrix relative_contrast_mask= compute_relative_contrast_mask(contrast, blocks);
    printf("relative_contrast_mask.width: %d, relative_contrast_mask.height: %d\n", relative_contrast_mask.width, relative_contrast_mask.height);
    for (int i = 0; i < relative_contrast_mask.height; i++) {
        for (int j = 0; j < relative_contrast_mask.width; j++) {
            printf("%d ", boolean_matrix_get(&relative_contrast_mask, j, i));
        }
        printf("\n");
    }

    boolean_matrix_merge(&mask, &relative_contrast_mask);
    BooleanMatrix mask2 = apply_vote_filter(&mask);
    boolean_matrix_merge(&mask, &mask2);
    boolean_matrix_invert(&mask);

    mask2 = apply_vote_filter(&mask);
    boolean_matrix_merge(&mask, &mask2);

    mask2 = apply_vote_filter(&mask);
    boolean_matrix_merge(&mask, &mask2);

    mask2 = vote_filter(
        &mask,
        NULL,
        MASK_VOTE_RADIUS,
        MASK_VOTE_MAJORITY,
        MASK_VOTE_BORDER_DISTANCE
    );
    boolean_matrix_merge(&mask, &mask2);

    printf("fin mask.width: %d, fin mask.height: %d\n", mask.width, mask.height);
    for(int i=0;i<mask.height;i++)
    {
        for(int j=0;j<mask.width;j++)   
        {
            printf("%d ",boolean_matrix_get(&mask,j,i));
        }
        printf("\n");
    }
   
    // BooleanMatrix mask = compute_absolute_contrast_mask(contrast);
    // BooleanMatrix relmask = compute_relative_contrast_mask(contrast, blocks);
    // boolean_matrix_merge(&mask, &relmask);
    // log_transparency("combined-mask", mask);

    // BooleanMatrix f1 = filter(&mask);
    // boolean_matrix_merge(&mask, &f1);
    // boolean_matrix_invert(&mask);
    // BooleanMatrix f2 = filter(&mask);
    // boolean_matrix_merge(&mask, &f2);
    // BooleanMatrix f3 = filter(&mask);
    // boolean_matrix_merge(&mask, &f3);

    // BooleanMatrix voted = vote_filter(&mask, NULL, MASK_VOTE_RADIUS, MASK_VOTE_MAJORITY, MASK_VOTE_BORDER_DISTANCE);
    // boolean_matrix_merge(&mask, &voted);

    // log_transparency("filtered-mask", mask);
    free(contrast.data);
    free(relative_contrast_mask.cells);
    free(mask2.cells);

    return mask;
}

typedef struct {
    int width;
    int height;
    int bins;
    float** data;
} MappingTable;

MappingTable create_mapping_table(int width, int height, int bins) {
    printf("IN create_mapping_table, before creating table\n");
    printf("width: %d, height: %d, bins: %d\n", width, height, bins);
    // print_sram_usage();
    MappingTable table;
    table.width = width;
    table.height = height;
    table.bins = bins;
    // float->float
    table.data = malloc(width * height * sizeof(float*));
    for (int i = 0; i < width * height; ++i) {
        table.data[i] = calloc(bins, sizeof(float));
    }
    printf("AFter creating table\n");
    // print_sram_usage();
    return table;
}

float* mapping_table_get(MappingTable* table, IntPoint pt) {
    if (pt.x < 0 || pt.y < 0 || pt.x >= table->width || pt.y >= table->height) {
        fprintf(stderr, "mapping_table_get: Index out of bounds (%d, %d)\n", pt.x, pt.y);
        exit(EXIT_FAILURE);
    }
    return table->data[pt.y * table->width + pt.x];
}

void mapping_table_free(MappingTable* table) {
    for (int i = 0; i < table->width * table->height; ++i) {
        free(table->data[i]);
    }
    free(table->data);
}

// Computes square of a number
float sq(float value) {
    return value * value;
}

// Linear interpolation between two values
float interpolate(float start, float end, float position) {
    return start + position * (end - start);
}

// Bilinear interpolation using four corners and x/y positions
float interpolate_doubles(float bottomleft, float bottomright, float topleft, float topright, float x, float y) {
    float left = interpolate(topleft, bottomleft, y);
    float right = interpolate(topright, bottomright, y);
    return interpolate(left, right, x);
}

// Exponential interpolation (e.g., for equalization scaling)
float interpolate_exponential(float start, float end, float position) {
    return pow(end / start, position) * start;
}


// ImageEqualization function
DoubleMatrix equalize_image(BlockMap blocks, DoubleMatrix image, HistogramCube histogram, BooleanMatrix blockMask) {
    printf("In equalize_image\n");

    //float->float
    const float rangeMin = -1;
    const float rangeMax = 1;
    const float rangeSize = rangeMax - rangeMin;
    const float widthMax = rangeSize / 256.0 * MAX_EQUALIZATION_SCALING;
    const float widthMin = rangeSize / 256.0 * MIN_EQUALIZATION_SCALING;

    // float->float
    float* limitedMin = malloc(histogram.bins * sizeof(float));
    float* limitedMax = malloc(histogram.bins * sizeof(float));
    float* dequantized = malloc(histogram.bins * sizeof(float));

    for (int i = 0; i < histogram.bins; ++i) {
        limitedMin[i] = fmax(i * widthMin + rangeMin, rangeMax - (histogram.bins - 1 - i) * widthMax);
        limitedMax[i] = fmin(i * widthMax + rangeMin, rangeMax - (histogram.bins - 1 - i) * widthMin);
        dequantized[i] = i / (float)(histogram.bins - 1);
    }

    MappingTable mappings = create_mapping_table(blocks.secondary.blocks.x, blocks.secondary.blocks.y, histogram.bins);

    for (int by = 0; by < blocks.secondary.blocks.y; ++by) {
        for (int bx = 0; bx < blocks.secondary.blocks.x; ++bx) {
            IntPoint corner = {bx, by};
            float* mapping = mapping_table_get(&mappings, corner);

            if (boolean_matrix_get_with_fallback(&blockMask, bx, by, false) ||
                boolean_matrix_get_with_fallback(&blockMask, bx - 1, by, false) ||
                boolean_matrix_get_with_fallback(&blockMask, bx, by - 1, false) ||
                boolean_matrix_get_with_fallback(&blockMask, bx - 1, by - 1, false)) {

                int volume = histogram_cube_sum(&histogram, corner.x, corner.y);
                 
                float step = rangeSize / volume;
                float top = rangeMin;

                for (int i = 0; i < histogram.bins; ++i) {
                    // float->float
                    float band = histogram_cube_get(&histogram, corner.x,corner.y,i) * step;
                    float equalized = top + dequantized[i] * band;
                    
                    top += band;
                    if (equalized < limitedMin[i]) equalized = limitedMin[i];
                    if (equalized > limitedMax[i]) equalized = limitedMax[i];
                    mapping[i] = equalized;
                }
            }
        }
    }

    DoubleMatrix result = create_double_matrix(blocks.pixels.x, blocks.pixels.y);

    for (int by = 0; by < blocks.primary.blocks.y; ++by) {
        for (int bx = 0; bx < blocks.primary.blocks.x; ++bx) {
            IntPoint block = {bx, by};
            IntRect area = blockgrid_block_point(&blocks.primary, block);

            if (boolean_matrix_get(&blockMask, bx, by)) {
                float* topleft = mapping_table_get(&mappings, block);
                float* topright = mapping_table_get(&mappings, (IntPoint){block.x + 1, block.y});
                float* bottomleft = mapping_table_get(&mappings, (IntPoint){block.x, block.y + 1});
                float* bottomright = mapping_table_get(&mappings, (IntPoint){block.x + 1, block.y + 1});

                for (int y = area.y; y < area.y + area.height; ++y) {
                    for (int x = area.x; x < area.x + area.width; ++x) {
                        int depth = histogram_cube_constrain(&histogram, (int)(double_matrix_get(&image, x, y) * histogram.bins));
                        float rx = (x - area.x + 0.5) / area.width;
                        float ry = (y - area.y + 0.5) / area.height;
                        float value = interpolate_doubles(bottomleft[depth], bottomright[depth], topleft[depth], topright[depth], rx, ry);
                        double_matrix_set(&result, x, y, value);
                    }
                }
            } else {
                for (int y = area.y; y < area.y + area.height; ++y) {
                    for (int x = area.x; x < area.x + area.width; ++x) {
                        double_matrix_set(&result, x, y, -1);
                    }
                }
            }
        }
    }

    free(limitedMin);
    free(limitedMax);
    free(dequantized);
    mapping_table_free(&mappings);

    return result;
}

// float->float
/*DoublePointMatrx*/
typedef struct {
    int width;
    int height;
    // float* vectors; // Stores [x0, y0, x1, y1, ...]
    float* vectors;
} DoublePointMatrix;

DoublePointMatrix create_double_point_matrix(int width, int height) {
    printf("In create_double_point_matrix (width=%d, height=%d), before creating matrix\n", width, height);
    // print_sram_usage();
    DoublePointMatrix matrix;
    matrix.width = width;
    matrix.height = height;
    // float->float
    matrix.vectors = malloc(2 * width * height * sizeof(float));
    for(int i=0;i<2*width*height;i++)
    {
        matrix.vectors[i] = 0.0;  // Initialize all vectors to zero
    }

    printf("After creating matrix\n");
    // print_sram_usage();

    return matrix;
}


int double_point_matrix_offset(DoublePointMatrix* matrix, int x, int y) {
    return 2 * (y * matrix->width + x);
}

//float->float
void double_point_matrix_set(DoublePointMatrix* matrix, int x, int y, float px, float py) {
    int i = double_point_matrix_offset(matrix, x, y);
    matrix->vectors[i] = px;
    matrix->vectors[i + 1] = py;
}

//float->float
void double_point_matrix_add(DoublePointMatrix* matrix, int x, int y, float px, float py) {
    int i = double_point_matrix_offset(matrix, x, y);
    matrix->vectors[i] += px;
    matrix->vectors[i + 1] += py;
}


//float->float
typedef struct {
    float x;
    float y;
} DoublePoint;


// Constant
const DoublePoint DOUBLE_POINT_ZERO = {0.0f, 0.0f};

// Constructor
DoublePoint create_double_point(float x, float y) {
    DoublePoint p = {x, y};
    return p;
}

// Add two points
DoublePoint add_doublepoint(DoublePoint a, DoublePoint b) {
    return create_double_point(a.x + b.x, a.y + b.y);
}

// Negate a point
DoublePoint negate_doublepoint(DoublePoint p) {
    return create_double_point(-p.x, -p.y);
}

// Multiply point by scalar
DoublePoint multiply_doublepoint(DoublePoint p, float factor) {
    return create_double_point(factor * p.x, factor * p.y);
}



DoublePoint to_vector(float angle) {
    DoublePoint result;
    result.x = cos(angle);
    result.y = sin(angle);
    return result;
}


DoublePoint double_point_matrix_get(const DoublePointMatrix* m, int x, int y) {
    int index = double_point_matrix_offset(m, x, y);
    DoublePoint dp;
    dp.x = m->vectors[index];
    dp.y = m->vectors[index + 1];
    return dp;
}

float double_point_matrix_get_x(DoublePointMatrix* matrix, int x, int y) {
    return matrix->vectors[double_point_matrix_offset(matrix, x, y)];
}

float double_point_matrix_get_y(DoublePointMatrix* matrix, int x, int y) {
    return matrix->vectors[double_point_matrix_offset(matrix, x, y) + 1];
}

/*PixelWiseOrientation*/

float atan_doublepoint(DoublePoint vector) {
    float angle = atan2(vector.y, vector.x);
    return angle >= 0 ? angle : angle + PI2;
}

float atan_intpoint(IntPoint vector) {
    DoublePoint d = { vector.x, vector.y };
    return atan_doublepoint(d);
}

float atan_from_points(IntPoint center, IntPoint point) {
    IntPoint delta = { point.x - center.x, point.y - center.y };
    return atan_intpoint(delta);
}

DoublePoint to_doublepoint(IntPoint p) {
    DoublePoint result;
    result.x = (float)p.x;
    result.y = (float)p.y;
    return result;
}

float to_orientation(float angle) {
    return angle < M_PI ? 2.0 * angle : 2.0 * (angle - M_PI);
}

float from_orientation(float angle) {
    return 0.5 * angle;
}

float add_double_angle(float start, float delta) {
    float angle = start + delta;
    return angle < PI2 ? angle : angle - PI2;
}

float bucket_center(int bucket, int resolution) {
    return PI2 * (2 * bucket + 1) / (2.0 * resolution);
}

int quantize_angle(float angle, int resolution) {
    // printf("quantize_angle: angle=%f, INV_PI2: %f, resolution=%d\n", angle, INV_PI2, resolution);
    int result = (int)(angle * INV_PI2 * resolution);
    // printf("quantize_angle: result=%d\n", result);
    if (result < 0) return 0;
    else if (result >= resolution) return resolution - 1;
    else return result;
}

float opposite_angle(float angle) {
    return angle < M_PI ? angle + M_PI : angle - M_PI;
}

float distance_between_angles(float first, float second) {
    float delta = fabs(first - second);
    return delta <= M_PI ? delta : PI2 - delta;
}

float difference_between_angles(float first, float second) {
    float angle = first - second;
    return angle >= 0 ? angle : angle + PI2;
}

float complementary_angle(float angle) {
    float complement = PI2 - angle;
    return complement < PI2 ? complement : complement - PI2;
}

bool is_normalized_angle(float angle) {
    return angle >= 0 && angle < PI2;
}

int java_round(float x) {
    return (int)floor(x + 0.5);
}

// Round to IntPoint (assumes IntPoint is already defined)
IntPoint round_doublepoint(DoublePoint p) {
    IntPoint result = {
        // .x = (int)round(p.x),
        // .y = (int)round(p.y)
        .x = (int)java_round(p.x),
        .y = (int)java_round(p.y)
    };
    return result;
}

typedef struct {
    int start;
    int end;
} IntRange;

const IntRange INT_RANGE_ZERO = {0, 0};

int int_range_length(IntRange range) {
    return range.end - range.start;
}
typedef struct {
    IntPoint offset;
    DoublePoint orientation;
} ConsideredOrientation;

typedef struct {
    unsigned long long state;
} OrientationRandom;

// #define ORIENTATION_SPLIT 50
// #define ORIENTATIONS_CHECKED 20
#define ORIENTATION_SPLIT 30
#define ORIENTATIONS_CHECKED 10
#define MIN_ORIENTATION_RADIUS 2
#define MAX_ORIENTATION_RADIUS 6

void orientation_random_init(OrientationRandom* rng) {
    rng->state = 1610612741ULL * 1610612741ULL * 1610612741ULL;
}

float orientation_random_next(OrientationRandom* rng) {
    const unsigned long long PRIME = 1610612741ULL;
    const int BITS = 30;
    const unsigned long long MASK = (1ULL << BITS) - 1;
    const float SCALING = 1.0 / (1ULL << BITS);
    rng->state *= PRIME;
    return ((rng->state & MASK) + 0.5) * SCALING;
}

bool intpoint_equals(IntPoint a, IntPoint b) {
    return a.x == b.x && a.y == b.y;
}

ConsideredOrientation** plan_orientations() {
    printf("In planned_orientations\n");
    // print_sram_usage();
    OrientationRandom rng;
    orientation_random_init(&rng);

    ConsideredOrientation** splits = malloc(sizeof(ConsideredOrientation*) * ORIENTATION_SPLIT);

    for (int i = 0; i < ORIENTATION_SPLIT; ++i) {
        splits[i] = malloc(sizeof(ConsideredOrientation) * ORIENTATIONS_CHECKED);
        for (int j = 0; j < ORIENTATIONS_CHECKED; ++j) {
            ConsideredOrientation* sample = &splits[i][j];
            bool conflict;
            do {
                conflict = false;
                float angle = orientation_random_next(&rng) * M_PI;
                float distance = interpolate_exponential(MIN_ORIENTATION_RADIUS, MAX_ORIENTATION_RADIUS, orientation_random_next(&rng));
                sample->offset = round_doublepoint(multiply_doublepoint(to_vector(angle), distance));
                if ((sample->offset.x == 0 && sample->offset.y == 0) || sample->offset.y < 0)
                    conflict = true;
                else {
                    for (int k = 0; k < j; ++k) {
                        if (intpoint_equals(splits[i][k].offset, sample->offset)) {
                            conflict = true;
                            break;
                        }
                    }
                }
            } while (conflict);
            float direction = atan_doublepoint(to_doublepoint(sample->offset));
            float orient_angle = add_double_angle(to_orientation(direction), M_PI);
            sample->orientation = to_vector(orient_angle);
        }
    }

    printf("After planned_orientations\n");
    // print_sram_usage();
    return splits;
}

IntRange compute_mask_range(BooleanMatrix* mask, int y) {
    int first = -1, last = -1;
    for (int x = 0; x < mask->width; ++x) {
        if (boolean_matrix_get(mask, x, y)) {
            last = x;
            if (first < 0)
                first = x;
        }
    }
    IntRange result;
    if (first >= 0)
        result = (IntRange){ first, last + 1 };
    else
        result = (IntRange){ 0, 0 };
    return result;
}

IntRect blockmap_block(BlockMap* map, int bx, int by) {
    IntRect rect;
    // printf("blockmap_block: bx=%d, by=%d\n", bx, by);
        
    // printf("map->primary.blocks.x: %d, map->primary.blocks.y: %d\n", map->primary.blocks.x, map->primary.blocks.y);
    
    if (!map->primary.y) {
        fprintf(stderr, "Error: map->primary.y is NULL\n");
        exit(1);
    }

    // for(int i=0;i<map->primary.blocks.x;i++)
    // {
    //     printf("map->primary.x[%d]: %d\n", i, map->primary.x[i]);
    // }
    // for(int i=0;i<map->primary.blocks.y;i++)
    // {
    //     printf("map->primary.y[%d]: %d\n", i, map->primary.y[i]);
    // }

    rect.x = map->primary.x[bx];
    rect.y = map->primary.y[by];
    rect.width = map->primary.x[bx + 1] - map->primary.x[bx];
    rect.height = map->primary.y[by + 1] - map->primary.y[by];
    return rect;
}

DoublePointMatrix compute_pixelwise_orientations(DoubleMatrix* input, BooleanMatrix* mask, BlockMap* blocks) {
    ConsideredOrientation** neighbors = plan_orientations();
    DoublePointMatrix orientation = create_double_point_matrix(input->width, input->height);
    printf("In compute_pixelwise_orientations, after create_double_point_matrix\n");
    // print_sram_usage();

    for(int i=0;i<blocks->primary.corners.x;i++)
    {
        printf("BBB2locks.primary.x[%d]: %d\n",i,blocks->primary.x[i]);
    }
    for(int i=0;i<blocks->primary.corners.y;i++)
    {
        printf("BBB2locks.primary.y[%d]: %d\n",i,blocks->primary.y[i]);
    }

    for (int blockY = 0; blockY < blocks->primary.blocks.y; ++blockY) {
        IntRange range = compute_mask_range(mask, blockY);
        if (range.end > range.start) {
            IntRect left_rect = blockmap_block(blocks, range.start, blockY);
            IntRect right_rect = blockmap_block(blocks, range.end - 1, blockY);
            IntRange validX = (IntRange){ left_rect.x, right_rect.x + right_rect.width };

            IntRect base_rect = blockmap_block(blocks, 0, blockY);
            for (int y = base_rect.y; y < base_rect.y + base_rect.height; ++y) {
                for (int j = 0; j < ORIENTATIONS_CHECKED; ++j) {
                    ConsideredOrientation* neighbor = &neighbors[y % ORIENTATION_SPLIT][j];
                    int radius = fmax(abs(neighbor->offset.x), abs(neighbor->offset.y));
                    if (y - radius >= 0 && y + radius < input->height) {
                        IntRange x_range = {
                            fmax(radius, validX.start),
                            fmin(input->width - radius, validX.end)
                        };
                        for (int x = x_range.start; x < x_range.end; ++x) {
                            float before = double_matrix_get(input, x - neighbor->offset.x, y - neighbor->offset.y);
                            float at = double_matrix_get(input, x, y);
                            float after = double_matrix_get(input, x + neighbor->offset.x, y + neighbor->offset.y);
                            float strength = at - fmax(before, after);
                            if (strength > 0)
                                double_point_matrix_add(&orientation, x, y,
                                    neighbor->orientation.x * strength,
                                    neighbor->orientation.y * strength);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < ORIENTATION_SPLIT; ++i)
        free(neighbors[i]);
    free(neighbors);

    return orientation;
}


DoublePointMatrix aggregate_orientation(DoublePointMatrix* orientation, BlockMap* blocks, BooleanMatrix* mask) {
    IntPoint gridSize = blocks->primary.blocks;
    DoublePointMatrix sums = create_double_point_matrix(gridSize.x, gridSize.y);
    printf("In aggregate orientation\n");

    for (int by = 0; by < gridSize.y; ++by) {
        for (int bx = 0; bx < gridSize.x; ++bx) {
            if (boolean_matrix_get(mask, bx, by)) {
                IntRect area = blockmap_block(blocks, bx, by);
                for (int y = area.y; y < area.y + area.height; ++y) {
                    for (int x = area.x; x < area.x + area.width; ++x) {
                        DoublePoint dp = double_point_matrix_get(orientation, x, y);
                        IntPoint block = {bx, by};
                        // printf("(x: %d,y: %d): (block.x: %d, block.y: %d), (d.x: %f, d.y: %f)\n", x, y, block.x, block.y, dp.x, dp.y);
                        double_point_matrix_add(&sums, block.x, block.y, dp.x, dp.y);
                    }
                }
            }
        }
    }

    // If you want to log the result, insert your logging function here
    // log_double_point_matrix("block-orientation", &sums);

    return sums;
}


DoublePointMatrix smooth_orientation(DoublePointMatrix orientation, BooleanMatrix* mask, int radius) {
    DoublePointMatrix smoothed = create_double_point_matrix(mask->width, mask->height);
    for (int y = 0; y < mask->height; ++y) {
        for (int x = 0; x < mask->width; ++x) {
            IntPoint block = {x, y};
            if (boolean_matrix_get(mask, block.x, block.y)) {
                for (int dy = -radius; dy <= radius; ++dy) {
                    for (int dx = -radius; dx <= radius; ++dx) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && ny >= 0 && nx < mask->width && ny < mask->height) {
                            IntPoint neighbor = {nx, ny};
                            if (boolean_matrix_get(mask, neighbor.x, neighbor.y)) {
                                DoublePoint v = double_point_matrix_get(&orientation, neighbor.x, neighbor.y);
                                double_point_matrix_add(&smoothed, block.x, block.y, v.x, v.y);
                            }
                        }
                    }
                }
            }
        }
    }
    return smoothed;
}

DoubleMatrix compute_angles(DoublePointMatrix* vectors, BooleanMatrix* mask) {
    DoubleMatrix angles = create_double_matrix(mask->width, mask->height);
    for (int y = 0; y < mask->height; ++y) {
        for (int x = 0; x < mask->width; ++x) {
            if (boolean_matrix_get(mask, x, y)) {
                DoublePoint dp = double_point_matrix_get(vectors, x, y);
                float angle = atan_doublepoint(dp);
                IntPoint p = {x, y};
                double_matrix_set(&angles, p.x, p.y, angle);
            }
        }
    }
    return angles;
}

DoubleMatrix compute_orientation(DoubleMatrix image, BooleanMatrix mask, BlockMap blocks) {
    DoublePointMatrix accumulated = compute_pixelwise_orientations(&image, &mask, &blocks);
    printf("accumulated.width: %d, accumulated.height: %d\n", accumulated.width, accumulated.height);
    // for(int i=0;i<accumulated.width;i++)
    // {
    //     for(int j=0;j<accumulated.height;j++)
    //     {
    //         DoublePoint dp = double_point_matrix_get(&accumulated, i, j);
    //         printf("(%d, %d): (%f, %f)\n", i, j, dp.x, dp.y);
    //     }
    // }

    DoublePointMatrix byBlock = aggregate_orientation(&accumulated, &blocks, &mask);
    free(accumulated.vectors);

    printf("blocked.width: %d, blocked.height: %d\n", byBlock.width, byBlock.height);
    // for(int i=0;i<byBlock.width;i++)
    // {   
    //     for(int j=0;j<byBlock.height;j++)
    //     {
    //         DoublePoint dp = double_point_matrix_get(&byBlock, j, i);
    //         printf("(%d, %d): (%f, %f)\n", i, j, dp.x, dp.y);
    //     }
    // }
    DoublePointMatrix smooth = smooth_orientation(byBlock, &mask, ORIENTATION_SMOOTHING_RADIUS);
    free(byBlock.vectors);

    DoubleMatrix orientation_fin =  compute_angles(&smooth, &mask);
    free(smooth.vectors);

    printf("Orientation computed: width=%d, height=%d\n", orientation_fin.width, orientation_fin.height);
    // for (int i = 0; i < orientation_fin.height; ++i) {
    //     for (int j = 0; j < orientation_fin.width; ++j) {           
    //         printf("%f ", double_matrix_get(&orientation_fin, j, i));
    //     }
    //     printf("\n");   
    // }

    return orientation_fin;
}

/*//////////////  OrientedSmoothing ////////////////*/
float add_angles(float start, float delta) {
    float angle = start + delta;
    return (angle < PI2) ? angle : (angle - PI2);
}

IntPoint** generate_lines(int resolution, int radius, float step, int* out_line_lengths) {
    IntPoint** result = malloc(resolution * sizeof(IntPoint*));
    *out_line_lengths = 0;

    for (int i = 0; i < resolution; ++i) {
        IntPoint* line = malloc(256 * sizeof(IntPoint)); // max size guess
        int line_size = 0;
        line[line_size++] = (IntPoint){0, 0};

        float angle = from_orientation(bucket_center(i, resolution));
        DoublePoint direction = to_vector(angle);

        for (float r = radius; r >= 0.5; r /= step) {
            IntPoint sample = round_doublepoint(multiply_doublepoint(direction, r));
            if (!contains_intpoint(line, line_size, sample)) {
                line[line_size++] = sample;
                line[line_size++] = intpoint_negate(sample);
            }
        }

        result[i] = malloc(line_size * sizeof(IntPoint));
        memcpy(result[i], line, line_size * sizeof(IntPoint));
        out_line_lengths[i] = line_size;
        free(line);
    }

    return result;
}


DoubleMatrix smooth(DoubleMatrix input, DoubleMatrix orientation, BooleanMatrix mask, BlockMap* blocks, float angle, IntPoint** lines, int* line_lengths, int resolution) {
    DoubleMatrix output = create_double_matrix(input.width, input.height);

    // printf("Inside smmoth\n");
    // for(int i=0;i<orientation.width;i++)
    // {
    //     for(int j=0;j<orientation.height;j++)
    //     {
    //         printf("(%d, %d): %f\n", i, j, double_matrix_get(&orientation, i, j));
    //     }
    // }

    for (int by = 0; by < blocks->primary.blocks.y; ++by) {
        for (int bx = 0; bx < blocks->primary.blocks.x; ++bx) {
            if (boolean_matrix_get(&mask, bx, by)) {
                printf("Processing block (%d, %d)\n", bx, by);
                IntPoint block = {bx, by};
                float base_angle = double_matrix_get(&orientation, bx, by);
                float sum_angle = add_angles(base_angle, angle);
                int index = quantize_angle(sum_angle, resolution);
                
                IntPoint* line = lines[index];
                int line_len = line_lengths[index];
                // printf("line_len: %d, index: %d, base_angle: %f, sum_angle: %f\n", line_len, index, base_angle, sum_angle);

                IntRect target = blockmap_block(blocks, bx, by);
                for (int i = 0; i < line_len; ++i) {
                    IntPoint offset = line[i];
                    // printf("offset: (%d, %d)\n", offset.x, offset.y);
                    IntRect source = move_rect(target, offset);
                    // printf("source: (%d, %d, %d, %d)\n", source.x, source.y, source.width, source.height);
                    source = intersect_rect(source, (IntRect){0, 0, blocks->pixels.x, blocks->pixels.y});
                    // printf("source after intersection: (%d, %d, %d, %d)\n", source.x, source.y, source.width, source.height);
                    IntRect target_moved = move_rect(source, intpoint_negate(offset));
                    // printf("target_moved: (%d, %d, %d, %d)\n", target_moved.x, target_moved.y, target_moved.width, target_moved.height);
                    for (int y = target_moved.y; y < target_moved.y + target_moved.height; ++y)
                        for (int x = target_moved.x; x < target_moved.x + target_moved.width; ++x)
                            double_matrix_add(&output, x, y, double_matrix_get(&input, x + offset.x, y + offset.y));
                }

                for (int y = target.y; y < target.y + target.height; ++y)
                    for (int x = target.x; x < target.x + target.width; ++x)
                        double_matrix_multiply(&output, x, y, 1.0 / line_len);
                
                // printf("Block (%d, %d) processed. Output:\n",bx,by);
                // for(int i=0;i<output.width;i++)
                // {
                //     for(int j=0;j<output.height;j++)
                //     {
                //         printf("%f ", double_matrix_get(&output, i, j));
                //     }
                //     printf("\n");
                // }
            }
        }
    }

    return output;
}

DoubleMatrix oriented_smoothing_parallel(DoubleMatrix input, DoubleMatrix orientation, BooleanMatrix mask, BlockMap* blocks) {
    int resolution = PARALLEL_SMOOTHING_RESOLUTION;
    int radius = PARALLEL_SMOOTHING_RADIUS;
    float step = PARALLEL_SMOOTHING_STEP;
    
    // printf("Inside parallel\n");
    // printf("orientation.width: %d, orientation.height: %d\n",orientation.width,orientation.height);

    // for(int i=0;i<orientation.width;i++)
    // {
    //     for(int j=0;j<orientation.height;j++)
    //     {
    //         printf("(%d, %d): %f\n", i, j, double_matrix_get(&orientation, i, j));
    //     }
    // }

    int* line_lengths = malloc(resolution * sizeof(int));
    IntPoint** lines = generate_lines(resolution, radius, step, line_lengths);
    for (int i = 0; i < resolution; ++i) {
        printf("lines Orientation %d:\n", i);
        for (int j = 0; j < line_lengths[i]; ++j) {
            printf("(%d, %d) ", lines[i][j].x, lines[i][j].y);
        }
        printf("\n");
    }
    
    DoubleMatrix result = smooth(input, orientation, mask, blocks, 0.0, lines, line_lengths, resolution);

    // free lines
    for (int i = 0; i < resolution; ++i)
        free(lines[i]);
    free(lines);
    free(line_lengths);

    return result;
}

DoubleMatrix oriented_smoothing_orthogonal(DoubleMatrix input, DoubleMatrix orientation, BooleanMatrix mask, BlockMap* blocks) {
    int resolution = ORTHOGONAL_SMOOTHING_RESOLUTION;
    int radius = ORTHOGONAL_SMOOTHING_RADIUS;
    float step = ORTHOGONAL_SMOOTHING_STEP;

    int* line_lengths = malloc(resolution * sizeof(int));
    IntPoint** lines = generate_lines(resolution, radius, step, line_lengths);
    DoubleMatrix result = smooth(input, orientation, mask, blocks, M_PI, lines, line_lengths, resolution);

    // free lines
    for (int i = 0; i < resolution; ++i)
        free(lines[i]);
    free(lines);
    free(line_lengths);

    return result;
}

////////// Binarized image ///////////////
IntRect BlockGrid_block(BlockGrid* grid, int atX, int atY) {
    int left = grid->x[atX];
    int top = grid->y[atY];
    int right = grid->x[atX + 1];
    int bottom = grid->y[atY + 1];

    IntRect rect;
    rect.x = left;
    rect.y = top;
    rect.width = right - left;
    rect.height = bottom - top;
    return rect;
}


#define IDX(width, x, y) ((y) * (width) + (x))

bool get_boolean(const BooleanMatrix* m, int x, int y) {
    return m->cells[IDX(m->width, x, y)];
}

void set_boolean(BooleanMatrix* m, int x, int y, bool value) {
    m->cells[IDX(m->width, x, y)] = value;
}


BooleanMatrix binarize(const DoubleMatrix* input, const DoubleMatrix* baseline, const BooleanMatrix* mask, const BlockMap* blocks) {
    IntPoint size = {input->width, input->height};
    BooleanMatrix binarized = create_boolean_matrix(size.x, size.y);

    for (int by = 0; by < blocks->primary.blocks.y; ++by) {
        for (int bx = 0; bx < blocks->primary.blocks.x; ++bx) {
            IntPoint block = {bx, by};

            if (get_boolean(mask, block.x, block.y)) {
                // printf("bin Processing block (%d, %d)\n", block.x, block.y);
                IntRect rect = BlockGrid_block(&blocks->primary, block.x, block.y);
                // printf("BlockRect: (%d, %d, %d, %d)\n", rect.x, rect.y, rect.width, rect.height);

                for (int y = rect.y; y < rect.y + rect.height; ++y) {
                    for (int x = rect.x; x < rect.x + rect.width; ++x) {
                        float diff = input->data[IDX(input->width, x, y)] - baseline->data[IDX(input->width, x, y)];
                        if (diff > 0)
                        {
                            // printf("Setting binarized at (%d, %d) to true\n", x, y);
                            set_boolean(&binarized, x, y, true);
                        }
                    }
                }
            }
        }
    }

    return binarized;
}

void set_boolean_matrix(BooleanMatrix* matrix, int x, int y, bool value) {
    if (x >= 0 && x < matrix->width && y >= 0 && y < matrix->height) {
        matrix->cells[y * matrix->width + x] = value;
    }
}

void free_boolean_matrix(BooleanMatrix* matrix) {
    if (matrix->cells != NULL) {
        free(matrix->cells);
        matrix->cells = NULL;
    }
    matrix->width = 0;
    matrix->height = 0;
}

bool get_boolean_matrix(const BooleanMatrix* matrix, int x, int y) {
    printf("x: %d, y: %d, width: %d, height: %d\n", x, y, matrix->width, matrix->height);
    if (x >= 0 && x < matrix->width && y >= 0 && y < matrix->height) {
        return matrix->cells[y * matrix->width + x];
    }
    return false;  // or handle error differently
}

bool get_boolean_matrix_safe(BooleanMatrix* matrix, int x, int y) {
    if (x < 0 || x >= matrix->width || y < 0 || y >= matrix->height)
        return false;
    return matrix->cells[y * matrix->width + x];
}

void binarize_cleanup(BooleanMatrix* binary, const BooleanMatrix* mask) {
    printf("In binarize_cleanup\n");
    IntPoint size = { binary->width, binary->height };

    // Invert binary
    BooleanMatrix inverted = create_boolean_matrix(size.x, size.y);
    for (int y = 0; y < size.y; ++y) {
        for (int x = 0; x < size.x; ++x) {
            bool value = get_boolean(binary, x, y);
            set_boolean(&inverted, x, y, !value);
        }
    }

    printf("inverted.width: %d, inverted.height: %d\n", inverted.width, inverted.height);

    free_boolean_matrix(&inverted);

    // islands = VoteFilter.vote(inverted, mask, ...)
    BooleanMatrix islands = vote_filter(
        &inverted,
        mask,
        BINARIZED_VOTE_RADIUS,
        BINARIZED_VOTE_MAJORITY,
        BINARIZED_VOTE_BORDER_DISTANCE
    );

    printf("islands.width: %d, islands.height: %d\n", islands.width, islands.height);

    // holes = VoteFilter.vote(binary, mask, ...)
    BooleanMatrix holes = vote_filter(
        binary,
        mask,
        BINARIZED_VOTE_RADIUS,
        BINARIZED_VOTE_MAJORITY,
        BINARIZED_VOTE_BORDER_DISTANCE
    );

    printf("holes.width: %d, holes.height: %d\n", holes.width, holes.height);

    // binary = binary && !islands || holes
    for (int y = 0; y < size.y; ++y) {
        for (int x = 0; x < size.x; ++x) {
            bool bin = get_boolean(binary, x, y);
            bool isl = get_boolean(&islands, x, y);
            bool hol = get_boolean(&holes, x, y);
            set_boolean(binary, x, y, (bin && !isl) || hol);
        }
    }

    // Remove diagonal crosses
    remove_crosses(binary);

    // Optional logging
    // log_boolean_matrix("filtered-binary-image", binary);

    // Cleanup
    free_boolean_matrix(&islands);
    free_boolean_matrix(&holes);
}


void remove_crosses(BooleanMatrix* input) {
    IntPoint size = {input->width, input->height};
    bool any = true;
    while (any) {
        any = false;
        for (int y = 0; y < size.y - 1; ++y) {
            for (int x = 0; x < size.x - 1; ++x) {
                bool a = get_boolean(input, x, y);
                bool b = get_boolean(input, x + 1, y + 1);
                bool c = get_boolean(input, x, y + 1);
                bool d = get_boolean(input, x + 1, y);
                if ((a && b && !c && !d) || (c && d && !a && !b)) {
                    set_boolean(input, x, y, false);
                    set_boolean(input, x, y + 1, false);
                    set_boolean(input, x + 1, y, false);
                    set_boolean(input, x + 1, y + 1, false);
                    any = true;
                }
            }
        }
    }
}

BooleanMatrix invert(BooleanMatrix* binary, BooleanMatrix* mask) {
    IntPoint size = {binary->width, binary->height};
    BooleanMatrix inverted = create_boolean_matrix(size.x, size.y);
    for (int y = 0; y < size.y; ++y) {
        for (int x = 0; x < size.x; ++x) {
            bool val = !get_boolean(binary, x, y) && get_boolean(mask, x, y);
            set_boolean(&inverted, x, y, val);
        }
    }
    return inverted;
}




////////////////////////////////

//////////////////////
BooleanMatrix pixelwise(BooleanMatrix* mask, BlockMap* blocks) {
    int block_width = blocks->primary.blocks.x;
    int block_height = blocks->primary.blocks.y;

    BooleanMatrix pixelized = create_boolean_matrix(blocks->pixels.x, blocks->pixels.y);

    for (int by = 0; by < block_height; ++by) {
        for (int bx = 0; bx < block_width; ++bx) {
            if (get_boolean_matrix(mask, bx, by)) {
                IntRect rect = BlockGrid_block(&blocks->primary, bx, by);
                for (int y = rect.y; y < rect.y + rect.height; ++y) {
                    for (int x = rect.x; x < rect.x + rect.width; ++x) {
                        set_boolean_matrix(&pixelized, x, y, true);
                    }
                }
            }
        }
    }

    // No TransparencySink in C, you can log if needed:
    // print_boolean_matrix(&pixelized); // optional for debug
    return pixelized;
}

BooleanMatrix shrink(BooleanMatrix* mask, int amount) {
    IntPoint size = {mask->width, mask->height};
    BooleanMatrix shrunk = create_boolean_matrix(size.x, size.y);

    for (int y = amount; y < size.y - amount; ++y) {
        for (int x = amount; x < size.x - amount; ++x) {
            bool val =
                get_boolean(mask, x, y - amount) &&
                get_boolean(mask, x, y + amount) &&
                get_boolean(mask, x - amount, y) &&
                get_boolean(mask, x + amount, y);
            set_boolean(&shrunk, x, y, val);
        }
    }

    return shrunk;
}

BooleanMatrix inner(BooleanMatrix* outer) {
    printf("In inner mask computation\n");
    IntPoint size = {outer->width, outer->height};
    BooleanMatrix inner = create_boolean_matrix(size.x, size.y);

    // Copy central region
    for (int y = 1; y < size.y - 1; ++y) {
        for (int x = 1; x < size.x - 1; ++x) {
            bool val = get_boolean(outer, x, y);
            set_boolean(&inner, x, y, val);
        }
    }

    // Shrink inner by 1 if necessary
    if (INNER_MASK_BORDER_DISTANCE >= 1) {
        BooleanMatrix temp = shrink(&inner, 1);
        free_boolean_matrix(&inner);
        inner = temp;
        // free_boolean_matrix(temp);
    }

    int total = 1;
    for (int step = 1; total + step <= INNER_MASK_BORDER_DISTANCE; step *= 2) {
        BooleanMatrix temp = shrink(&inner, step);
        free_boolean_matrix(&inner);
        inner = temp;
        // free_boolean_matrix(temp);
        total += step;
    }

    if (total < INNER_MASK_BORDER_DISTANCE) {
        int remaining = INNER_MASK_BORDER_DISTANCE - total;
        BooleanMatrix temp = shrink(&inner, remaining);
        free_boolean_matrix(&inner);
        inner = temp;
    }

    // log_boolean_matrix("inner-mask", &inner); // Optional logging
    return inner;
}

//////////// Skeleton ////////////////////////
typedef enum {
    SKELETON_RIDGES,
    SKELETON_VALLEYS
} SkeletonType;

static const char* SkeletonTypePrefix[] = {
    [SKELETON_RIDGES] = "ridges-",
    [SKELETON_VALLEYS] = "valleys-"
};

////////////// SkeletonRidge and SkeletonMinutiae
struct SkeletonRidge; // forward declaration

typedef struct SkeletonMinutia {
    IntPoint position;
    struct SkeletonRidge** ridges;
    int ridge_count;
    int ridge_capacity;
} SkeletonMinutia;

typedef struct SkeletonRidge {
    IntPoint* points;
    int point_count;
    int point_capacity;

    struct SkeletonRidge* reversed;
    SkeletonMinutia* startMinutia;
    SkeletonMinutia* endMinutia;

    int is_view; 
    unsigned char freed;
} SkeletonRidge;


typedef struct {
    SkeletonType type;
    IntPoint size;
    SkeletonMinutia** minutiae;  // dynamically allocated array
    int count;
    int capacity;
} Skeleton;

///////

static inline IntPoint ridge_point_at(const SkeletonRidge* h, int i) {
    const SkeletonRidge* b = h->is_view ? h->reversed : h;
    // bounds check! (return {0,0} or assert on OOB)
    return h->is_view ? b->points[b->point_count - 1 - i] : b->points[i];
}

static inline SkeletonRidge* base_of(SkeletonRidge* r) {
    if (!r) return NULL;
    return (r->is_view && r->reversed) ? r->reversed : r;
}

void expand_size(SkeletonRidge* ridge) {
    SkeletonRidge* base = base_of(ridge);
    if (base->point_count == base->point_capacity) {
        base->point_capacity = base->point_capacity * 2 + 1;
        base->points = realloc(base->points, sizeof(IntPoint) * base->point_capacity);
        if (base->reversed) 
        {
            base->reversed->point_count = base->point_count;
            base->reversed->point_capacity = base->point_capacity;
        }
    }
}

/////////

void init_skeleton_minutia(SkeletonMinutia* m, IntPoint position) {
    m->position = position;
    m->ridge_capacity = 4;
    m->ridge_count = 0;
    m->ridges = malloc(sizeof(SkeletonRidge*) * m->ridge_capacity);
}

void free_skeleton_minutia(SkeletonMinutia* m) {
    free(m->ridges);
}

// m is assumed to have all base_of originally
// r is also assumed to be base_of
bool minutia_contains_ridge(SkeletonMinutia* m, SkeletonRidge* r) {
    for (int i = 0; i < m->ridge_count; ++i)
        if (m->ridges[i] == r)
            return true;
    return false;
}

void minutia_attach_start(SkeletonMinutia* m, SkeletonRidge* r); // forward

void minutia_add_ridge(SkeletonMinutia* m, SkeletonRidge* r) {
    if (!minutia_contains_ridge(m, r)) {
        if (m->ridge_count == m->ridge_capacity) {
            // m->ridge_capacity *= 2;
            m->ridge_capacity = m->ridge_capacity * 3 / 2 + 1;

            m->ridges = realloc(m->ridges, sizeof(SkeletonRidge*) * m->ridge_capacity);
        }
        m->ridges[m->ridge_count++] = r;
        minutia_attach_start(m, r); // call after add
    }
}

void minutia_remove_ridge(SkeletonMinutia* m, SkeletonRidge* r) {
    for (int i = 0; i < m->ridge_count; ++i) {
        if (m->ridges[i] == r) {
            for (int j = i + 1; j < m->ridge_count; ++j)
                m->ridges[j - 1] = m->ridges[j];
            m->ridge_count--;
            break;
        }
    }
}

void ridge_set_start(SkeletonRidge* ridge, SkeletonMinutia* value);
void ridge_set_end(SkeletonRidge* ridge, SkeletonMinutia* value);

void minutia_attach_start(SkeletonMinutia* m, SkeletonRidge* r) {
    if (!minutia_contains_ridge(m, r)) {
        minutia_add_ridge(m, r);
        ridge_set_start(r, m);
    }
}

void minutia_detach_start(SkeletonMinutia* m, SkeletonRidge* r) {
    if (minutia_contains_ridge(m, r)) {
        minutia_remove_ridge(m, r);
        if (r->startMinutia == m)
            ridge_set_start(r, NULL);
    }
}

void reverse_ridge_points(SkeletonRidge* ridge) {
    // SkeletonRidge* rev = ridge->reversed;
    // rev->point_capacity = ridge->point_count;
    // rev->point_count = ridge->point_count;
    // rev->points = malloc(sizeof(IntPoint) * rev->point_capacity);

    // for (int i = 0; i < ridge->point_count; ++i) {
    //     rev->points[i] = ridge->points[ridge->point_count - 1 - i];
    // }

    SkeletonRidge* base = base_of(ridge);

    if (base->reversed) 
    {
        base->reversed->point_count = base->point_count;
        base->reversed->point_capacity = base->point_capacity;
    }
}


SkeletonRidge* create_ridge() {
    SkeletonRidge* r = malloc(sizeof(SkeletonRidge));
    r->point_capacity = 8;
    r->point_count = 0;
    r->points = malloc(sizeof(IntPoint) * r->point_capacity);
    r->is_view = 0; // This is the real one
    r->freed = 0;
    
    r->reversed = malloc(sizeof(SkeletonRidge));
    r->reversed->point_capacity = 8;
    r->reversed->point_count = 0;
    // r->reversed->points = malloc(sizeof(IntPoint) * r->point_capacity); // will allocate after reversal
    r->reversed->reversed = r;
    r->reversed->is_view = 1; // This is the view
    r->reversed->freed = 0;

    r->startMinutia = NULL;
    r->endMinutia = NULL;
    r->reversed->startMinutia = NULL;
    r->reversed->endMinutia = NULL;

    return r;
}

void ridge_set_start(SkeletonRidge* ridge, SkeletonMinutia* value) {
    // Skip if value minutiae is already on ridge
    if (ridge->startMinutia != value) {
        // If ridge was already connected to some minutia, detach it
        // Remove the ridge from the old minutaie detachFrom's ridge list using minutia_detach_start
        if (ridge->startMinutia != NULL) {
            SkeletonMinutia* detachFrom = ridge->startMinutia;
            ridge->startMinutia = NULL;
            minutia_detach_start(detachFrom, ridge);
        }

        // New startMinutiae for ridge is value
        ridge->startMinutia = value;
        // Add the ridge to the new minutia’s list (if non-null) via minutia_attach_start.
        if (value != NULL)
            minutia_attach_start(value, ridge);
        ridge->reversed->endMinutia = value;
    }
}

void ridge_set_end(SkeletonRidge* ridge, SkeletonMinutia* value) {
    if (ridge->endMinutia != value) {
        printf("Setting endMinutia\n");
        ridge->endMinutia = value;
        ridge_set_start(ridge->reversed, value);
    }
}

void ridge_detach(SkeletonRidge* ridge) {
    ridge_set_start(ridge, NULL);
    ridge_set_end(ridge, NULL);
}

////////////////// SkeletonTracing
#define INITIAL_HASHMAP_CAPACITY 64


bool point_equals(IntPoint a, IntPoint b) {
    return (a.x == b.x && a.y == b.y);
}

typedef struct {
    IntPoint* keys;
    void** values;
    int size;
    int capacity;
} HashMap;

HashMap* create_hash_map() {
    HashMap* map = malloc(sizeof(HashMap));
    map->capacity = INITIAL_HASHMAP_CAPACITY;
    map->size = 0;
    map->keys = malloc(sizeof(IntPoint) * map->capacity);
    map->values = malloc(sizeof(void*) * map->capacity);
    return map;
}

void* hash_map_get(HashMap* map, IntPoint key) {
    for (int i = 0; i < map->size; ++i) {
        if (point_equals(map->keys[i], key))
            return map->values[i];
    }
    return NULL;
}

void hash_map_put(HashMap* map, IntPoint key, void* value) {
    for (int i = 0; i < map->size; ++i) {
        if (point_equals(map->keys[i], key)) {
            map->values[i] = value;
            return;
        }
    }
    if (map->size == map->capacity) {
        // map->capacity *= 2;
        map->capacity = map->capacity * 3 / 2 + 1;
        map->keys = realloc(map->keys, sizeof(IntPoint) * map->capacity);
        map->values = realloc(map->values, sizeof(void*) * map->capacity);
    }
    map->keys[map->size] = key;
    map->values[map->size] = value;
    map->size++;
}


// IntPointArray definition
typedef struct IntPointArray {
    IntPoint* data;
    int size;
    int capacity;
} IntPointArray;

void free_int_point_array(IntPointArray* array) {
    if (array) {
        free(array->data);
        free(array);
    }
}

void free_minutia_link_map(HashMap* linking) {
    HashMap* seen = create_hash_map();
    for (int i = 0; i < linking->size; ++i) {
        IntPointArray* arr = (IntPointArray*)linking->values[i];
        if (hash_map_get(seen, (IntPoint){(intptr_t)arr, 0}) == NULL) {
            hash_map_put(seen, (IntPoint){(intptr_t)arr, 0}, arr);  // dummy key to track
            free_int_point_array(arr);
        }
    }
    free(seen->keys);
    free(seen->values);
    free(seen);
    free(linking->keys);
    free(linking->values);
    free(linking);
}


void free_minutia_map(HashMap* map) {
    if (!map) return;
    // Do NOT free SkeletonMinutia* — they are owned by the skeleton
    free(map->keys);
    free(map->values);
    free(map);
}

IntPointArray* create_int_point_array(int capacity) {
    IntPointArray* array = malloc(sizeof(IntPointArray));
    array->data = malloc(capacity * sizeof(IntPoint));
    array->size = 0;
    array->capacity = capacity;
    return array;
}

void append_int_point(IntPointArray* array, IntPoint point) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        // array->capacity = array->capacity * 3 / 2 + 1;
        array->data = realloc(array->data, array->capacity * sizeof(IntPoint));
    }
    array->data[array->size++] = point;
}

// int java_round(float x) {
//     return (int)floor(x + 0.5);
// }

IntPointArray* line_to(IntPoint a, IntPoint b) {
    IntPointArray* result;
    int dx = b.x - a.x;
    int dy = b.y - a.y;

    printf("a.x: %d, a.y: %d, b.x: %d, b.y: %d\n",a.x,a.y,b.x,b.y);

    if (abs(dx) >= abs(dy)) {
        int length = abs(dx) + 1;
        result = create_int_point_array(length);
        if (dx > 0) {
            for (int i = 0; i <= dx; ++i) {
                int y_offset = java_round(i * (dy / (float)dx));
                printf("i: %d, dy: %d, dx: %d\n",i,dy,dx);
                printf("a.y: %d, y_offset: %d, a.y+y_offset: %d\n",a.y,y_offset,a.y+y_offset);
                append_int_point(result, (IntPoint){ a.x + i, a.y + y_offset });
            }
        } else if (dx < 0) {
            for (int i = 0; i <= -dx; ++i) {

                int y_offset = java_round(i * (dy / (float)dx));
                printf("i: %d, dy: %d, dx: %d\n",i,dy,dx);
                printf("dy / (float)dx: %f\n",dy / (float)dx);
                printf("i*(dy / (float)dx): %f\n",i*(dy / (float)dx));

                printf("a.y: %d, y_offset: %d, a.y-y_offset: %d\n",a.y,y_offset,a.y-y_offset);
                append_int_point(result, (IntPoint){ a.x - i, a.y - y_offset });
            }
        } else {
            append_int_point(result, a);
        }
    } else {
        int length = abs(dy) + 1;
        result = create_int_point_array(length);
        if (dy > 0) {
            for (int i = 0; i <= dy; ++i) {
                int x_offset = java_round(i * (dx / (float)dy));
                printf("a.y: %d, i: %d, a.y+i: %d\n",a.y,i,a.y+i);
                append_int_point(result, (IntPoint){ a.x + x_offset, a.y + i });
            }
        } else if (dy < 0) {
            for (int i = 0; i <= -dy; ++i) {
                int x_offset = java_round(i * (dx / (float)dy));
                printf("a.y: %d, i: %d, a.y-i: %d\n",a.y,i,a.y-i);
                append_int_point(result, (IntPoint){ a.x - x_offset, a.y - i });
            }
        } else {
            append_int_point(result, a);
        }
    }

    return result;
}


IntPointArray* create_int_point_array_empty() {
    IntPointArray* array = malloc(sizeof(IntPointArray));
    array->size = 0;
    array->capacity = 8;
    array->data = malloc(array->capacity * sizeof(IntPoint));
    return array;
}

void push_point(IntPointArray* array, IntPoint p) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        // array->capacity = array->capacity * 3 / 2 + 1;
        array->data = realloc(array->data, array->capacity * sizeof(IntPoint));
    }
    array->data[array->size++] = p;
}

void push_point_skeletonridge(SkeletonRidge* ridge, IntPoint point) {
    printf("In push_point_skeletonridge\n");
    // print_sram_usage();

    SkeletonRidge* base = base_of(ridge);
    if (base->point_count >= base->point_capacity) {
        base->point_capacity = base->point_capacity ? base->point_capacity * 2 : 8;
        base->points = realloc(base->points, base->point_capacity * sizeof(IntPoint));
    }
    base->points[base->point_count++] = point;

    if (base->reversed) 
    {
        base->reversed->point_count = base->point_count;
        base->reversed->point_capacity = base->point_capacity;
    }

    // // Ensure capacity for ridge
    // if (ridge->point_count >= ridge->point_capacity) {
    //     printf("ridge->point_count: %d, ridge->point_capacity: %d\n",ridge->point_count,ridge->point_capacity);
    //     ridge->point_capacity = ridge->point_capacity > 0 ? ridge->point_capacity * 2 : 8;
    //     printf("New ridge->point_capacity: %d\n",ridge->point_capacity);
    //     ridge->points = realloc(ridge->points, ridge->point_capacity * sizeof(IntPoint));
    //     if (!ridge->points) {
    //         fprintf(stderr, "Memory allocation failed in push_point (ridge)\n");
    //         exit(1);
    //     }
    // }

    // // Add to original ridge (append)
    // ridge->points[ridge->point_count++] = point;

    // // Add to reversed ridge (prepend)
    // if (ridge->reversed) {
    //     SkeletonRidge* rev = ridge->reversed;

    //     // Ensure capacity
    //     if (rev->point_count >= rev->point_capacity) {
    //         printf("rev->point_count: %d, rev->point_capacity: %d\n",rev->point_count,rev->point_capacity);
    //         rev->point_capacity = rev->point_capacity > 0 ? rev->point_capacity * 2 : 8;
    //         printf("Before realloc, New rev->point_count: %d, rev->point_capacity: %d\n",rev->point_count,rev->point_capacity);
    //         rev->points = realloc(rev->points, rev->point_capacity * sizeof(IntPoint));
    //         printf("rev->points: %p\n",rev->points);

    //         if (!rev->points) {
    //             fprintf(stderr, "Memory allocation failed in push_point (reversed)\n");
    //             exit(1);
    //         }
    //     }

    //     // Shift existing points right to make space at index 0
    //     for (int i = rev->point_count; i > 0; --i)
    //         rev->points[i] = rev->points[i - 1];

    //     // Prepend to reversed
    //     rev->points[0] = point;
    //     rev->point_count++;
    // }
}


IntPoint add_points(IntPoint a, IntPoint b) {
    IntPoint result = {a.x + b.x, a.y + b.y};
    return result;
}


IntPointArray* find_minutiae(BooleanMatrix* thinned) {
    IntPointArray* result = create_int_point_array_empty();
    for (int y = 0; y < thinned->height; ++y) {
        for (int x = 0; x < thinned->width; ++x) {
            if (get_boolean_matrix(thinned, x, y)) {
                printf("get_boolean_matrix at (%d, %d) is true\n", x, y);
                int count = 0;
                for (int i = 0; i < 8; ++i) {
                    IntPoint neighbor = add_points((IntPoint){x, y}, CORNER_NEIGHBORS[i]);
                    if (get_boolean_matrix_safe(thinned, neighbor.x, neighbor.y))
                    {
                        ++count;
                        printf("New count=%d at neighbor (%d, %d)\n",count,neighbor.x,neighbor.y);
                    }
                }
                // If pixel at position has one neighbour thats also true (ridge endings)
                // and more than 2 neighbours (ridge bifurcations) that are true, then its a MINUTIAE
                if (count == 1 || count > 2)
                {
                    printf("count=%d at (%d, %d) is minutiae\n",count,x,y);
                    push_point(result, (IntPoint){x, y});
                }
            }
        }
    }
    return result;
}

// linkNeighboringMinutiae translated to C
//  Each group of neighboring minutiae ends up sharing the same IntPointArray*
HashMap* link_neighboring_minutiae(IntPointArray* minutiae) {
    HashMap* linking = create_hash_map();
    for (int i = 0; i < minutiae->size; ++i) {
        IntPoint minutiaPos = minutiae->data[i];
        IntPointArray* ownLinks = NULL;
        for (int j = 0; j < 8; ++j) {
            IntPoint neighborRelative = CORNER_NEIGHBORS[j];
            IntPoint neighborPos = add_points(minutiaPos, neighborRelative);
            IntPointArray* neighborLinks = (IntPointArray*)hash_map_get(linking, neighborPos);
            // sets of points exist for some neighbour of minutiaPos - neighborLinks != NULL
            if (neighborLinks && neighborLinks != ownLinks) {
                if (ownLinks != NULL) {
                    for (int k = 0; k < ownLinks->size; ++k)
                        push_point(neighborLinks, ownLinks->data[k]);
                    
                    // Each ownLinks point is added to neighborLinks; so array is same for all ownLinks in this case
                    for (int k = 0; k < ownLinks->size; ++k)
                        hash_map_put(linking, ownLinks->data[k], neighborLinks);
                }
                ownLinks = neighborLinks;
            }
        }
        if (ownLinks == NULL)
            ownLinks = create_int_point_array_empty();
        push_point(ownLinks, minutiaPos);

        // Basically, for each minutiae position minutiaePos, we add value corresponding to it as ownLinks
        hash_map_put(linking, minutiaPos, ownLinks);
    }
    return linking;
}

SkeletonMinutia* deep_copy_minutia(SkeletonMinutia* src) {
    SkeletonMinutia* copy = malloc(sizeof(SkeletonMinutia));
    copy->position = src->position;
    copy->ridge_count = src->ridge_count;
    copy->ridge_capacity = src->ridge_capacity;

    // Allocate and copy ridges array (shallow copy of ridge pointers)
    copy->ridges = malloc(copy->ridge_capacity * sizeof(SkeletonRidge*));
    for (int i = 0; i < copy->ridge_count; ++i) {
        copy->ridges[i] = src->ridges[i];  // still shallow for now
    }

    return copy;
}


// minutiaCenters in C
// Note that skeleton is intially empty

// The build_minutia_centers function adds only one minutia (at the centroid) per connected component to the Skeleton
// centers[primary_pos]=SkeletonMinutia* for the primary position of the component; single SkeletonMinutia* — that is, a pointer to one specific SkeletonMinutia structure, representing the centroid of that connected component
// build_minutia_centers with pointer array
HashMap* build_minutia_centers(Skeleton* skeleton, HashMap* linking) {
    HashMap* centers = create_hash_map();
    for (int i = 0; i < linking->size; ++i) {
        IntPoint current_pos = linking->keys[i];
        IntPointArray* linked_minutiae = (IntPointArray*)hash_map_get(linking, current_pos);
        IntPoint primary_pos = linked_minutiae->data[0];

        if (hash_map_get(centers, primary_pos) == NULL) {
            IntPoint sum = {0, 0};
            for (int j = 0; j < linked_minutiae->size; ++j)
                sum = add_points(sum, linked_minutiae->data[j]);
            IntPoint center = {sum.x / linked_minutiae->size, sum.y / linked_minutiae->size};
            SkeletonMinutia* minutia = malloc(sizeof(SkeletonMinutia));
            init_skeleton_minutia(minutia, center);
            if (skeleton->count == skeleton->capacity) {
                // skeleton->capacity *= 2;
                skeleton->capacity = skeleton->capacity * 3 / 2 + 1;
                skeleton->minutiae = realloc(skeleton->minutiae, skeleton->capacity * sizeof(SkeletonMinutia*));
            }
            skeleton->minutiae[skeleton->count] = minutia;
            hash_map_put(centers, primary_pos, minutia);
            skeleton->count++;
        }
        hash_map_put(centers, current_pos, hash_map_get(centers, primary_pos));
    }
    return centers;
}


// HashMap* build_minutia_centers(Skeleton* skeleton, HashMap* linking) {
//     HashMap* centers = create_hash_map();
//     for (int i = 0; i < linking->size; ++i) {
//         // FOr all keys in linking hashmap; keys are of type IntPoint(position) and value is IntPointArray*
//         IntPoint current_pos = linking->keys[i];
//         IntPointArray* linked_minutiae = (IntPointArray*)hash_map_get(linking, current_pos);
//         IntPoint primary_pos = linked_minutiae->data[0];

//         // If primary_pos is NOT already in our newly created centers hashmap, create a new SkeletonMinutia at the center of linked_minutiae
//         // and add to centers hashmap
//         if (hash_map_get(centers, primary_pos) == NULL) {
//             IntPoint sum = {0, 0};
//             for (int j = 0; j < linked_minutiae->size; ++j)
//                 sum = add_points(sum, linked_minutiae->data[j]);
//             // Get center of all linked minutaie, whose primary_pos is linking[linking->keys[i]]
//             IntPoint center = {sum.x / linked_minutiae->size, sum.y / linked_minutiae->size};
//             // SkeletonMinutia minutia;
//             SkeletonMinutia* minutia = malloc(sizeof(SkeletonMinutia));
//             // create skeleton_minutaie (CREATE A MINUTIAE) whose position is the center, and it has ridges
//             init_skeleton_minutia(minutia, center);
//             // Add to skeleton
//             if (skeleton->count == skeleton->capacity) {
//                 skeleton->capacity *= 2;
//                 skeleton->minutiae = realloc(skeleton->minutiae, skeleton->capacity * sizeof(SkeletonMinutia));
//             }

//             // Add the newly created centroid minutiae to the old skeleton
//             skeleton->minutiae[skeleton->count] = *(deep_copy_minutia(minutia));
//             hash_map_put(centers, primary_pos, &skeleton->minutiae[skeleton->count]);
//             skeleton->count++;
//         }
//         hash_map_put(centers, current_pos, hash_map_get(centers, primary_pos));
//     }
//     return centers;
// }


// traceRidges in C
// trace all ridges between SKeletonMinutaie points and create SkeletonRidge for each ridge
// BooleanMatrix* thinned is a binary skeleton image (1 for ridge pixels, 0 for background).
// HashMap* minutiae_points maps IntPoint → SkeletonMinutia* for all detected minutiae.
// Each ridge is a sequence of ridge pixels connecting two minutiae, stored as a SkeletonRidge.
// traceRidges in C

int compare_intpoints(const void* a, const void* b) {
    const IntPoint* p1 = (const IntPoint*)a;
    const IntPoint* p2 = (const IntPoint*)b;
    if (p1->y != p2->y)
        return p1->y - p2->y;
    return p1->x - p2->x;
}

// minutiae_point map has center->SkeletonMinutia* mapping; but none of these SkeletonMinutia* have any ridges yet
// These ridges will be put in this function
void trace_ridges(BooleanMatrix* thinned, HashMap* minutiae_points) {
    // leads: A map that keeps track of ridge-starting pixels, so we don't trace the same ridge twice.
    HashMap* leads = create_hash_map();

    IntPoint* sorted_keys = malloc(sizeof(IntPoint) * minutiae_points->size);
    memcpy(sorted_keys, minutiae_points->keys, sizeof(IntPoint) * minutiae_points->size);
    qsort(sorted_keys, minutiae_points->size, sizeof(IntPoint), compare_intpoints);

    // Iterates over each key in the minutiaePoints map (which are positions of detected minutiae).
    for (int i = 0; i < minutiae_points->size; ++i) {
        // IntPoint minutia_point = minutiae_points->keys[i];
        IntPoint minutia_point = sorted_keys[i];
        printf("i: %d/%d, orig minutiaPoint: (%d, %d)\n", i, minutiae_points->size, minutia_point.x, minutia_point.y);
        SkeletonMinutia* minutia = (SkeletonMinutia*)hash_map_get(minutiae_points, minutia_point);
        for (int j = 0; j < 8; ++j) {
            IntPoint start_relative = CORNER_NEIGHBORS[j];
            IntPoint start = add_points(minutia_point, start_relative);
            printf("j: %d/8, Processing start=(%d, %d)\n", j, start.x, start.y);
            // printf("get_boolean_matrix_safe(thinned,start): %d, hash_map_get(minutiae_points, start): %d, hash_map_get(leads, start): %d\n",
            //        get_boolean_matrix_safe(thinned, start.x, start.y),
            //        hash_map_get(minutiae_points, start)==NULL,
            //        hash_map_get(leads, start)==NULL);

            if (get_boolean_matrix_safe(thinned, start.x, start.y) &&
                hash_map_get(minutiae_points, start) == NULL &&
                hash_map_get(leads, start) == NULL) {

                SkeletonRidge* ridge = create_ridge();
                // printf("minutia_point: (%d, %d), start: (%d, %d)\n", minutia_point.x, minutia_point.y, start.x, start.y);

                // If valis start is found for new ridge, Pushes minutiaPoint and start into the ridge.points list
                
                push_point_skeletonridge(ridge, minutia_point);
                push_point_skeletonridge(ridge, start);
                IntPoint previous = minutia_point;
                IntPoint current = start;
                IntPoint next;
                do {
                    next = (IntPoint){0, 0};
                    for (int k = 0; k < 8; ++k) {
                        IntPoint next_relative = CORNER_NEIGHBORS[k];
                        next = add_points(current, next_relative);
                        if (get_boolean_matrix_safe(thinned, next.x, next.y) && !point_equals(next, previous))
                            break;
                    }
                    previous = current;
                    current = next;
                    printf("current: (%d, %d)\n", current.x, current.y);
                    push_point_skeletonridge(ridge, current);
                } while (hash_map_get(minutiae_points, current) == NULL);
                printf("end: (%d, %d)\n", current.x, current.y);
                
                reverse_ridge_points(ridge);

                #undef printf
                #define printf printf
                printf("ridge: ");
                SkeletonRidge* base = ridge;

                for(int p = 0; p < base->point_count; ++p) {
                    printf("  (%d, %d)", base->points[p].x, base->points[p].y);
                }
                printf("\n");
                
                // printf("Setting start ridge for minutia: (%d, %d)\n", minutia->position.x, minutia->position.y);
                // printf("Setting end ridge for minutia: (%d, %d)\n", ((SkeletonMinutia*)hash_map_get(minutiae_points, current))->position.x, ((SkeletonMinutia*)hash_map_get(minutiae_points, current))->position.y);
                printf("ridge_point_at(ridge,1): (%d, %d)\n", ridge_point_at(ridge,1).x, ridge_point_at(ridge,1).y);
                printf("ridge_point_at(ridge->reversed,1): (%d, %d)\n", ridge_point_at(ridge->reversed,1).x, ridge_point_at(ridge->reversed,1).y);

                printf("minutia_point: (%d, %d), start: (%d, %d), end: (%d, %d)\n", minutia_point.x, minutia_point.y, start.x, start.y, current.x, current.y);
                printf("hash_map_get(minutiae_points, current): %p\n", hash_map_get(minutiae_points, current));
                printf("ridge->is_view: %d\n", ridge->is_view);

                // minutia set as startMinutia of ridge
                ridge_set_start(ridge, minutia);
                ridge_set_end(ridge, (SkeletonMinutia*)hash_map_get(minutiae_points, current));
                hash_map_put(leads, ridge_point_at(ridge,1), ridge);
                hash_map_put(leads, ridge_point_at(ridge->reversed,1), ridge);
                // #define printf(...)
            }
        }
    }

    free(sorted_keys);
    free(leads->keys);
    free(leads->values);
    free(leads);
    leads = NULL;
}

void fix_linking_gaps(Skeleton* skeleton) {
    printf("In fix_linking_gaps, skeleton->count: %d\n",skeleton->count);
    for (int i = 0; i < skeleton->count; ++i) {
        printf("Adding to minutia %d at (%d, %d)\n", i, skeleton->minutiae[i]->position.x, skeleton->minutiae[i]->position.y);
        SkeletonMinutia* minutia = skeleton->minutiae[i];
        for (int j = 0; j < minutia->ridge_count; ++j) {
            SkeletonRidge* ridge = minutia->ridges[j];
            printf("Ridge number %d with %d points\n", j, ridge->point_count);

            if (!point_equals(ridge_point_at(ridge,0), minutia->position)) {
                IntPointArray* filling = line_to(ridge_point_at(ridge,0), minutia->position);

                // Skip the first point to avoid duplication
                for (int k = 1; k < filling->size; ++k) {
                    IntPoint point = filling->data[k];

                    expand_size(ridge);

                    // // Append to reversed.points
                    // if (ridge->reversed->point_count == ridge->reversed->point_capacity) {
                    //     // ridge->reversed->point_capacity *= 2;
                    //     ridge->reversed->point_capacity = ridge->reversed->point_capacity * 3 / 2 + 1;

                    //     ridge->reversed->points = realloc(
                    //         ridge->reversed->points,
                    //         ridge->reversed->point_capacity * sizeof(IntPoint));
                    // }
                    // ridge->reversed->points[ridge->reversed->point_count++] = point;

                    // // Also prepend to ridge->points (since reversed is reverse of this)
                    // if (ridge->point_count == ridge->point_capacity) {
                    //     // ridge->point_capacity *= 2;
                    //     ridge->point_capacity = ridge->point_capacity * 3 / 2 + 1;

                    //     ridge->points = realloc(
                    //         ridge->points,
                    //         ridge->point_capacity * sizeof(IntPoint));
                    // }

                    if(ridge->is_view==0)
                    {
                        // Shift existing points to the right to insert at the beginning
                        for (int m = ridge->point_count; m > 0; --m) {
                            ridge->points[m] = ridge->points[m - 1];
                        }
                        ridge->points[0] = point;
                        ridge->point_count++;
                        printf("New ridge->points[0]: (%d, %d)\n", ridge->points[0].x, ridge->points[0].y);

                        ridge->reversed->point_count = ridge->point_count;
                        ridge->reversed->point_capacity = ridge->point_capacity;
                    }
                    else
                    {
                        SkeletonRidge* base = ridge->reversed;
                        base->points[base->point_count++] = point;
                        base->reversed->point_count = base->point_count;
                        base->reversed->point_capacity = base->point_capacity;
                    }
                }

                free(filling->data);
                free(filling);
            }
        }
    }
}

void init_skeleton(Skeleton* skeleton, SkeletonType type, IntPoint size) {
    skeleton->type = type;
    skeleton->size = size;
    skeleton->count = 0;
    skeleton->capacity = 16;
    skeleton->minutiae = malloc(sizeof(SkeletonMinutia*) * skeleton->capacity);
    if (!skeleton->minutiae) {
        fprintf(stderr, "Failed to allocate minutiae array\n");
        exit(1);
    }
}


static inline const SkeletonRidge* base_of_c(const SkeletonRidge* r) {
    return (r && r->is_view) ? r->reversed : r;
}
static inline void ridge_sync_view(SkeletonRidge* base) {
    if (base && base->reversed) base->reversed->point_count = base->point_count;
}

// Input is thinned image
Skeleton* trace(BooleanMatrix* thinned, SkeletonType type) {
    IntPoint size = {thinned->width, thinned->height};
    Skeleton* skeleton = (Skeleton*)malloc(sizeof(Skeleton));
    // Initialize empty skeleton
    init_skeleton(skeleton, type, size);  // assumes you have an init function

    // Detects pixel positions with:
    // Only 1 neighbor (ending ridge)
    // Or 3+ neighbors (bifurcation)
    // Returns a dynamic array of IntPoint minutiae positions.
    IntPointArray* minutiaPoints = find_minutiae(thinned);
    printf("Minutiae found: %d\n", minutiaPoints->size);
    for(int i = 0; i < minutiaPoints->size; ++i) {
        IntPoint p = minutiaPoints->data[i];
        printf("Minutia at (%d, %d)\n", p.x, p.y);
    }

    // Link adjacent minutiae into clusters
    // Returns a HashMap<IntPoint, IntPointArray*> where each key maps to a group of linked minutiae (like Union-Find).
    HashMap* linking = link_neighboring_minutiae(minutiaPoints);  // define this type
    free_int_point_array(minutiaPoints);

    #undef printf
    #define printf printf
    printf("Minutia clusters found: %d\n", linking->size);

    for(int i=0;i<linking->size;i++)
    {
        IntPointArray* minutiae_points= hash_map_get(linking,linking->keys[i]);
        printf("Key minutiaepos: (%d,%d)\n",linking->keys[i].x,linking->keys[i].y);
        
        for(int j = 0; j < minutiae_points->size; ++j) {
            IntPoint p = minutiae_points->data[j];
            printf("(%d, %d) ", p.x, p.y);
        }
        printf("\n");
    }   
    // #define printf(...)

    //  Computes average position of each cluster.
    // Creates a SkeletonMinutia at the center.
    // Maps every original minutia pixel to the representative SkeletonMinutia.

    // minutiae progressively added to skeleton
    // minutiae also represented as values in hashmap with key as centerpos
    HashMap* minutiaMap = build_minutia_centers(skeleton, linking);  // define this type too
    free_minutia_link_map(linking);

    #undef printf
    #define printf printf
    for(int i=0;i<minutiaMap->size;i++)
    {
        printf("Minutia center at: (%d, %d)\n",minutiaMap->keys[i].x,minutiaMap->keys[i].y);
        SkeletonMinutia* m = (SkeletonMinutia*)hash_map_get(minutiaMap, minutiaMap->keys[i]);
        printf("Minutia at (%d, %d) with %d ridges\n", m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j) {
            SkeletonRidge* r = m->ridges[j];
            printf("Ridge with %d points from start: (%d, %d), end: (%d, %d)\n",
                r->startMinutia->position.x, r->startMinutia->position.y,
                r->endMinutia->position.x, r->endMinutia->position.y);
            for(int k = 0; k < r->point_count; ++k) {
                printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
            }
            printf("\n");
        }
    }
    // #define printf(...)


    // Walks along the thinned lines between minutiae.
    // For each traced path, builds a SkeletonRidge and connects two SkeletonMinutia endpoints.
    trace_ridges(thinned, minutiaMap);  // define this

    #undef printf
    #define printf printf
    printf("minutiaMap after trace_ridges, size: %d\n",minutiaMap->size);
    for(int i=0;i<minutiaMap->size;i++)
    {
        printf("After trace_ridges Minutia center at (%d, %d)\n",minutiaMap->keys[i].x,minutiaMap->keys[i].y);
        SkeletonMinutia* m = (SkeletonMinutia*)hash_map_get(minutiaMap, minutiaMap->keys[i]);
        printf("After trace_ridges Minutia at (%d, %d) with %d ridges\n", m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j) {
            SkeletonRidge* r = m->ridges[j];
            printf("After trace_ridges Ridge with %d points from (%d, %d) to (%d, %d)\n",
                  r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x,r->endMinutia->position.y);
                if(r->is_view==0) {
                    for(int k = 0; k < r->point_count; ++k) {
                        printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                    }
                } else {
                    SkeletonRidge* b = base_of(r);
                    for(int k = 0; k < b->point_count; ++k) {
                        printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                    }
                }
                printf("\n");
            
            }
    }
    
    printf("-------------------- Before\n");
    // // #define printf(...)

    //     // ---- place this immediately after trace_ridges(thinned, minutiaMap); ----
    // for (int i = 0; i < minutiaMap->size; ++i) {
    //     // printf("iii: %d\n",i);
    //     SkeletonMinutia* m = (SkeletonMinutia*)hash_map_get(minutiaMap, minutiaMap->keys[i]);
    //     if (!m) continue;

    //     for (int j = 0; j < m->ridge_count; ++j) {
    //         SkeletonRidge* r = m->ridges[j];
    //         if (!r) continue;

    //         if (r->is_view) {
    //             #undef printf
    //             #define printf printf
    //             printf("r->startMinutia: (%d, %d), r->endMinutia: (%d, %d), m: (%d, %d)\n",
    //                    r->startMinutia->position.x, r->startMinutia->position.y,
    //                    r->endMinutia->position.x, r->endMinutia->position.y,
    //                    m->position.x, m->position.y);
    //             // #define printf(...)

    //             SkeletonRidge* new_ridge = create_ridge();

    //             new_ridge->point_capacity = r->point_capacity;
    //             new_ridge->point_count = r->point_count;
    //             new_ridge->is_view = 0; // This is the real one
                
    //             r->reversed = malloc(sizeof(SkeletonRidge));
    //             r->reversed->point_capacity = 8;
    //             r->reversed->point_count = 0;
    //             // r->reversed->points = malloc(sizeof(IntPoint) * r->point_capacity); // will allocate after reversal
    //             r->reversed->reversed = r;
    //             r->reversed->is_view = 1; // This is the view

    //             r->startMinutia = NULL;
    //             r->endMinutia = NULL;
    //             r->reversed->startMinutia = NULL;
    //             r->reversed->endMinutia = NULL;

    //             // We hold the *view* at this adjacency. Make the base match this orientation.
    //             SkeletonRidge* b = base_of(r);

    //             int n = b->point_count;

    //             // 1) Reverse the base points physically so base order == view's logical order
    //             for (int a = 0, z = n - 1; a < n; ++a, --z) {
    //                 r->points[a]=b->points[z];
    //             }

    //             // // 2) Swap endpoints: start/end minutiae must follow the new orientation
    //             // SkeletonMinutia* tmpM = b->startMinutia;
    //             // b->startMinutia = b->endMinutia;
    //             // b->endMinutia   = tmpM;

    //             // Keep the reversed view in sync (count only; it's still a view)
    //             // ridge_sync_view(b);

    //             // 3) Store the base handle in the minutia's adjacency list (no views in lists)
    //             m->ridges[j] = r;

    //             #undef printf
    //             #define printf printf
    //             printf("New r->startMinutia: (%d, %d), r->endMinutia: (%d, %d), m: (%d, %d)\n",
    //                    r->startMinutia->position.x, r->startMinutia->position.y,
    //                    r->endMinutia->position.x, r->endMinutia->position.y,
    //                    m->position.x, m->position.y);
    //             for(int k = 0; k < r->point_count; ++k) {
    //                 printf("(%d, %d) ", ridge_point_at(r,k).x, ridge_point_at(r,k).y);
    //             }
    //             printf("\n");
    //             // #define printf(...)
    //         }
    //         else
    //         {
    //             #undef printf
    //             #define printf printf
    //             printf("Same: r->startMinutia: (%d, %d), r->endMinutia: (%d, %d), m: (%d, %d)\n",
    //                    r->startMinutia->position.x, r->startMinutia->position.y,
    //                    r->endMinutia->position.x, r->endMinutia->position.y,
    //                    m->position.x, m->position.y);
    //             for(int k = 0; k < r->point_count; ++k) {
    //                 printf("(%d, %d) ", ridge_point_at(r,k).x, ridge_point_at(r,k).y);
    //             }
    //             printf("\n");
    //             // #define printf(...)
    //         }

    //         #undef printf
    //         #define printf printf
    //         printf("m->ridges[%d]: (%d, %d) to (%d, %d), point_count: %d\n",
    //                j,m->ridges[j]->startMinutia->position.x, m->ridges[j]->startMinutia->position.y,
    //                m->ridges[j]->endMinutia->position.x, m->ridges[j]->endMinutia->position.y,
    //                m->ridges[j]->point_count);
    //         for(int k = 0; k < m->ridges[j]->point_count; ++k) {
    //             printf("(%d, %d) ", m->ridges[j]->points[k].x, m->ridges[j]->points[k].y);
    //         }
    //         printf("\n");
    //         // #define printf(...)

    //     }
    // }

    // #undef printf
    // #define printf printf
    // for(int i=0;i<minutiaMap->size;i++)
    // {
    //     printf("After trace_ridges Minutia center at (%d, %d)\n",minutiaMap->keys[i].x,minutiaMap->keys[i].y);
    //     SkeletonMinutia* m = (SkeletonMinutia*)hash_map_get(minutiaMap, minutiaMap->keys[i]);
    //     printf("After trace_ridges Minutia at (%d, %d) with %d ridges\n", m->position.x, m->position.y, m->ridge_count);
    //     for (int j = 0; j < m->ridge_count; ++j) {
    //         SkeletonRidge* r = m->ridges[j];
    //         // SkeletonRidge* r = base_of_c(r2);

    //         printf("After trace_ridges Ridge with %d points from (%d, %d) to (%d, %d)\n",
    //               r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
    //                r->endMinutia->position.x, r->endMinutia->position.y);
    //         for(int k = 0; k < r->point_count; ++k) {
    //             printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
    //         }
    //         printf("\n");
    //     }
    // }
    // printf("-------------------- After\n");
    // // #define printf(...)

    #undef printf
    #define printf printf
    printf("\nSkeleton before fix_linking_gaps\n");
    printf("Ridges created with %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
                if(r->is_view==0) {
                    for(int k = 0; k < r->point_count; ++k) {
                        printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                    }
                } else {
                    SkeletonRidge* b = base_of(r);
                    for(int k = 0; k < b->point_count; ++k) {
                        printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                    }
                }
            printf("\n");
        }
    }
    // #define printf(...)

    fix_linking_gaps(skeleton);

    #undef printf
    #define printf printf
    printf("Skeleton after fix_linking_gaps:\n");
    printf("Ridges created: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
                if(r->is_view==0) {
                    for(int k = 0; k < r->point_count; ++k) {
                        printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                    }
                } else {
                    SkeletonRidge* b = base_of(r);
                    for(int k = 0; k < b->point_count; ++k) {
                        printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                    }
                }
            printf("\n");
        }
    }
    // #define printf(...)

    free_minutia_map(minutiaMap);

    return skeleton;
}


//////////////////////////


///// BinaryThinning
typedef enum {
    SKELETON,
    ENDING,
    REMOVABLE
} NeighborhoodType;


// // Function to add two IntPoint values
// IntPoint add_points(IntPoint a, IntPoint b) {
// 	IntPoint result;
// 	result.x = a.x + b.x;
// 	result.y = a.y + b.y;
// 	return result;
// }

NeighborhoodType* compute_neighborhood_types() {
    NeighborhoodType* types = malloc(256 * sizeof(NeighborhoodType));
    for (int mask = 0; mask < 256; ++mask) {
        bool TL = (mask & 1) != 0;
        bool TC = (mask & 2) != 0;
        bool TR = (mask & 4) != 0;
        bool CL = (mask & 8) != 0;
        bool CR = (mask & 16) != 0;
        bool BL = (mask & 32) != 0;
        bool BC = (mask & 64) != 0;
        bool BR = (mask & 128) != 0;

        int count = __builtin_popcount(mask);

        bool diagonal = (!TC && !CL && TL) || (!CL && !BC && BL) || (!BC && !CR && BR) || (!CR && !TC && TR);
        bool horizontal = (!TC && !BC && (TR || CR || BR) && (TL || CL || BL));
        bool vertical = (!CL && !CR && (TL || TC || TR) && (BL || BC || BR));
        bool end = (count == 1);

        if (end)
            types[mask] = ENDING;
        else if (!diagonal && !horizontal && !vertical)
            types[mask] = REMOVABLE;
        else
            types[mask] = SKELETON;
    }
    return types;
}

bool is_false_ending(BooleanMatrix* binary, IntPoint ending) {
    for (int i = 0; i < 8; ++i) {
        IntPoint rel = CORNER_NEIGHBORS[i];
        IntPoint neighbor = add_points(ending, rel);
        if (get_boolean_matrix(binary, neighbor.x, neighbor.y)) {
            int count = 0;
            for (int j = 0; j < 8; ++j) {
                IntPoint rel2 = CORNER_NEIGHBORS[j];
                IntPoint n2 = add_points(neighbor, rel2);
                if (get_boolean_matrix_safe(binary, n2.x, n2.y))
                    ++count;
            }
            return count > 2;
        }
    }
    return false;
}


 
BooleanMatrix thin(BooleanMatrix* input, SkeletonType type) {
    NeighborhoodType* types = compute_neighborhood_types();
    IntPoint size = {input->width, input->height};
    BooleanMatrix partial = create_boolean_matrix(size.x, size.y);
    BooleanMatrix thinned = create_boolean_matrix(size.x, size.y);

    for (int y = 1; y < size.y - 1; ++y)
        for (int x = 1; x < size.x - 1; ++x)
        {
            set_boolean_matrix(&partial, x, y, get_boolean_matrix(input, x, y));
            printf("Setting x: %d, y: %d to %d\n", x, y, get_boolean_matrix(input, x, y));
        }

    bool removed = true;
    for (int i = 0; i < THINNING_ITERATIONS && removed; ++i) {
        removed = false;
        for (int evenY = 0; evenY < 2; ++evenY) {
            for (int evenX = 0; evenX < 2; ++evenX) {
                for (int y = 1 + evenY; y < size.y - 1; y += 2) {
                    for (int x = 1 + evenX; x < size.x - 1; x += 2) {
                        if (get_boolean_matrix(&partial, x, y) &&
                            !get_boolean_matrix(&thinned, x, y) &&
                            !(get_boolean_matrix(&partial, x, y - 1) &&
                              get_boolean_matrix(&partial, x, y + 1) &&
                              get_boolean_matrix(&partial, x - 1, y) &&
                              get_boolean_matrix(&partial, x + 1, y))) {
                            
                            int neighbors =
                                (get_boolean_matrix(&partial, x + 1, y + 1) ? 128 : 0) |
                                (get_boolean_matrix(&partial, x, y + 1) ? 64 : 0) |
                                (get_boolean_matrix(&partial, x - 1, y + 1) ? 32 : 0) |
                                (get_boolean_matrix(&partial, x + 1, y) ? 16 : 0) |
                                (get_boolean_matrix(&partial, x - 1, y) ? 8 : 0) |
                                (get_boolean_matrix(&partial, x + 1, y - 1) ? 4 : 0) |
                                (get_boolean_matrix(&partial, x, y - 1) ? 2 : 0) |
                                (get_boolean_matrix(&partial, x - 1, y - 1) ? 1 : 0);

                            if (types[neighbors] == REMOVABLE ||
                                (types[neighbors] == ENDING && is_false_ending(&partial, (IntPoint){x, y}))) {
                                removed = true;
                                set_boolean_matrix(&partial, x, y, false);
                            } else {
                                printf("Setting thinned x: %d, y: %d to true\n", x, y);
                                set_boolean_matrix(&thinned, x, y, true);
                            }
                        }
                    }
                }
            }
        }
    }

    // TransparencySink_log_matrix(type.prefix + "thinned-skeleton", &thinned);
    free(types);
    free(partial.cells);

    return thinned;
}

/////////////// Filter Apply /////////////

void minutia_detach_end(SkeletonMinutia* minutia, SkeletonRidge* ridge) {
    // Find the ridge in the minutia's list of ridges and remove it
    for (int i = 0; i < minutia->ridge_count; ++i) {
        if (minutia->ridges[i] == ridge) {
            // Shift remaining ridges left
            for (int j = i; j < minutia->ridge_count - 1; ++j) {
                minutia->ridges[j] = minutia->ridges[j + 1];
            }
            minutia->ridge_count--;
            break;
        }
    }

    // Clear the endMinutia pointer in the ridge
    if (ridge->endMinutia == minutia) {
        ridge->endMinutia = NULL;
    }

    // Also clear reversed ridge's startMinutia if it's pointing to this
    if (ridge->reversed && ridge->reversed->startMinutia == minutia) {
        ridge->reversed->startMinutia = NULL;
    }
}


void apply_skeleton_dot_filter(Skeleton* skeleton) {
    int new_count = 0;
    for (int i = 0; i < skeleton->count; ++i) {
        SkeletonMinutia* minutia = skeleton->minutiae[i];
        if (minutia->ridge_count > 0) {
            // Keep this minutia
            skeleton->minutiae[new_count++] = minutia;
        } else {
            // Free the minutia since it's unused
            free(minutia->ridges); // if ridges was malloc'd
            free(minutia);
        }
    }
    skeleton->count = new_count;
}

// int check_ridges(SkeletonRidge* r1, SkeletonRidge* r2)
// {
//     if(r1->point_count!=r2->point_count)
//         return 1;
//     if(r1->point_capacity!=r2->point_capacity)
//         return 1;
//     if(r1->startMinutia!=r2->startMinutia)
//         return 1;
//     if(r1->endMinutia!=r2->endMinutia)
//         return 1;
    
//     if(r1->is_view==r2->is_view)
//     {
//         SkeletonRidge* k1=base_of(r1);
//         SkeletonRidge* k2=base_of(r2);


//     }

//     return 0;
// }

void apply_skeleton_knot_filter(Skeleton* skeleton) {
    for (int i = 0; i < skeleton->count; ++i) {
        SkeletonMinutia* minutia = skeleton->minutiae[i];

        // if (minutia->ridge_count == 2 && check_ridges(minutia->ridges[0]->reversed, minutia->ridges[1])) {
            if (minutia->ridge_count == 2 && minutia->ridges[0]->reversed != minutia->ridges[1]) {
            #undef printf
    #define printf printf
            printf("minutia count: %d\n",i);
            printf("Earlier: Minutia at (%d, %d) with %d ridges\n", minutia->position.x, minutia->position.y, minutia->ridge_count);
            for(int j = 0; j < minutia->ridge_count; ++j) {
                SkeletonRidge* ridge = minutia->ridges[j];
                printf("Ridge %d with %d points from (%d, %d) to (%d, %d)\n",
                   j, ridge->point_count, ridge->startMinutia->position.x, ridge->startMinutia->position.y,
                   ridge->endMinutia->position.x, ridge->endMinutia->position.y);
                if(ridge->is_view==0) {
                    for(int k = 0; k < ridge->point_count; ++k) {
                        printf("(%d, %d) ",ridge->points[k].x, ridge->points[k].y);
                    }
                } else {
                    SkeletonRidge* b = base_of(ridge);
                    for(int k = 0; k < b->point_count; ++k) {
                        printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                    }
                }
            printf("\n");
            }
            // #define printf(...)

            SkeletonRidge* extended = minutia->ridges[0]->reversed;
            SkeletonRidge* removed = minutia->ridges[1];

            // #undef printf
            // #define printf printf
            // printf("extended->point_count originally: %d\n",extended->point_count);
            // printf("removed->point_count: %d\n",removed->point_count);
            // printf("extended->reversed->point_count originally: %d\n",extended->reversed->point_count);
            // printf("reversed->removed->point_count originally: %d\n",removed->reversed->point_count);
            // // #define printf(...)

            printf("extended ridge: \n");
            for (int j = 0; j < extended->point_count; ++j)
                printf("(%d, %d) ", ridge_point_at(extended,j).x, ridge_point_at(extended,j).y);
            printf("\nremoved ridge: \n");
            for (int j = 0; j < removed->point_count; ++j)
                printf("(%d, %d) ", ridge_point_at(removed,j).x, ridge_point_at(removed,j).y);
            printf("\n");

            // Prefer longer ridge as extended
            if (extended->point_count < removed->point_count) {
                SkeletonRidge* tmp = extended;
                extended = removed;
                removed = tmp;
                extended = extended->reversed;
                removed = removed->reversed;
            }

            #undef printf
            #define printf printf
            printf("extended ridge: \n");
            for (int j = 0; j < extended->point_count; ++j)
                printf("(%d, %d) ", ridge_point_at(extended,j).x, ridge_point_at(extended,j).y);
            printf("\nremoved ridge: \n");
            for (int j = 0; j < removed->point_count; ++j)
                printf("(%d, %d) ", ridge_point_at(removed,j).x, ridge_point_at(removed,j).y);
            printf("\n");
            // #define printf(...)

            // Remove the last point from extended ridge
            if (extended->point_count > 0)
            {
                if(extended->is_view==0)
                {
                    extended->point_count--;

                    extended->reversed->point_count--;

                    extended->reversed->point_capacity = extended->point_capacity;
                    extended->reversed->point_count = extended->point_count;

                    // // Remove the last point from extended reversed ridge
                    // if (extended->reversed->point_count > 0) {
                    //     for (int k = 0; k < extended->reversed->point_count; k++)
                    //         extended->reversed->points[k] = extended->reversed->points[k + 1];
                    // }
                }
                else
                {
                    SkeletonRidge* base = extended->reversed;
                    base->point_count--;

                    // extended->point_count--;

                    for (int k = 0; k < base->point_count; k++)
                        base->points[k] = base->points[k + 1];
                    
                    base->reversed->point_capacity = base->point_capacity;
                    base->reversed->point_count = base->point_count;
                }
               
            }

            #undef printf
            #define printf printf
            // printf("extended->point_count originally: %d\n",extended->point_count);
            // printf("removed->point_count: %d\n",removed->point_count);
            // printf("extended->reversed->point_count originally: %d\n",extended->reversed->point_count);
            // printf("reversed->removed->point_count originally: %d\n",removed->reversed->point_count);

            printf("1: extended ridge: \n");
            for (int j = 0; j < extended->point_count; ++j)
                printf("(%d, %d) ", ridge_point_at(extended,j).x, ridge_point_at(extended,j).y);
            printf("removed ridge: \n");
            for (int j = 0; j < removed->point_count; ++j)
                printf("(%d, %d) ", ridge_point_at(removed,j).x, ridge_point_at(removed,j).y);
            printf("\n");
            // #define printf(...)

            // Append all points of removed ridge to extended
            for (int j = 0; j < removed->point_count; ++j) {
                // // Ensure capacity in extended
                // if (extended->point_count == extended->point_capacity) {
                //      // extended->point_capacity *= 2;
                //     extended->point_capacity = extended->point_capacity * 3 / 2 + 1;
                //     extended->points = realloc(extended->points, extended->point_capacity * sizeof(IntPoint));
                // }
                
                expand_size(extended);
            //     #undef printf
            // #define printf printf
            //     printf("extended->is_view: %d, removed->is_view: %d\n",extended->is_view, removed->is_view);
            //     printf("extended->point_count: %d, extended->point_capacity: %d\n",extended->point_count, extended->point_capacity);

            //     printf("EEExtended ridge: \n");
            //     for (int j = 0; j < extended->point_count; ++j)
            //         printf("(%d, %d) ", ridge_point_at(extended,j).x, ridge_point_at(extended,j).y);
            //     printf("\n");
            //     // #define printf(...)
                if(extended->is_view==0)
                {
                    extended->points[extended->point_count++] = ridge_point_at(removed,j); // base_of(removed)->points[j];

                    extended->reversed->point_capacity=extended->point_capacity;
                    extended->reversed->point_count=extended->point_count;
                }
                else
                {
                    SkeletonRidge* base = base_of(extended);
                    for(int k = base->point_count; k > 0; --k)
                        base->points[k] = base->points[k - 1];
                    base->points[0] = ridge_point_at(removed,j); // base_of(removed)->points[j];
                    base->point_count++;

                    base->reversed->point_capacity = base->point_capacity;
                    base->reversed->point_count = base->point_count;
                }

            // #undef printf
            // #define printf printf
            //     printf("new EEExtended ridge: \n");
            //     for (int j = 0; j < extended->point_count; ++j)
            //         printf("(%d, %d) ", ridge_point_at(extended,j).x, ridge_point_at(extended,j).y);
            //     printf("\n");
            //     // #define printf(...)
            }

            #undef printf
            #define printf printf
            printf("2: extended ridge: \n");
            for (int j = 0; j < extended->point_count; ++j)
                printf("(%d, %d) ", ridge_point_at(extended,j).x, ridge_point_at(extended,j).y);
            printf("\n");
            printf("removed ridge: \n");
            for (int j = 0; j < removed->point_count; ++j)
                printf("(%d, %d) ", ridge_point_at(removed,j).x, ridge_point_at(removed,j).y);
            printf("\n");
            // #define printf(...)

            // // Also update reversed ridge (prepend in reverse order)
            // if (extended->reversed) {
            //     SkeletonRidge* rev = extended->reversed;
            //     printf("Original extended reversed ridge: \n");
            //     for (int j = 0; j < rev->point_count; ++j)
            //         printf("(%d, %d) ", rev->points[j].x, rev->points[j].y);
            //     printf("\n");

            //     for (int j = removed->point_count - 1; j >= 0; --j) {
            //         // Ensure capacity
            //         if (rev->point_count == rev->point_capacity) {
            //             // rev->point_capacity *= 2;
            //             rev->point_capacity = rev->point_capacity * 3 / 2 + 1;
            //             rev->points = realloc(rev->points, rev->point_capacity * sizeof(IntPoint));
            //         }
            //         // Shift existing points to the right to prepend
            //         for (int k = rev->point_count; k > 0; --k)
            //             rev->points[k] = rev->points[k - 1];

            //         // Prepend current point
            //         rev->points[0] = removed->points[(removed->point_count - 1)-j];
            //         rev->point_count++;

            //         printf("temp extended reversed ridge: \n");
            //         for (int j = 0; j < rev->point_count; ++j)
            //             printf("(%d, %d) ", rev->points[j].x, rev->points[j].y);
            //         printf("\n");
            //     }Earlier
            // }

            // #undef printf
            // #define printf printf
            // printf("new extended of size %d: \n",extended->point_count);
            // for (int j = 0; j < extended->point_count; ++j)
            //     printf("(%d, %d) ", ridge_point_at(extended,j).x, ridge_point_at(extended,j).y);
            // printf("\n");
            // printf("new extended reversed of size:%d \n",extended->reversed->point_count);
            // for (int j = 0; j < extended->reversed->point_count; ++j)
            //     printf("(%d, %d) ", ridge_point_at(extended->reversed,j).x, ridge_point_at(extended->reversed,j).y);
            // printf("\n");

            // printf("new removed pf size:%d \n",removed->point_count);
            // for (int j = 0; j < removed->point_count; ++j)  
            //     printf("(%d, %d) ", ridge_point_at(removed,j).x, ridge_point_at(removed,j).y);
            // printf("\n");

            // printf("Setting new extended ridge as end for removed->endMinutia: (%d, %d)\n",
            //        removed->endMinutia->position.x, removed->endMinutia->position.y);
            
            // printf("Before removed->endMinutia: (%d, %d)\n",
            //        removed->endMinutia->position.x, removed->endMinutia->position.y);
            // for(int j = 0; j < removed->endMinutia->ridge_count; ++j) {
            //     SkeletonRidge* r = removed->endMinutia->ridges[j];
            //     printf("j: %d, Ridge %d with %d points from (%d, %d) to (%d, %d)\n",
            //         j, r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
            //         r->endMinutia->position.x, r->endMinutia->position.y);
            //     if(r->is_view==0) {
            //             for(int k = 0; k < r->point_count; ++k) {
            //                 printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
            //             }
            //     } else {
            //             SkeletonRidge* b = base_of(r);
            //             for(int k = 0; k < b->point_count; ++k) {
            //                 printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
            //             }
            //         }
            //     printf("\n");
            // }
            // // #define printf(...)

            #undef printf
            #define printf printf

            printf("Before removed->endMinutia: (%d, %d)\n",
                   removed->endMinutia->position.x, removed->endMinutia->position.y);
            for(int j = 0; j < removed->endMinutia->ridge_count; ++j) {
                SkeletonRidge* r = removed->endMinutia->ridges[j];
                printf("Ridge %d with %d points from (%d, %d) to (%d, %d)\n",
                    j, r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                    r->endMinutia->position.x, r->endMinutia->position.y);
                for (int k = 0; k < r->point_count; ++k) {
                    printf("(%d, %d) ", ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                }
                printf("\n");
            }

            // printf("extended->point_count: %d, extended->reversed->point_count: %d\n",extended->point_count,extended->reversed->point_count);
            // #define printf(...)

            // Set new end for extended ridge
            ridge_set_end(extended, removed->endMinutia);

            #undef printf
            #define printf printf
            printf("After removed->endMinutia: (%d, %d)\n",
                   removed->endMinutia->position.x, removed->endMinutia->position.y);
            for(int j = 0; j < removed->endMinutia->ridge_count; ++j) {
                SkeletonRidge* r = removed->endMinutia->ridges[j];
                // if(r->startMinutia && r->endMinutia)
                    printf("Ridge %d with %d points from (%d, %d) to (%d, %d)\n",
                       j, r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                       r->endMinutia->position.x, r->endMinutia->position.y);
                for (int k = 0; k < r->point_count; ++k) {
                    printf("(%d, %d) ", ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                }
                printf("\n");
            }
            // #define printf(...)

            // printf("Detaching removed ridge from current minutia\n");
            // Detach removed ridge from minutiae
            ridge_detach(removed);  // Implement this to detach from both start and end minutiae
        }
    }

    apply_skeleton_dot_filter(skeleton); // Also convert and call SkeletonDotFilter
}

void apply_skeleton_pore_filter(Skeleton* skeleton) {
    for (int i = 0; i < skeleton->count; ++i) {
        SkeletonMinutia* minutia = skeleton->minutiae[i];

        if (minutia->ridge_count == 3) {
            for (int exit = 0; exit < 3; ++exit) {
                SkeletonRidge* exit_ridge = minutia->ridges[exit];
                SkeletonRidge* arm1 = minutia->ridges[(exit + 1) % 3];
                SkeletonRidge* arm2 = minutia->ridges[(exit + 2) % 3];

                SkeletonMinutia* common_end = arm1->endMinutia;
                if (common_end == arm2->endMinutia &&
                    exit_ridge->endMinutia != common_end &&
                    common_end != minutia &&
                    exit_ridge->endMinutia != minutia) {

                    if (common_end->ridge_count == 3 &&
                        arm1->point_count <= MAX_PORE_ARM &&
                        arm2->point_count <= MAX_PORE_ARM) {
                        printf("exit: %d; ",exit);
                        printf("exit_ridge->startMinutia: (%d, %d), exit_ridge->endMinutia: (%d, %d)\n",exit_ridge->startMinutia->position.x, exit_ridge->startMinutia->position.y,exit_ridge->endMinutia->position.x, exit_ridge->endMinutia->position.y);
                        printf("arm1->startMinutia: (%d, %d), arm1->endMinutia: (%d, %d)\n",arm1->startMinutia->position.x, arm1->startMinutia->position.y,arm1->endMinutia->position.x, arm1->endMinutia->position.y);
                        printf("arm2->startMinutia: (%d, %d), arm2->endMinutia: (%d, %d)\n",arm2->startMinutia->position.x, arm2->startMinutia->position.y,arm2->endMinutia->position.x, arm2->endMinutia->position.y);
    
                        // minutia_detach_end(arm1->endMinutia, arm1);
                        // minutia_detach_end(arm2->endMinutia, arm2);
                        // minutia_detach_start(minutia, arm1);
                        // minutia_detach_start(minutia, arm2);
                        ridge_detach(arm1); ridge_detach(arm2);

                        SkeletonRidge* merged = create_ridge();
                        ridge_set_start(merged, minutia);
                        ridge_set_end(merged, common_end);

                        IntPointArray* path = line_to(minutia->position, common_end->position);
                        for (int j = 0; j < path->size; ++j)
                            push_point_skeletonridge(merged, path->data[j]);

                        free(path->data);
                        free(path);
                    }
                    break;
                }
            }
        }
    }

    #undef printf
    #define printf printf
    printf("Before pore filter's knot filter: Number of minutiae: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            // if(r->startMinutia && r->endMinutia)
                printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
                if(r->is_view==0) {
                    for(int k = 0; k < r->point_count; ++k) {
                        printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                    }
                } else {
                    SkeletonRidge* b = base_of(r);
                    for(int k = 0; k < b->point_count; ++k) {
                        printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                    }
                }
            printf("\n");
        }
    }
    // #define printf(...)

    apply_skeleton_knot_filter(skeleton); // You must implement this too.
    // Optionally add: log_skeleton("removed-pores", skeleton);

    #undef printf
    #define printf printf
    printf("After pore filter's knot filter: Number of minutiae: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
            if(r->is_view==0) {
                for(int k = 0; k < r->point_count; ++k) {
                    printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                }
            } else {
                SkeletonRidge* b = base_of(r);
                for(int k = 0; k < b->point_count; ++k) {
                    printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                }
            }
            printf("\n");
        }
    }
    // #define printf(...)
}

//////////////// GAP FILTER ///////

// Utility: Subtract two IntPoints
IntPoint subtract_points(IntPoint a, IntPoint b) {
    IntPoint result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

// Helper: square of integer
int square(int value) {
    return value * value;
}



// atan2 wrapper
float double_angle_atan(IntPoint a, IntPoint b) {
    float angle= atan2((float)(b.y - a.y), (float)(b.x - a.x));
    return (angle >=0) ? angle : angle+PI2;
}

// Angle difference in radians, always positive, <= PI
float double_angle_distance(float a1, float a2) {
    float diff = fabs(a1 - a2);
    return diff > M_PI ? 2 * M_PI - diff : diff;
}

// Return angle opposite to given angle
float double_angle_opposite(float angle) {
    angle += M_PI;
    if (angle > 2 * M_PI)
        angle -= 2 * M_PI;
    return angle;
}

BooleanMatrix* skeleton_shadow(Skeleton* skeleton, IntPoint size) {
    BooleanMatrix* shadow= create_boolean_matrix_pointer(size.x, size.y);

    for (int i = 0; i < skeleton->count; ++i) {
        SkeletonMinutia* minutia = skeleton->minutiae[i];
        boolean_matrix_set(shadow, minutia->position.x, minutia->position.y, true);

        for (int j = 0; j < minutia->ridge_count; ++j) {
            SkeletonRidge* ridge = minutia->ridges[j];

            if (ridge->startMinutia->position.y <= ridge->startMinutia->position.y) {
                for (int k = 0; k < ridge->point_count; ++k) {
                    // IntPoint p = ridge->points[k];
                    IntPoint p = ridge_point_at(ridge, k);
                    boolean_matrix_set(shadow, p.x, p.y, true);
                }
            }
        }
    }

    return shadow;
}



typedef struct {
    int distance;
    SkeletonMinutia* end1;
    SkeletonMinutia* end2;
} SkeletonGap;

// Helper to compare gaps (priority queue: smallest distance first)
int compare_gaps(const void* a, const void* b) {
    return ((SkeletonGap*)a)->distance - ((SkeletonGap*)b)->distance;
}

static void add_gap_ridge(BooleanMatrix* shadow, SkeletonGap* gap, IntPointArray* line) {
    printf("Adding ridge for gap between (%d, %d) and (%d, %d)\n",
           gap->end1->position.x, gap->end1->position.y,
           gap->end2->position.x, gap->end2->position.y);
    
    SkeletonRidge* ridge = create_ridge();
    for (int i = 0; i < line->size; ++i)
        push_point_skeletonridge(ridge, line->data[i]);

    printf("Adding ridge: in add_gap_ridge\n");
    for(int i = 0; i < ridge->point_count; ++i) {
        printf("(%d, %d) ",ridge_point_at(ridge, i).x, ridge_point_at(ridge, i).y);
        // printf("(%d, %d) ", ridge->points[i].x, ridge->points[i].y);
    }
    printf("\n");

    printf("gap.end2 before: \n");
    for(int i = 0; i < gap->end2->ridge_count; ++i) {
        printf("Ridge number %d with %d points: ", i, gap->end2->ridges[i]->point_count);
        for(int j = 0; j < gap->end2->ridges[i]->point_count; ++j) {
            printf("(%d, %d) ", ridge_point_at(gap->end2->ridges[i], j).x, ridge_point_at(gap->end2->ridges[i], j).y);
        }
        printf("\n");
    }

    ridge_set_start(ridge, gap->end1);
    ridge_set_end(ridge, gap->end2);

    printf("gap.end2 after: \n");
    for(int i = 0; i < gap->end2->ridge_count; ++i) {
        printf("Ridge number %d with %d points: ", i, gap->end2->ridges[i]->point_count);
        for(int j = 0; j < gap->end2->ridges[i]->point_count; ++j) {
            printf("(%d, %d) ", ridge_point_at(gap->end2->ridges[i], j).x, ridge_point_at(gap->end2->ridges[i], j).y);
        }
        printf("\n");
    }

    for (int i = 0; i < line->size; ++i)
        set_boolean_matrix(shadow, line->data[i].x, line->data[i].y, true);
}



static bool is_ridge_overlapping(IntPointArray* line, BooleanMatrix* shadow) {
    for (int i = TOLERATED_GAP_OVERLAP; i < line->size - TOLERATED_GAP_OVERLAP; ++i)
        if (get_boolean_matrix_safe(shadow, line->data[i].x, line->data[i].y))
            return true;
    return false;
}

static IntPoint angle_sample_for_gap_removal(SkeletonMinutia* minutia) {
    SkeletonRidge* ridge = minutia->ridges[0];
    if (GAP_ANGLE_OFFSET < ridge->point_count)
        return ridge_point_at(ridge, GAP_ANGLE_OFFSET);
        // return ridge->points[GAP_ANGLE_OFFSET];
    else
        return ridge->endMinutia->position;
}

static bool is_within_gap_limits(SkeletonMinutia* end1, SkeletonMinutia* end2) {
    IntPoint delta = subtract_points(end1->position, end2->position);
    int distanceSq = delta.x * delta.x + delta.y * delta.y;
    // printf("Distance squared: %d\n", distanceSq);

    if (distanceSq <= square(MAX_RUPTURE_SIZE))
        return true;
    if (distanceSq > square(MAX_GAP_SIZE))
        return false;

    float gapDirection = double_angle_atan(end1->position, end2->position);
    // printf("end1->position: (%d, %d), end2->position: (%d, %d)\n",
    //        end1->position.x, end1->position.y,
    //        end2->position.x, end2->position.y);
    // printf("anglesample_for_gap_removal(end1): (%d, %d)\n",
    //        angle_sample_for_gap_removal(end1).x, angle_sample_for_gap_removal(end1).y);
    float direction1 = double_angle_atan(end1->position, angle_sample_for_gap_removal(end1));
    // printf("gapDirection: %f, direction1: %f\n", gapDirection, direction1);
    // printf("double_angle_distance(direction1, double_angle_opposite(gapDirection)): %f\n",double_angle_distance(direction1, double_angle_opposite(gapDirection)));   
    
    if (double_angle_distance(direction1, double_angle_opposite(gapDirection)) > MAX_GAP_ANGLE)
        return false;

    float direction2 = double_angle_atan(end2->position, angle_sample_for_gap_removal(end2));
    // printf("direction2: %f\n", direction2);
    // printf("double_angle_distance(direction2, gapDirection): %f\n",double_angle_distance(direction2, gapDirection));
    if (double_angle_distance(direction2, gapDirection) > MAX_GAP_ANGLE)
        return false;

    return true;
}

void apply_skeleton_gap_filter(Skeleton* skeleton) {
    SkeletonGap queue[1000];
    int queue_size = 0;

    for (int i = 0; i < skeleton->count; ++i) {
        SkeletonMinutia* end1 = skeleton->minutiae[i];
        if (end1->ridge_count == 1 && end1->ridges[0]->point_count >= SHORTEST_JOINED_ENDING) {
            for (int j = 0; j < skeleton->count; ++j) {
                SkeletonMinutia* end2 = skeleton->minutiae[j];
                // printf("Checking gap between (%d, %d) and (%d, %d)\n",
                //        end1->position.x, end1->position.y,
                //        end2->position.x, end2->position.y);
                // printf("end1==end2: %d \n", end1 == end2);
                // printf("end2->ridge_count: %d \n", end2->ridge_count);
                // printf("end1->ridges[0]->endMinutia!= end2: %d \n", end1->ridges[0]->endMinutia != end2);
                // printf("end2->ridges[0]->point_count: %d \n",
                //        end2->ridges[0]->point_count);
                // printf("SHORTEST_JOINED_ENDING: %d \n", SHORTEST_JOINED_ENDING);
                // printf("is_within_gap_limits: %d \n", is_within_gap_limits(end1, end2));

                if (end1!=end2 &&
                    end2->ridge_count == 1 &&
                    end1->ridges[0]->endMinutia != end2 &&
                    end2->ridges[0]->point_count >= SHORTEST_JOINED_ENDING &&
                    is_within_gap_limits(end1, end2)) {

                    SkeletonGap gap;
                    IntPoint diff = subtract_points(end1->position, end2->position);
                    gap.distance = diff.x * diff.x + diff.y * diff.y;
                    gap.end1 = end1;
                    gap.end2 = end2;

                    queue[queue_size++] = gap;
                }
            }
        }
    }

    #undef printf
    #define printf printf
    printf("Gap filter: Found %d gaps\n", queue_size);
    for(int i=0;i<queue_size;i++)
    {
        SkeletonGap* gap = &queue[i];
        printf("Gap %d: (%d, %d) to (%d, %d) with distance %d\n",
               i, gap->end1->position.x, gap->end1->position.y,
               gap->end2->position.x, gap->end2->position.y,
               gap->distance);
    }
    // #define printf(...)

    qsort(queue, queue_size, sizeof(SkeletonGap), compare_gaps);

    BooleanMatrix* shadow = skeleton_shadow(skeleton, skeleton->size);  // You must define this helper

    for (int i = 0; i < queue_size; ++i) {
        SkeletonGap* gap = &queue[i];
        if (gap->end1->ridge_count == 1 && gap->end2->ridge_count == 1) {
            IntPointArray* line = line_to(gap->end1->position, gap->end2->position);
            if (!is_ridge_overlapping(line, shadow))
                add_gap_ridge(shadow, gap, line);
            free(line->data);
            free(line);
        }
    }

    #undef printf
        #define printf printf
    printf("Before gap filter's knot filter: Number of minutiae: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            // if(r->startMinutia && r->endMinutia)
                printf(" Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
                if(r->is_view==0) {
                    for(int k = 0; k < r->point_count; ++k) {
                        printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                    }
                } else {
                    SkeletonRidge* b = base_of(r);
                    for(int k = 0; k < b->point_count; ++k) {
                        printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                    }
                }
                printf("\n");
            // for (int k = 0; k < r->point_count; ++k)
            // {
            //     printf("[%d,%d] ", ridge_point_at(r,k).x, ridge_point_at(r,k).y);
            // }
            // printf("\n");
        }
    }
    // #define printf(...)

    apply_skeleton_knot_filter(skeleton);  // Implemented earlier
    // TransparencySink logging omitted in C version

    #undef printf
    #define printf printf
    printf("After gap filter's knot filter: Number of minutiae: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            // if(r->startMinutia && r->endMinutia)
                printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
            
                if(r->is_view==0) {
                    for(int k = 0; k < r->point_count; ++k) {
                        printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                    }
                } else {
                    SkeletonRidge* b = base_of(r);
                    for(int k = 0; k < b->point_count; ++k) {
                        printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                    }
                }
                printf("\n");
            // for (int k = 0; k < r->point_count; ++k)
            // {
            //     printf("(%d, %d) ", ridge_point_at(r,k).x, ridge_point_at(r,k).y);
            // }
            // printf("\n");
        }
    }
    // #define printf(...)

}

/// TailFIlter //////////////

void apply_skeleton_tail_filter(Skeleton* skeleton) {
    for (int i = 0; i < skeleton->count; ++i) {
        SkeletonMinutia* minutia = skeleton->minutiae[i];
        if (minutia->ridge_count == 1) {
            SkeletonRidge* ridge = minutia->ridges[0];
            SkeletonMinutia* end = ridge->endMinutia;
            if (end != NULL && end->ridge_count >= 3) {
                if (ridge->point_count < MIN_TAIL_LENGTH) {
                    ridge_detach(ridge);
                }
            }
        }
    }

    apply_skeleton_dot_filter(skeleton);
    apply_skeleton_knot_filter(skeleton);

    // TransparencySink.current().logSkeleton("removed-tails", skeleton);
    // Logging or debugging output can be added here if needed.
}

void apply_skeleton_fragment_filter(Skeleton* skeleton) {
    for (int i = 0; i < skeleton->count; ++i) {
        SkeletonMinutia* minutia = skeleton->minutiae[i];

        if (minutia->ridge_count == 1) {
            SkeletonRidge* ridge = minutia->ridges[0];
            SkeletonMinutia* end = ridge->endMinutia;

            printf("Checking minutia at (%d, %d) with end->ridge_count %d and ridge->point_count %d\n",
                   minutia->position.x, minutia->position.y, end ? end->ridge_count : 0, ridge->point_count);

            if (end != NULL && end->ridge_count == 1 && ridge->point_count < MIN_FRAGMENT_LENGTH) {
                printf("Detaching fragment ridge from minutia at (%d, %d) with end at (%d, %d) and  ridge->count %d\n",
                       minutia->position.x, minutia->position.y,
                       end->position.x, end->position.y, ridge->point_count);
                ridge_detach(ridge);
            }
        }
    }

    printf("Before fragment filter's dot filter: Number of minutiae: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            // if(r->startMinutia && r->endMinutia)
                printf(" Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
            for (int k = 0; k < r->point_count; ++k)
            {
                printf("[%d,%d] ", ridge_point_at(r,k).x, ridge_point_at(r,k).y);
            }
            printf("\n");
        }
    }

    apply_skeleton_dot_filter(skeleton);

    printf("After fragment filter's dot filter: Number of minutiae: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            // if(r->startMinutia && r->endMinutia)
                printf(" Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
            for (int k = 0; k < r->point_count; ++k)
            {
                printf("[%d,%d] ", ridge_point_at(r,k).x, ridge_point_at(r,k).y);
            }
            printf("\n");
        }
    }

    // Transparency logging equivalent, if needed:
    // log_skeleton("removed-fragments", skeleton);
}

void apply_skeleton_filters(Skeleton* skeleton) {
    #undef printf
        #define printf printf
    apply_skeleton_dot_filter(skeleton);
    // log_skeleton("removed-dots", skeleton); // Optional: implement if you need logging like Java
    printf("After dot filter: Number of minutiae: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            // if(r->startMinutia && r->endMinutia)
                printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
                if(r->is_view==0) {
                    for(int k = 0; k < r->point_count; ++k) {
                        printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                    }
                } else {
                    SkeletonRidge* b = base_of(r);
                    for(int k = 0; k < b->point_count; ++k) {
                        printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                    }
                }
                printf("\n");
        }
    }


    apply_skeleton_pore_filter(skeleton);
    printf("After pore filter: Number of minutiae: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            // if(r->startMinutia && r->endMinutia)
                printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
                if(r->is_view==0) {
                    for(int k = 0; k < r->point_count; ++k) {
                        printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                    }
                } else {
                    SkeletonRidge* b = base_of(r);
                    for(int k = 0; k < b->point_count; ++k) {
                        printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                    }
                }
                printf("\n");
        }
    }

    apply_skeleton_gap_filter(skeleton);
    printf("After gap filter: Number of minutiae: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            // if(r->startMinutia && r->endMinutia)
                printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
                if(r->is_view==0) {
                    for(int k = 0; k < r->point_count; ++k) {
                        printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                    }
                } else {
                    SkeletonRidge* b = base_of(r);
                    for(int k = 0; k < b->point_count; ++k) {
                        printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                    }
                }
                printf("\n");
        }
    }


    apply_skeleton_tail_filter(skeleton);
    printf("After tail filter: Number of minutiae: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            // if(r->startMinutia && r->endMinutia)
            printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
            if(r->is_view==0) {
                for(int k = 0; k < r->point_count; ++k) {
                    printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                }
            } else {
                SkeletonRidge* b = base_of(r);
                for(int k = 0; k < b->point_count; ++k) {
                    printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                }
            }
            printf("\n");
        }
    }

    apply_skeleton_fragment_filter(skeleton);
    printf("After fragment filter: Number of minutiae: %d minutiae\n", skeleton->count);
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            // if(r->startMinutia && r->endMinutia)
            printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
            if(r->is_view==0) {
                for(int k = 0; k < r->point_count; ++k) {
                    printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                }
            } else {
                SkeletonRidge* b = base_of(r);
                for(int k = 0; k < b->point_count; ++k) {
                    printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                }
            }
            printf("\n");
        }
    }

    // #define printf(...)
}


Skeleton* Skeletons_create(BooleanMatrix binary, SkeletonType type) {
    // Log the input binary skeleton
    // char label[256];
    // snprintf(label, sizeof(label), "%sbinarized-skeleton", type.prefix);
    // log_transparency(label, binary);

    // Thinning
    BooleanMatrix thinned = thin(&binary, type);

    printf("Thinned skeleton: width=%d, height=%d\n", thinned.width, thinned.height);
    for (int i = 0; i < thinned.height; ++i) {
        for (int j = 0; j < thinned.width; ++j) {
            printf("%d ", get_boolean_matrix(&thinned, j, i));
        }
        printf("\n");
    }

    // Skeleton* skeleton;

    // // Tracing
    Skeleton* skeleton = trace(&thinned, type);
    #undef printf
        #define printf printf
    printf("After trace: Number of minutiae: %d minutiae\n", skeleton->count);
    // #define printf(...)
    free(thinned.cells);

    #undef printf
    #define printf printf    
    for (int i = 0; i < skeleton->count; ++i)
    {
        SkeletonMinutia* m = skeleton->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
                if(r->is_view==0) {
                    for(int k = 0; k < r->point_count; ++k) {
                        printf("(%d, %d) ",ridge_point_at(r,k).x, ridge_point_at(r,k).y);
                    }
                } else {
                    SkeletonRidge* b = base_of(r);
                    for(int k = 0; k < b->point_count; ++k) {
                        printf("(%d, %d) ",b->points[b->point_count-1-k].x, b->points[b->point_count-1-k].y);
                    }
                }
                printf("\n");
        }
    }
    // #define printf(...)

    // // Optional: Free thinned if not needed anymore
    // free_boolean_matrix(&thinned);

    // Filtering
    apply_skeleton_filters(skeleton);

    return skeleton;
}

/////////////// Minutiacollector ///////////////////

typedef enum {
    MINUTIA_ENDING,
    MINUTIA_BIFURCATION
} MinutiaType;    

typedef struct {
    IntPoint position;
    float direction;
    MinutiaType type;
} FeatureMinutia;

typedef struct {
    FeatureMinutia* data;
    int size;
    int capacity;
} FeatureMinutiaArray;

void init_feature_minutia_array(FeatureMinutiaArray* arr) {
    arr->size = 0;
    arr->capacity = 8;
    arr->data = malloc(arr->capacity * sizeof(FeatureMinutia));
}

void push_feature_minutia(FeatureMinutiaArray* arr, FeatureMinutia value) {
    if (arr->size == arr->capacity) {
        // arr->capacity *= 2;
        arr->capacity = arr->capacity * 3 / 2 + 1;

        arr->data = realloc(arr->data, arr->capacity * sizeof(FeatureMinutia));
    }
    arr->data[arr->size++] = value;
    printf("arr->size: %d\n",arr->size);
}



// Direction function for ridge
float ridge_direction(SkeletonRidge* ridge) {
    int first = RIDGE_DIRECTION_SKIP;
    int last = RIDGE_DIRECTION_SKIP + RIDGE_DIRECTION_SAMPLE - 1;

    if (last >= ridge->point_count) {
        int shift = last - ridge->point_count + 1;
        last -= shift;
        first -= shift;
    }

    if (first < 0)
        first = 0;

    return (float)(atan_from_points(ridge_point_at(ridge, first), ridge_point_at(ridge, last)));
    // return double_angle_atan(ridge->points[first], ridge->points[last]);
}


void collect_minutiae(FeatureMinutiaArray* out, Skeleton* skeleton, MinutiaType type) {
    for (int i = 0; i < skeleton->count; ++i) {
        SkeletonMinutia* sminutia = skeleton->minutiae[i];
        // SkeletonMinutia* sminutia = &skeleton->minutiae[i];
        printf("sminutia->ridge_count: %d\n",sminutia->ridge_count);
        if (sminutia->ridge_count == 1) {
            FeatureMinutia fminutia;
            fminutia.position = sminutia->position;
            fminutia.direction = ridge_direction(sminutia->ridges[0]);
            fminutia.type = type;
            printf("Adding fminutia.direction: %f\n",fminutia.direction);
            push_feature_minutia(out, fminutia);
        }
    }
}

FeatureMinutiaArray collect_all_minutiae(Skeleton* ridges, Skeleton* valleys) {
    FeatureMinutiaArray result;
    init_feature_minutia_array(&result);
    printf("COllecting all\n");
    collect_minutiae(&result, ridges, MINUTIA_ENDING);
    collect_minutiae(&result, valleys, MINUTIA_BIFURCATION);
    return result;
}

typedef struct {
    IntPoint size;
    FeatureMinutiaArray minutiae;
} FeatureTemplate;

FeatureTemplate* create_feature_template(IntPoint size, FeatureMinutiaArray minutiae) {
    FeatureTemplate* template = malloc(sizeof(FeatureTemplate));
    template->size = size;
    template->minutiae = minutiae;
    return template;
}

void FeatureTemplate_free(FeatureTemplate* ft) {
    if (!ft) return;

    // Free the owned minutiae buffer
    free(ft->minutiae.data);
    ft->minutiae.data = NULL;
    ft->minutiae.size = 0;
    ft->minutiae.capacity = 0;

    // Free the struct
    free(ft);
}


IntPoint double_matrix_size(DoubleMatrix *matrix) {
    IntPoint size;
    size.x = matrix->width;
    size.y = matrix->height;
    return size;
}

/////////// InnerMinutiaeFilter //////////////

IntPoint int_point_add(IntPoint a, IntPoint b) {
    IntPoint result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}


void inner_minutiae_filter_apply(FeatureMinutiaArray* minutiae, BooleanMatrix* mask) {
    int dst = 0;
    for (int src = 0; src < minutiae->size; ++src) {
        FeatureMinutia m = minutiae->data[src];
        DoublePoint vec = to_vector(m.direction);
        DoublePoint displacement = multiply_doublepoint(vec, -MASK_DISPLACEMENT);
        IntPoint arrow = round_doublepoint(displacement);
        IntPoint displaced = int_point_add(m.position, arrow);
        if(boolean_matrix_get_fallback(mask, displaced.x, displaced.y, false))
        {
            minutiae->data[dst++] = m;
        }
    }
    minutiae->size = dst;
}

/////////////////// CloudFilter //////////////////////

int int_point_length_sq(IntPoint p) {
    return p.x * p.x + p.y * p.y;
}

IntPoint int_point_subtract(IntPoint a, IntPoint b) {
    IntPoint result = { a.x - b.x, a.y - b.y };
    return result;
}

void remove_feature_minutia_at(FeatureMinutiaArray* array, int index) {
    for (int i = index + 1; i < array->size; ++i)
        array->data[i - 1] = array->data[i];
    array->size--;
}

void apply_minutia_cloud_filter(FeatureMinutiaArray* minutiae, int radius) {
    int radius_sq = radius * radius;

    // Mark which minutiae to remove
    bool* remove_flags = calloc(minutiae->size, sizeof(bool));

    for (int i = 0; i < minutiae->size; ++i) {
        int count = 0;
        for (int j = 0; j < minutiae->size; ++j) {
            if (i == j) continue;
            IntPoint diff = int_point_subtract(minutiae->data[j].position, minutiae->data[i].position);
            if (int_point_length_sq(diff) <= radius_sq)
                count++;
        }
        if (count > MAX_CLOUD_SIZE)
            remove_flags[i] = true;
    }

    // Remove in reverse to preserve indices
    for (int i = minutiae->size - 1; i >= 0; --i) {
        if (remove_flags[i])
            remove_feature_minutia_at(minutiae, i);
    }

    free(remove_flags);
}

///////////////////// TopMinutiaeFilter ///////////////////////

typedef struct {
    FeatureMinutia minutia;
    int sort_key;
} SortableMinutia;

int compare_sortable_minutiae_desc(const void* a, const void* b) {
    const SortableMinutia* ma = (const SortableMinutia*)a;
    const SortableMinutia* mb = (const SortableMinutia*)b;
    return mb->sort_key - ma->sort_key; // Descending order
}

int compute_sort_key(FeatureMinutia* m, FeatureMinutia* all, int size) {
    int* distances = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        IntPoint delta = int_point_subtract(m->position, all[i].position);
        distances[i] = int_point_length_sq(delta);
    }

    // Simple sort (e.g., insertion sort since array is small)
    for (int i = 1; i < size; ++i) {
        int key = distances[i];
        int j = i - 1;
        while (j >= 0 && distances[j] > key) {
            distances[j + 1] = distances[j];
            j--;
        }
        distances[j + 1] = key;
    }

    int result = (SORT_BY_NEIGHBOR < size)
        ? distances[SORT_BY_NEIGHBOR]
        : INT_MAX;

    free(distances);
    return result;
}

// static FeatureMinutiaArray* clone_feature_minutia_array(const FeatureMinutiaArray* src) {
//     FeatureMinutiaArray* dst = (FeatureMinutiaArray*)malloc(sizeof(FeatureMinutiaArray));
//     if (!dst) { perror("malloc"); return NULL; }
//     dst->size = src->size;
//     dst->capacity = src->size;
//     dst->data = NULL;
//     if (dst->size) {
//         dst->data = malloc((size_t)dst->size * sizeof(FeatureMinutia));
//         if (!dst->data) { free(dst); perror("malloc"); return NULL; }
//         memcpy(dst->data, src->data, (size_t)dst->size * sizeof(FeatureMinutia));
//     }
//     return dst;
// }


FeatureMinutiaArray* apply_top_minutiae_filter(const FeatureMinutiaArray* input) {
    if (input->size <= MAX_MINUTIAE) {
        FeatureMinutiaArray* result = input; // return as is
        return result;
    }

    SortableMinutia* sortable = malloc(input->size * sizeof(SortableMinutia));
    for (int i = 0; i < input->size; ++i) {
        sortable[i].minutia = input->data[i];
        sortable[i].sort_key = compute_sort_key(&input->data[i], input->data, input->size);
    }

    qsort(sortable, input->size, sizeof(SortableMinutia), compare_sortable_minutiae_desc);

    FeatureMinutiaArray* result=(FeatureMinutiaArray*)malloc(sizeof(FeatureMinutiaArray));
    result->size = MAX_MINUTIAE;
    result->capacity = MAX_MINUTIAE;
    result->data = malloc(result->capacity * sizeof(FeatureMinutia));

    for (int i = 0; i < result->size; ++i) {
        result->data[i] = sortable[i].minutia;
    }

    free(sortable);

    free(input->data);
    free(input);

    return result;
}


const char* minutia_type_to_string(MinutiaType type) {
    switch (type) {
        case MINUTIA_ENDING: return "ENDING";
        case MINUTIA_BIFURCATION: return "BIFURCATION";
        default: return "UNKNOWN";
    }
}

void print_feature_minutia_array(const FeatureMinutiaArray* array) {
    printf("After TopMinutiaeFilter: \n");
    for (int i = 0; i < array->size; ++i) {
        FeatureMinutia* m = &array->data[i];
        printf("Minutia %d:\n", i);
        printf("  Position: (%d, %d)\n", m->position.x, m->position.y);
        printf("  Direction: %.3f radians\n", m->direction);
        printf("  Type: %s\n", minutia_type_to_string(m->type));
    }
}


///////////////// FeatureTemplate ///////////////////////



FeatureTemplate* create_feature_template_from_list(IntPoint size, FeatureMinutiaArray* source) {
    FeatureTemplate* ft = malloc(sizeof(FeatureTemplate));
    if (!ft) return NULL;

    ft->size = size;
    ft->minutiae.size = source->size;
    ft->minutiae.capacity = source->size;

    ft->minutiae.data = malloc(sizeof(FeatureMinutia) * source->size);
    if (!ft->minutiae.data) {
        free(ft);
        return NULL;
    }

    memcpy(ft->minutiae.data, source->data, sizeof(FeatureMinutia) * source->size);
    printf("Freeing source->data in create_feature_template_from_list\n");
    free(source->data);
    // free(source);

    return ft;
}

void free_feature_template(FeatureTemplate* ft){
    if (ft) {
        if (ft->minutiae.data) {
            free(ft->minutiae.data);
        }
        free(ft);
    }
}


void print_feature_template(const FeatureTemplate* ft) {
    printf("FeatureTemplate:\n");
    printf("  Size: (%d, %d)\n", ft->size.x, ft->size.y);
    printf("  Minutiae count: %d\n", ft->minutiae.size);

    for (int i = 0; i < ft->minutiae.size; ++i) {
        FeatureMinutia* m = &ft->minutiae.data[i];
        const char* type_str = (m->type == MINUTIA_ENDING) ? "ENDING" : "BIFURCATION";
        printf("    Minutia %d: position=(%d, %d), direction=%.2f, type=%s\n",
               i, m->position.x, m->position.y, m->direction, type_str);
    }
}

// If ridge is reversed and base 
static void destroy_ridge_once(SkeletonRidge* r) {
    if (!r) return;
    printf("r->is_view: %d\n", r->is_view);

    SkeletonRidge* b = base_of(r);
    printf("b->freed: %d, b->point_count: %d, b->point_capacity: %d\n", b->freed, b->point_count, b->point_capacity);

    if (!b || b->freed) return;     // already freed, do nothing
    b->freed = 1;

    printf("Freeing base ridge at %p with %d points: ", (void*)b, b->point_count);
    for(int k=0; k < b->point_count; ++k) {
        printf("(%d, %d) ",ridge_point_at(b,k).x, ridge_point_at(b,k).y);
    }
    printf("\n");

    free(b->points);
    b->points = NULL;
    b->point_count = b->point_capacity = 0;

    // if (b->reversed) {
    //     SkeletonRidge* v = b->reversed;

    //     // Defensive: if legacy code ever allocated v->points, free it
    //     // if (v->points) { free(v->points); v->points = NULL; }

    //     // b->reversed = NULL;          // break the back-link first
    //     // v->reversed = NULL;

    //     free(v);
    // }

    if(b!=r)
        free(r);

    free(b);
}

void free_skeleton(Skeleton* skel) {
    if (!skel) return;

    // Free ridges once
    for (int i = 0; i < skel->count; ++i) {
        SkeletonMinutia* m = skel->minutiae[i];
        if (!m) continue;
        for (int j = 0; j < m->ridge_count; ++j) {
            printf("\nMinutia %d, Ridge %d: Freeing ridge at %p\n", i, j, (void*)m->ridges[j]);
            destroy_ridge_once(m->ridges[j]);
            m->ridges[j] = NULL; // optional: avoid accidental reuse
        }
    }

    // Free minutiae (just the arrays + structs)
    for (int i = 0; i < skel->count; ++i) {
        SkeletonMinutia* m = skel->minutiae[i];
        if (!m) continue;
        free(m->ridges);
        free(m);
        skel->minutiae[i] = NULL;
    }

    free(skel->minutiae);
    free(skel);
}


////////////////////////////
FeatureTemplate* extract(DoubleMatrix raw, int dpi, int flag)
{
    IntPoint pixels;
    pixels.x = raw.width;
    pixels.y = raw.height;

    BlockMap blocks = create_block_map(pixels.x, pixels.y, 20);   // PARAMTERS.BLOCK_SIZE=15
    printf("After create_block_map:\n");
    // print_sram_usage();
    // sleep_ms(8000); 

    printf("blocks.pixels.x: %d, blocks.pixels.y: %d\n", blocks.pixels.x, blocks.pixels.y);
    
    printf("blocks.primary.blocks.x: %d, blocks.primary.blocks.y: %d\n", blocks.primary.blocks.x, blocks.primary.blocks.y);
    printf("blocks.primary.corners.x: %d, blocks.primary.corners.y: %d\n", blocks.primary.corners.x, blocks.primary.corners.y);
    for(int i=0;i<blocks.primary.corners.x;i++)
    {
        printf("blocks.primary.x[%d]: %d\n",i,blocks.primary.x[i]);
    }
    for(int i=0;i<blocks.primary.corners.y;i++)
    {
        printf("blocks.primary.y[%d]: %d\n",i,blocks.primary.y[i]);
    }   

    printf("blocks.secondary.blocks.x: %d, blocks.secondary.blocks.y: %d\n", blocks.secondary.blocks.x, blocks.secondary.blocks.y);
    printf("blocks.secondary.corners.x: %d, blocks.secondary.corners.y: %d\n", blocks.secondary.corners.x, blocks.secondary.corners.y);
    for(int i=0;i<blocks.secondary.corners.x;i++)
    {
        printf("blocks.secondary.x[%d]: %d\n",i,blocks.secondary.x[i]);
    }
    for(int i=0;i<blocks.secondary.corners.y;i++)
    {   
        printf("blocks.secondary.y[%d]: %d\n",i,blocks.secondary.y[i]);
    }

    /////////// HISTOGRAMCUBE ////////////////////
    HistogramCube histogram = create_histogram_cube_from_point(blocks.primary.blocks, 256);
    printf("After create_histogram_cube_from_point:\n");
    // print_sram_usage();
    // sleep_ms(8000); 
    
    // Fill the histogram using image data
    for (int by = 0; by < blocks.primary.blocks.y; ++by) {
        for (int bx = 0; bx < blocks.primary.blocks.x; ++bx) {
            IntPoint block = {bx, by};
            IntRect area = blockgrid_block_point(&blocks.primary, block);
            IntPoint topLeft = {area.x, area.y};
            IntPoint bottomRight = {area.x + area.width, area.y + area.height};

            for (int y = topLeft.y; y < bottomRight.y; ++y) {
                for (int x = topLeft.x; x < bottomRight.x; ++x) {
                    float pixel = get(&raw,x,y); // grayscale in [0, 1)
                    int depth = (int)(pixel * histogram.bins);
                    depth = histogram_cube_constrain(&histogram, depth);
                    histogram_cube_increment_at(&histogram, block, depth);
                    printf("Incrementing histgram at: %d, %d, %d\n",block.x, block.y, depth);
                }
            }
        }
    }
    
    print_histogram_cube(&histogram);
    printf("-----------------------------------\n");

    HistogramCube smoothHistogram = histogramcube_smooth(&blocks, &histogram);  
    print_histogram_cube(&smoothHistogram);

    /////////////// SEGMENTATIONMASK //////////////////

    BooleanMatrix mask = compute_mask(blocks, histogram);
    free(histogram.counts);
    printf("Freed histogram.counts\n");
    DoubleMatrix equalized = equalize_image(blocks, raw, smoothHistogram, mask);
    // free(smoothHistogram.counts);

    printf("equalized.width: %d, equalized.height: %d\n", equalized.width, equalized.height);
    for(int i=0;i<equalized.height;i++)
    {
        for(int j=0;j<equalized.width;j++)
        {
            printf("%f ",double_matrix_get(&equalized,j,i));
        }
        printf("\n");
    }

    for(int i=0;i<blocks.primary.corners.x;i++)
    {
        printf("BBBlocks.primary.x[%d]: %d\n",i,blocks.primary.x[i]);
    }
    for(int i=0;i<blocks.primary.corners.y;i++)
    {
        printf("BBBlocks.primary.y[%d]: %d\n",i,blocks.primary.y[i]);
    }

    // BlockOrientation.compute(equalized, mask, blocks);
    DoubleMatrix orientation = compute_orientation(equalized, mask, blocks);
    printf("Before smooth- orientation.width: %d, orientation.height: %d\n", orientation.width, orientation.height);
    // OrientedSmoothing.parallel(equalized, orientation, mask, blocks)

    DoubleMatrix smoothed = oriented_smoothing_parallel(equalized, orientation,mask,&blocks);
    printf("smoothed.width: %d, smoothed.height: %d\n", smoothed.width, smoothed.height);
    for(int i=0;i<smoothed.height;i++)
    {
        for(int j=0;j<smoothed.width;j++)
        {   
            printf("%f ",double_matrix_get(&smoothed,j,i));
        }
        printf("\n");
    }

    free(equalized.data);

    DoubleMatrix orthogonal = oriented_smoothing_orthogonal(smoothed, orientation, mask, &blocks);
    free(orientation.data);

    printf("orthogonal.width: %d, orthogonal.height: %d\n", orthogonal.width, orthogonal.height);
    for(int i=0;i<orthogonal.height;i++)
    {
        for(int j=0;j<orthogonal.width;j++)
        {   
            printf("%f ",double_matrix_get(&orthogonal,j,i));
        }
        printf("\n");
    }

    // Binarization
    BooleanMatrix binary = binarize(&smoothed, &orthogonal, &mask, &blocks);
    free(orthogonal.data);
    free(smoothed.data);

    printf("binary.width: %d, binary.height: %d\n", binary.width, binary.height);
    for(int i = 0; i < binary.height; ++i) {
        for (int j = 0; j < binary.width; ++j) {
            printf("%d ", get_boolean(&binary, j, i));
        }
        printf("\n");
    }

    BooleanMatrix pixelMask = pixelwise(&mask, &blocks);
    free(mask.cells);
    free(blocks.primary.x); free(blocks.primary.y); free(blocks.secondary.x); free(blocks.secondary.y);

    printf("pixelMask.width: %d, pixelMask.height: %d\n", pixelMask.width, pixelMask.height);
    for(int i = 0; i < pixelMask.height; ++i) {
        for (int j = 0; j < pixelMask.width; ++j) {
            printf("%d ", get_boolean(&pixelMask, j, i));
        }
        printf("\n");
    }

    binarize_cleanup(&binary, &pixelMask);

    BooleanMatrix inverted = invert(&binary, &pixelMask);
    printf("inverted.width: %d, inverted.height: %d\n", inverted.width, inverted.height);
    for(int i = 0; i < inverted.height; ++i) {
        for (int j = 0; j < inverted.width; ++j) {
            printf("%d ", get_boolean(&inverted, j, i));
        }
        printf("\n");
    }

    // for(int i = 0; i < innerMask.height; ++i) {
    //     for (int j = 0; j < innerMask.width; ++j) {
    //         printf("%d ", get_boolean(&innerMask, j, i));
    //     }
    //     printf("\n");
    // }

    BooleanMatrix innerMask = inner(&pixelMask);
    free(pixelMask.cells);

    Skeleton* ridges = Skeletons_create(binary, SKELETON_RIDGES);
    free(binary.cells);

    printf("After Skeletons.create: Ridges created with %d minutiae\n", ridges->count);
    for (int i = 0; i < ridges->count; ++i)
    {
        SkeletonMinutia* m = ridges->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
            for (int k = 0; k < r->point_count; ++k)
            {
                printf("(%d, %d) ", ridge_point_at(r,k).x, ridge_point_at(r,k).y);
            }
            printf("\n");
        }
    }

    // sleep_ms(3000);

    Skeleton* valleys = Skeletons_create(inverted, SKELETON_VALLEYS);

    printf("After Skeletons.create: Valleys created with %d minutiae\n", valleys->count);
    for (int i = 0; i < valleys->count; ++i)
    {
        SkeletonMinutia* m = valleys->minutiae[i];
        printf("Minutia %d at (%d, %d) with %d ridges\n", i, m->position.x, m->position.y, m->ridge_count);
        for (int j = 0; j < m->ridge_count; ++j)
        {
            SkeletonRidge* r = m->ridges[j];
            printf("Ridge with %d points from (%d, %d) to (%d, %d)\n",
                   r->point_count, r->startMinutia->position.x, r->startMinutia->position.y,
                   r->endMinutia->position.x, r->endMinutia->position.y);
            for (int k = 0; k < r->point_count; ++k)
            {
                printf("(%d, %d) ", ridge_point_at(r,k).x, ridge_point_at(r,k).y);
            }
            printf("\n");
        }
    }

    /////////////////////// MinutiaCollector //////////////////////////

    free(inverted.cells);
    IntPoint size = double_matrix_size(&raw);  // Equivalent of raw.size()
    
    if(flag==0)
        free(raw.data);

    FeatureMinutiaArray minutiae = collect_all_minutiae(ridges, valleys);  // MinutiaCollector.collect(...)
    printf("minutia.size: %d\n",minutiae.size);
    
    free_skeleton(ridges);
    free_skeleton(valleys);
    
    FeatureTemplate* template = create_feature_template(size, minutiae);

    // free(minutiae.data); // minutiae data is now owned by template
    
    printf("Template Size: (%d, %d)\n", template->size.x, template->size.y);
    printf("Number of Minutiae: %d\n", template->minutiae.size);
    
    for (int i = 0; i < template->minutiae.size; ++i) {
        FeatureMinutia m = template->minutiae.data[i];
        const char* type_str = (m.type == MINUTIA_ENDING) ? "ENDING" :
                               (m.type == MINUTIA_BIFURCATION) ? "BIFURCATION" : "UNKNOWN";
        
        printf("Minutia %d: ", i);
        printf("Position- (%d, %d); ", m.position.x, m.position.y);
        printf("Direction- %.2f radians; ", m.direction);
        printf("Type- %s\n", type_str);
    }

    /////////////// InnerMinutiaeFilter ///////////////////////////////

    inner_minutiae_filter_apply(&template->minutiae, &innerMask);
    // free(innerMask.cells);

    printf("After InnerMinutiaeFilter - Template Size: (%d, %d)\n", template->size.x, template->size.y);
    printf("Number of Minutiae: %d\n", template->minutiae.size);
    
    for (int i = 0; i < template->minutiae.size; ++i) {
        FeatureMinutia m = template->minutiae.data[i];
        const char* type_str = (m.type == MINUTIA_ENDING) ? "ENDING" :
                               (m.type == MINUTIA_BIFURCATION) ? "BIFURCATION" : "UNKNOWN";
        
        printf("Minutia %d: ", i);
        printf("Position- (%d, %d); ", m.position.x, m.position.y);
        printf("Direction- %.2f radians; ", m.direction);
        printf("Type- %s\n", type_str);
    }

    /////////////// MinutiaeCloudFilter ////////////////////

    apply_minutia_cloud_filter(&template->minutiae, MINUTIA_CLOUD_RADIUS);
    printf("After cloudFilter - Template Size: (%d, %d)\n", template->size.x, template->size.y);
    printf("Number of Minutiae: %d\n", template->minutiae.size);
    
    for (int i = 0; i < template->minutiae.size; ++i) {
        FeatureMinutia m = template->minutiae.data[i];
        const char* type_str = (m.type == MINUTIA_ENDING) ? "ENDING" :
                               (m.type == MINUTIA_BIFURCATION) ? "BIFURCATION" : "UNKNOWN";
        
        printf("Minutia %d: ", i);
        printf("Position- (%d, %d); ", m.position.x, m.position.y);
        printf("Direction- %.2f radians; ", m.direction);
        printf("Type- %s\n", type_str);
    }

    /////////////// TopMinutiaeFilter ////////////////////////////

    FeatureMinutiaArray* top_minutiae_filter_result = apply_top_minutiae_filter(&template->minutiae);
    printf("After topMinutiae - Template Size: (%d, %d)\n", template->size.x, template->size.y);
    printf("Number of Minutiae: %d\n", template->minutiae.size);
    
    for (int i = 0; i < template->minutiae.size; ++i) {
        FeatureMinutia m = template->minutiae.data[i];
        const char* type_str = (m.type == MINUTIA_ENDING) ? "ENDING" :
                               (m.type == MINUTIA_BIFURCATION) ? "BIFURCATION" : "UNKNOWN";
        
        printf("Minutia %d: ", i);
        printf("Position- (%d, %d); ", m.position.x, m.position.y);
        printf("Direction- %.2f radians; ", m.direction);
        printf("Type- %s\n", type_str);
    }
    // free(template->minutiae.data); // free old minutiae data

    print_feature_minutia_array(top_minutiae_filter_result);

    //////////// FeatureTemplate /////////////////

    FeatureTemplate* template_final = create_feature_template_from_list(template->size, top_minutiae_filter_result);
    print_feature_template(template_final);

    return template_final;

}
//////////// SearchTemplate /////////////////////

/////// Search Minutaie //////
typedef struct {
    short x;
    short y;
    float direction;
    MinutiaType type;
} SearchMinutia;

SearchMinutia create_search_minutia(const FeatureMinutia* feature) {
    SearchMinutia sm;
    sm.x = (short)feature->position.x;
    sm.y = (short)feature->position.y;
    sm.direction = feature->direction;
    sm.type = feature->type;
    return sm;
}

FeatureMinutia to_feature_minutia(const SearchMinutia* sm) {
    FeatureMinutia fm;
    fm.position.x = sm->x;
    fm.position.y = sm->y;
    fm.direction = sm->direction;
    fm.type = sm->type;
    return fm;
}


size_t search_minutia_memory() {
    return 2 * sizeof(short) + sizeof(float) + sizeof(MinutiaType);
    // If you want to mimic Java object overhead + reference: add sizeof(void*) as REFERENCE
}

///// MemoryEstimates ///////


typedef struct {
    int BITNESS;
    int REFERENCE;
    int MARK;
    int OBJECT_HEADER;
    int ARRAY_HEADER;
    int PADDING;
} MemoryEstimates;

static inline int detect_bitness() {
#if defined(__x86_64__) || defined(_M_X64) || defined(__aarch64__)
    return 64;
#elif defined(__i386__) || defined(_M_IX86) || defined(__arm__) || defined(__MIPSEL__)
    return 32;
#else
    return sizeof(void*) * 8; // fallback
#endif
}

// Padding utility
static inline int pad(int padding, int size) {
    return ((size + padding - 1) / padding) * padding;
}

static inline int default_pad(int size) {
    return pad(8, size); // 8 is default alignment
}

// Assume compressed references (4 bytes) even on 64-bit (like in Java)
static inline void init_memory_estimates(MemoryEstimates* m) {
    m->BITNESS = detect_bitness();
    m->REFERENCE = 4;
    m->MARK = m->BITNESS / 8;
    m->OBJECT_HEADER = m->MARK + m->REFERENCE;
    m->PADDING = 8;
    m->ARRAY_HEADER = m->OBJECT_HEADER + 4;
}

// Memory for object with `fields` bytes, aligned to largest field `alignment`
static inline int memory_estimates_object(MemoryEstimates* m, int fields, int alignment) {
    return default_pad(pad(alignment, m->OBJECT_HEADER) + fields);
}

// Memory for array of `count` elements of `component` bytes each
static inline int memory_estimates_array(MemoryEstimates* m, int component, int count) {
    return default_pad(pad(component, m->ARRAY_HEADER) + component * count);
}

////// Edge Shape //////

// const int POLAR_DISTANCE_CACHE[POLAR_CACHE_SIZE] __in_flash() = { 0 };
// const float POLAR_ANGLE_CACHE[POLAR_CACHE_SIZE]    __in_flash() = { 0.0f };

// static int POLAR_DISTANCE_CACHE [POLAR_CACHE_SIZE];
// static float POLAR_ANGLE_CACHE[POLAR_CACHE_SIZE];

// Precompute caches
void init_edge_shape_cache(int* POLAR_DISTANCE_CACHE, float* POLAR_ANGLE_CACHE) {
    for (int y = 0; y < POLAR_CACHE_RADIUS; ++y) {
        for (int x = 0; x < POLAR_CACHE_RADIUS; ++x) {
            int index = y * POLAR_CACHE_RADIUS + x;
            POLAR_DISTANCE_CACHE[index] = java_round(sqrt(x * x + y * y));
            if (y > 0 || x > 0)
                POLAR_ANGLE_CACHE[index] = atan2f((float)y, (float)x);  // equivalent to DoubleAngle.atan
            else
                POLAR_ANGLE_CACHE[index] = 0.0f;
        }
    }
}



typedef struct {
    short length;
    float referenceAngle;
    float neighborAngle;
} EdgeShape;



float float_angle_difference(float a, float b) {
    float angle = a-b;
    printf("float_angle_difference: first=%.2f, second=%.2f, angle=%.2f\n", a, b, angle);
    return angle>=0 ? angle : angle + 2 * M_PI; // Normalize to [0, 2π)
}

float float_angle_opposite(float angle) {
    return angle < M_PI ? angle + M_PI : angle - M_PI; 
}

// float float_angle_distance(float first, float second) {
//     float delta = fabsf(first - second);
//     return (delta <= M_PI) ? delta : 2 * M_PI - delta;
// }

float float_angle_distance(float first, float second) {
    printf("In float_angle_distance: first=%.2f, second=%.2f\n", first, second);
    float delta = fabsf(first - second);
    printf("delta: %.2f\n", delta);
    // delta = fmodf(delta, 2.0f * (float)M_PI); // Normalize to [0, 2π)

    return (delta <= (float)M_PI) ? delta : (2.0f * (float)M_PI - delta);
}

// Constructor from two SearchMinutiae
EdgeShape* create_edge_shape(SearchMinutia reference, SearchMinutia neighbor) {
    int POLAR_DISTANCE_CACHE[POLAR_CACHE_SIZE]= { 0 };
    float POLAR_ANGLE_CACHE[POLAR_CACHE_SIZE]  = { 0.0f };

    init_edge_shape_cache(POLAR_DISTANCE_CACHE, POLAR_ANGLE_CACHE);

    float quadrant = 0.0f;
    int x = neighbor.x - reference.x;
    int y = neighbor.y - reference.y;
    printf("create_edge_shape: x=%d, y=%d\n", x, y);

    if (y < 0) {
        x = -x;
        y = -y;
        quadrant = M_PI;
    }
    printf("new x=%d, y=%d, quadrant=%.2f\n", x, y, quadrant);

    if (x < 0) {
        int tmp = -x;
        x = y;
        y = tmp;
        quadrant += HALF_PI;
    }

    printf("2 new x=%d, y=%d, quadrant=%.2f\n", x, y, quadrant);

    unsigned int combined = (x | y) >> POLAR_CACHE_BITS;
    printf("combined: %d\n", combined);
    int shift = (combined == 0) ? 0 : 32 - __builtin_clz(combined);
    printf("shift: %d\n", shift);

    int offset = ((y >> shift) * POLAR_CACHE_RADIUS) + (x >> shift);
    printf("offset: %d\n", offset);
    int cached_distance = POLAR_DISTANCE_CACHE[offset];
    printf("cached_distance: %d\n", cached_distance);
    float angle = POLAR_ANGLE_CACHE[offset] + quadrant;
    printf("angle: %.2f\n", angle);
    printf("reference.direction: %.2f, neighbor.direction: %.2f\n", reference.direction, neighbor.direction);
    printf("float_angle_opposite(angle): %.2f\n", float_angle_opposite(angle));

    EdgeShape* shape= (EdgeShape*)malloc(sizeof(EdgeShape));
    shape->length = (short)(cached_distance << shift);
    printf("length: %d\n", shape->length);
    shape->referenceAngle = float_angle_difference(reference.direction, angle);
    printf("referenceAngle: %.3f\n", shape->referenceAngle);
    shape->neighborAngle = float_angle_difference(neighbor.direction, float_angle_opposite(angle));
    printf("neighborAngle: %.3f\n", shape->neighborAngle);

    // printf("EdgeShape created: length=%d, reference_angle=%.3f, neighbor_angle=%.3f\n",
    //        shape->length, shape->referenceAngle, shape->neighborAngle);
    return shape;
}

////// NeighborEdge ///////////

typedef struct {
    EdgeShape* shape;
    short neighbor;
} NeighborEdge;

NeighborEdge* NeighborEdge_new(SearchMinutia* minutiae, int reference, int neighbor) {
    NeighborEdge* edge = malloc(sizeof(NeighborEdge));
    edge->shape = create_edge_shape(minutiae[reference], minutiae[neighbor]);
    edge->neighbor = (short)neighbor;
    return edge;
}

// Comparison function for qsort
static int compare_edge_length(const void* a, const void* b) {
    float len_a = ((NeighborEdge*)a)->shape->length;
    float len_b = ((NeighborEdge*)b)->shape->length;
    return (len_a > len_b) - (len_a < len_b);
}

// Comparator function: sort by length, then neighbor
int compare_edges(const void* a, const void* b) {
    const NeighborEdge* e1 = (const NeighborEdge*)a;
    const NeighborEdge* e2 = (const NeighborEdge*)b;

    if (e1->shape->length != e2->shape->length)
        return (e1->shape->length > e2->shape->length) - (e1->shape->length < e2->shape->length);
    
    return (e1->neighbor > e2->neighbor) - (e1->neighbor < e2->neighbor);
}

int compare_ints(const int* a, const int* b) {
    return (*a) - (*b);
}

NeighborEdge** build_table(const SearchMinutia* minutiae, int count, int* edge_count) {
    NeighborEdge** edges = malloc(count * sizeof(NeighborEdge*));
    int* sq_distances = malloc(count * sizeof(int));
    NeighborEdge* star = malloc(count * sizeof(NeighborEdge)); // temporary array

    for (int reference = 0; reference < count; ++reference) {
        const SearchMinutia* rminutia = &minutiae[reference];
        int maxSqDistance = INT_MAX;

        // evaluated maxSqDistance
        if (count - 1 > EDGE_TABLE_NEIGHBORS) {
            for (int neighbor = 0; neighbor < count; ++neighbor) {
                const SearchMinutia* nminutia = &minutiae[neighbor];
                sq_distances[neighbor] = sq(rminutia->x - nminutia->x) + sq(rminutia->y - nminutia->y);
            }
            // sort copy of sq_distances
            int* sorted = malloc(count * sizeof(int));
            memcpy(sorted, sq_distances, count * sizeof(int));
            qsort(sorted, count, sizeof(int), compare_ints);
            maxSqDistance = sorted[EDGE_TABLE_NEIGHBORS];
            free(sorted);
        }

        printf("maxSqDistance for reference %d: %d\n", reference, maxSqDistance);

        int star_size = 0;
        for (int neighbor = 0; neighbor < count; ++neighbor) {
            if (neighbor == reference)
                continue;
            int dist = sq(rminutia->x - minutiae[neighbor].x) + sq(rminutia->y - minutiae[neighbor].y);
            if (dist <= maxSqDistance) {
                printf("neighbour: %d, distance: %d\n", neighbor, dist);
                star[star_size].shape = create_edge_shape(*rminutia, minutiae[neighbor]);
                star[star_size].neighbor = (short)neighbor;
                ++star_size;
            }
        }

        qsort(star, star_size, sizeof(NeighborEdge), compare_edges);

        if (star_size > EDGE_TABLE_NEIGHBORS)
            star_size = EDGE_TABLE_NEIGHBORS;

        edges[reference] = malloc(star_size * sizeof(NeighborEdge));
        memcpy(edges[reference], star, star_size * sizeof(NeighborEdge));
        // You may want to store size info externally or in a struct

        edge_count[reference] = star_size;
    }

    free(sq_distances);
    free(star);
    return edges;
}

void free_table(NeighborEdge** edges, int count) {
    if (!edges) return;

    for (int i = 0; i < count; i++) {
        if (edges[i]) {
            free(edges[i]);  // free each neighbor list
        }
    }
    free(edges); // free the outer pointer array
}


int NeighborEdge_memory() {
    MemoryEstimates* m = (MemoryEstimates*)(malloc(sizeof(MemoryEstimates)));
    return memory_estimates_object(m, 2 * sizeof(short) + 2 * sizeof(float), sizeof(float));
}

///// SearchTemplate //////

#define PRIME 1610612741

typedef struct {
    short width;
    short height;
    SearchMinutia* minutiae;
    int minutiae_count;
    NeighborEdge** edges; // edges[i] is an array of NeighborEdge
    int* edge_counts;     // lengths of each edges[i]
} SearchTemplate;

// Empty constant (equivalent to SearchTemplate.EMPTY)
SearchTemplate* SearchTemplate_empty() {
    SearchTemplate* st = (SearchTemplate*)calloc(1, sizeof(SearchTemplate));
    st->width = 1;
    st->height = 1;
    st->minutiae = NULL;
    st->minutiae_count = 0;
    st->edges = NULL;
    st->edge_counts = NULL;
    return st;
}

// Comparison function for qsort
int compare_search_minutia(const void* a, const void* b) {
    const SearchMinutia* m1 = (const SearchMinutia*)a;
    const SearchMinutia* m2 = (const SearchMinutia*)b;

    int hash1 = ((m1->x * PRIME) + m1->y) * PRIME;
    int hash2 = ((m2->x * PRIME) + m2->y) * PRIME;

    if (hash1 != hash2)
        return (hash1 > hash2) - (hash1 < hash2); // avoids overflow

    if (m1->x != m2->x)
        return (m1->x > m2->x) - (m1->x < m2->x);

    if (m1->y != m2->y)
        return (m1->y > m2->y) - (m1->y < m2->y);

    if (m1->direction != m2->direction)
        return (m1->direction > m2->direction) - (m1->direction < m2->direction);

    return m1->type - m2->type; // assuming enum values are ordered
}


SearchTemplate* SearchTemplate_new(const FeatureTemplate* features) {
    if (!features) return NULL;

    SearchTemplate* st = (SearchTemplate*)malloc(sizeof(SearchTemplate));
    if (!st) return NULL;

    st->width = (short)features->size.x;
    st->height = (short)features->size.y;

    st->minutiae_count = features->minutiae.size;
    st->minutiae = (SearchMinutia*)malloc(sizeof(SearchMinutia) * st->minutiae_count);
    st->edge_counts = (int*)malloc(sizeof(int) * st->minutiae_count);

    if (!st->minutiae) {
        free(st);
        return NULL;
    }

    // creating the searchtemplate's minutiae from original template's minutaie's
    for (int i = 0; i < st->minutiae_count; ++i)
        st->minutiae[i] = create_search_minutia(&features->minutiae.data[i]);

    qsort(st->minutiae, st->minutiae_count, sizeof(SearchMinutia), compare_search_minutia);

    for(int i=0;i<st->minutiae_count;i++)
    {
        printf("Minutia %d: x=%d, y=%d, direction=%.2f, type=%s\n",
               i, st->minutiae[i].x, st->minutiae[i].y, st->minutiae[i].direction, minutia_type_to_string(st->minutiae[i].type));
    }

    // Build edge table and get edge counts per minutia
    st->edges = build_table(st->minutiae, st->minutiae_count, st->edge_counts);
    if (!st->edges) {
        free(st->minutiae);
        free(st);
        return NULL;
    }

    return st;
}

void SearchTemplate_free(SearchTemplate* st) {
    if (!st) return;

    // Free the edge table if it has its own allocations
    if (st->edges) {
        free_table(st->edges, st->minutiae_count);  
    }

    // Free arrays allocated in SearchTemplate_new
    free(st->minutiae);
    free(st->edge_counts);

    // Finally free the struct itself
    free(st);
}

// Convert back to FeatureTemplate
FeatureTemplate* SearchTemplate_to_feature(const SearchTemplate* st) {
    FeatureTemplate* ft = (FeatureTemplate*)malloc(sizeof(FeatureTemplate));
    ft->size = (IntPoint){ st->width, st->height };
    ft->minutiae.size = st->minutiae_count;
    ft->minutiae.data = (FeatureMinutia*)malloc(sizeof(FeatureMinutia) * ft->minutiae.size);
    for (int i = 0; i < ft->minutiae.size; ++i)
        ft->minutiae.data[i] = to_feature_minutia(&st->minutiae[i]);
    return ft;
}

// Memory estimate
int SearchTemplate_memory(const SearchTemplate* st) {
    MemoryEstimates* m= (MemoryEstimates*)(malloc(sizeof(MemoryEstimates)));
    init_memory_estimates(m);

    int mem = memory_estimates_object(m, 2 * sizeof(short) + 2 * m->REFERENCE,  m->REFERENCE);
    mem += memory_estimates_array(m, m->REFERENCE, st->minutiae_count);
    mem += st->minutiae_count * search_minutia_memory();

    mem += memory_estimates_array( m, m->REFERENCE, st->minutiae_count);
    for (int i = 0; i < st->minutiae_count; ++i) {
        mem +=memory_estimates_array( m, m->REFERENCE, st->edge_counts[i]);
        mem += st->edge_counts[i] * NeighborEdge_memory();
    }
    return mem;
}


void print_search_template(SearchTemplate* template) {
    printf("SearchTemplate:\n");
    printf("Minutiae Count: %d\n", template->minutiae_count);

    for (int i = 0; i < template->minutiae_count; ++i) {
        SearchMinutia m = template->minutiae[i];
        printf("  Minutia[%d]: x=%d, y=%d, direction=%.2f, type=%s\n",
               i, m.x, m.y, m.direction,  minutia_type_to_string(m.type));
    }

    for (int i = 0; i < template->minutiae_count; ++i) {
        printf("  Edges[%d] (%d neighbors):\n", i, template->edge_counts[i]);
        for (int j = 0; j < template->edge_counts[i]; ++j) {
            NeighborEdge e = template->edges[i][j];
            printf("    → Neighbor=%d, length=%hd, referenceAngle=%.2f, neighborAngle=%.2f\n",
                   e.neighbor, e.shape->length, e.shape->referenceAngle, e.shape->neighborAngle);
        }
    }

    // FILE* file = fopen("minutiae_C_file.txt", "a"); // open in append mode
    // if (!file) {
    //     perror("Failed to open file");
    //     return;
    // }

    // fprintf(file, "SearchTemplate:\n");
    // fprintf(file, "Minutiae Count: %d\n", template->minutiae_count);

    // for (int i = 0; i < template->minutiae_count; ++i) {
    //     SearchMinutia m = template->minutiae[i];
    //     fprintf(file, "  Minutia[%d]: x=%d, y=%d, direction=%.2f, type=%s\n",
    //             i, m.x, m.y, m.direction, minutia_type_to_string(m.type));
    // }

    // for (int i = 0; i < template->minutiae_count; ++i) {
    //     fprintf(file, "  Edges[%d] (%d neighbors):\n", i, template->edge_counts[i]);
    //     for (int j = 0; j < template->edge_counts[i]; ++j) {
    //         NeighborEdge e = template->edges[i][j];
    //         fprintf(file, "    → Neighbor=%d, length=%hd, referenceAngle=%.2f, neighborAngle=%.2f\n",
    //                 e.neighbor, e.shape->length, e.shape->referenceAngle, e.shape->neighborAngle);
    //     }
    // }

    // // fprintf(file, "\n"); // add a blank line for readability

    // fclose(file);
}

////////// EdgeHashes ///////////////
#include "khash.h"

#define MAX_DISTANCE_ERROR 13       // Example value (use actual)
float MAX_ANGLE_ERROR = (float)(M_PI)/180*10; // Example value (use actual)
// #define MAX_ANGLE_ERROR ((float)(M_PI)/180*10)      // Example value (use actual)

typedef struct {
    char reference;
    char neighbor;
    EdgeShape* shape;  // Assuming you want to store EdgeShape info as well
} IndexedEdge;

typedef struct {
    IndexedEdge* data;
    int size;
    int capacity;
} IndexedEdgeList;

void IndexedEdge_init(IndexedEdge* edge, const SearchMinutia* minutiae, int reference, int neighbor) {
    edge->shape = create_edge_shape(minutiae[reference], minutiae[neighbor]);
    edge->reference = (char)reference;
    edge->neighbor = (char)neighbor;
}

KHASH_INIT(edge_map, int, IndexedEdgeList*, 1, kh_int_hash_func, kh_int_hash_equal)
typedef khash_t(edge_map) EdgeHashMap;

void indexed_edge_list_init(IndexedEdgeList* list) {
    list->size = 0;
    list->capacity = 4;
    list->data = malloc(sizeof(IndexedEdge) * list->capacity);
}

void indexed_edge_list_add(IndexedEdgeList* list, IndexedEdge edge) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        // list->capacity = list->capacity * 3 / 2+1; // Grow by 1.5x
        list->data = realloc(list->data, sizeof(IndexedEdge) * list->capacity);
    }
    list->data[list->size++] = edge;
}

float complementary(float angle) {
    float complement = PI2 - angle;
    return (complement < PI2) ? complement : (complement - PI2);
}

float float_angle_add(float start, float delta) {
    float angle = start + delta;
    printf("float_angle_add: start=%.3f, delta=%.3f, angle=%.3f\n", start, delta, angle);
    return (angle < PI2) ? angle : (angle - PI2);
}

int hash_edge_shape(EdgeShape* edge) {
    int lengthBin = edge->length / MAX_DISTANCE_ERROR;
    int referenceAngleBin = (int)(edge->referenceAngle / MAX_ANGLE_ERROR);
    int neighborAngleBin = (int)(edge->neighborAngle / MAX_ANGLE_ERROR);
    return (referenceAngleBin << 24) + (neighborAngleBin << 16) + lengthBin;
}

bool matching(EdgeShape probe, EdgeShape candidate) {
    printf("Matching: probe.length=%d, candidate.length=%d, probe.referenceAngle=%.3f, candidate.referenceAngle=%.3f\n",
           probe.length, candidate.length, probe.referenceAngle, candidate.referenceAngle);
    int lengthDelta = probe.length - candidate.length;
    if (lengthDelta >= -MAX_DISTANCE_ERROR && lengthDelta <= MAX_DISTANCE_ERROR) {
        float refDelta = float_angle_difference(probe.referenceAngle, candidate.referenceAngle);
        float compAngleError = complementary(MAX_ANGLE_ERROR);
        if (refDelta <= MAX_ANGLE_ERROR || refDelta >= compAngleError) {
            float neighDelta = float_angle_difference(probe.neighborAngle, candidate.neighborAngle);
            if (neighDelta <= MAX_ANGLE_ERROR || neighDelta >= compAngleError)
            {
                printf("Matching successful: lengthDelta=%d, referenceDelta=%.3f, neighborDelta=%.3f\n",
                       lengthDelta, refDelta, neighDelta);
                return true;
            }
        }
    }
    printf("Matching failed\n");
    return false;
}

int* coverage(EdgeShape* edge, int* outSize) {
    printf("EdgeShape: length=%d, referenceAngle=%.3f, neighborAngle=%.3f\n",
           edge->length, edge->referenceAngle, edge->neighborAngle);
    printf("Maxdistance error: %d, Max angle error: %.3f\n", MAX_DISTANCE_ERROR, MAX_ANGLE_ERROR);
    int minLengthBin = (edge->length - MAX_DISTANCE_ERROR) / MAX_DISTANCE_ERROR;
    int maxLengthBin = (edge->length + MAX_DISTANCE_ERROR) / MAX_DISTANCE_ERROR;
    int angleBins = (int)ceilf((float)(2.0f * M_PI) / MAX_ANGLE_ERROR);

    float f1 = float_angle_difference(edge->referenceAngle, MAX_ANGLE_ERROR);
    int minReferenceBin = (int)(f1/ MAX_ANGLE_ERROR);
    f1=float_angle_add(edge->referenceAngle, MAX_ANGLE_ERROR);
    int maxReferenceBin = (int)(f1 / MAX_ANGLE_ERROR);
    int endReferenceBin = (maxReferenceBin + 1) % angleBins;

    f1=float_angle_difference(edge->neighborAngle, MAX_ANGLE_ERROR);
    int minNeighborBin = (int)(f1 / MAX_ANGLE_ERROR);
    f1=float_angle_add(edge->neighborAngle, MAX_ANGLE_ERROR);
    int maxNeighborBin = (int)(f1 / MAX_ANGLE_ERROR);
    int endNeighborBin = (maxNeighborBin + 1) % angleBins;

    printf("minLengthBin: %d, maxLengthBin: %d\n", minLengthBin, maxLengthBin);
    printf("minReferenceBin: %d, maxReferenceBin: %d, endReferenceBin: %d\n",
           minReferenceBin, maxReferenceBin, endReferenceBin);
    printf("minNeighborBin: %d, maxNeighborBin: %d, endNeighborBin: %d\n",
           minNeighborBin, maxNeighborBin, endNeighborBin);
    printf("angleBins: %d\n", angleBins);

    // Estimate max size
    int maxSize = (maxLengthBin - minLengthBin + 1) * angleBins * angleBins;
    int* result = (int*)malloc(maxSize * sizeof(int));
    int count = 0;

    for (int lengthBin = minLengthBin; lengthBin <= maxLengthBin; ++lengthBin) {
        for (int referenceBin = minReferenceBin;
             referenceBin != endReferenceBin;
             referenceBin = (referenceBin + 1) % angleBins) {

            printf("lengthBin: %d, referenceBin: %d\n", lengthBin, referenceBin);
            for (int neighborBin = minNeighborBin;
                 neighborBin != endNeighborBin;
                 neighborBin = (neighborBin + 1) % angleBins) {

                int code = (referenceBin << 24) + (neighborBin << 16) + lengthBin;

                printf("coverage[%d]: ReferenceBin=%d, NeighborBin=%d, LengthBin=%d, fin: %d\n",
                       count, referenceBin, neighborBin, lengthBin, code);
                result[count++] = code;
            }
        }
    }

    printf("Edge coverage: %d hashes\n", count);
    for(int i = 0; i < count; ++i) {
        printf("Hash %d: ReferenceBin=%d, NeighborBin=%d, LengthBin=%d\n",
               result[i], 
               (result[i] >> 24) & 0xFF, 
               (result[i] >> 16) & 0xFF, 
               result[i] & 0xFFFF);
    }

    *outSize = count;
    return result;
}


EdgeHashMap* build_edge_map(const SearchTemplate* template) {
    #undef printf
    #define printf printf
    printf("In build_edge_map\n");
    printf("template->minutiae_count: %d\n",template->minutiae_count);
    // Uses a khash map from int → IndexedEdgeList*
    // typedef khash_t(edge_map) EdgeHashMap;
    EdgeHashMap* map = kh_init(edge_map);

    for (int reference = 0; reference < template->minutiae_count; ++reference) {
        for (int neighbor = 0; neighbor < template->minutiae_count; ++neighbor) {
            printf("reference: %d, neighbor: %d\n",reference,neighbor);
            // print_sram_usage();
            // sleep_ms(1000);

            if (reference != neighbor) {
                IndexedEdge* edge = (IndexedEdge*)malloc(sizeof(IndexedEdge));
                IndexedEdge_init(edge, template->minutiae, reference, neighbor);

                int hash_count;
                int* hashes = coverage(edge->shape, &hash_count);  // You already have this

                // for(int i = 0; i < hash_count; ++i) {
                //     printf("hash: %d for edge (%d, %d)\n", hashes[i], reference, neighbor);
                // }

                for (int i = 0; i < hash_count; ++i) {
                    printf("hash: %d for edge (%d, %d)\n", hashes[i], reference, neighbor);
                    // extract k corresponding to hash index from map
                    // kh_get() returns an iterator k to the map location, or kh_end(map) if not found.
                    khiter_t k = kh_get(edge_map, map, hashes[i]); // Use hashes[i] instead of hash
                    IndexedEdgeList* list;
                    printf("Got k\n");

                    if (k == kh_end(map)) {
                        printf("k==kh_end\n");
                        // Not found, create new list
                        list = malloc(sizeof(IndexedEdgeList));
                        list->data = malloc(4 * sizeof(IndexedEdge)); // initial capacity
                        list->size = 0;
                        list->capacity = 4;
                        printf("Created list\n");

                        // putting empty initialized list into the map
                        int ret;
                        k = kh_put(edge_map, map, hashes[i], &ret);
                        printf("After kh_put\n");
                        kh_value(map, k) = list;
                        printf("Created new list for hash %d\n", hashes[i]);
                        for(int j=0;j<list->size;j++)
                        {
                            printf("list[%d] = (%d, %d)\n", j, list->data[j].reference, list->data[j].neighbor);
                        }
                    } else {
                        // Found
                        printf("k!=kh_end\n");
                        list = kh_value(map, k);
                        printf("Got list for hash %d\n", hashes[i]);
                        for(int j=0;j<list->size;j++)
                        {
                            printf("list[%d] = (%d, %d)\n", j, list->data[j].reference, list->data[j].neighbor);
                        }
                    }

                    // Append edge to list
                    if (list->size == list->capacity) {
                        list->capacity *= 2;
                        // list->capacity = list->capacity * 3 / 2 + 1; // Grow by 1.5x
                        list->data = realloc(list->data, list->capacity * sizeof(IndexedEdge));
                    }

                    // list->data[list->size++] = *edge;

                    IndexedEdge* dest = &list->data[list->size++]; // 
                    memcpy(dest, edge, sizeof(IndexedEdge));  // copy value (shallow first)

                    if (edge->shape) {
                        dest->shape = malloc(sizeof(EdgeShape));  // allocate new EdgeShape
                        if (!dest->shape) {
                            fprintf(stderr, "Failed to allocate EdgeShape\n");
                            exit(1);
                        }
                        memcpy(dest->shape, edge->shape, sizeof(EdgeShape));  // deep copy contents
                    } else {
                        dest->shape = NULL;
                    }

                    printf("Appended edge (%d, %d) to list for hash %d\n", dest->reference, dest->neighbor, hashes[i]);
                    printf("List after append: ");
                    for(int j=0;j<list->size;j++)
                    {
                        printf("(%d, %d) ", list->data[j].reference, list->data[j].neighbor);
                    }
                    printf("\n");

                }

                free(hashes);
                printf("--------------------------------\n");
            }
        }
    }

    // for (khiter_t k = kh_begin(map); k != kh_end(map); ++k) {
    //     // printf("Key: %d\n", kh_key(map, k));
    //     if (kh_exist(map, k)) {
    //         int hash = kh_key(map, k);
    //         IndexedEdgeList* list = kh_value(map, k);

    //         printf("Hash: %d\n", hash);
    //         for (int i = 0; i < list->size; ++i) {
    //             IndexedEdge* edge = &list->data[i];
    //             printf("  → Ref: %d, Nbr: %d, Distance: %d, RefAngle: %.2f, NbrAngle: %.2f\n",
    //                    edge->reference,
    //                    edge->neighbor,
    //                    edge->shape->length,
    //                    edge->shape->referenceAngle,
    //                    edge->shape->neighborAngle);
    //         }
    //     }
    // }

    // TransparencySink.current().logEdgeHash(map); // optional logging
    return map;

    #define printf(...)
}


// EdgeHashMap* build_edge_map(const SearchTemplate* template) {
//     // Uses a khash map from int → IndexedEdgeList*
//     // typedef khash_t(edge_map) EdgeHashMap;
//     EdgeHashMap* map = kh_init(edge_map);

//     for (int reference = 0; reference < template->minutiae_count; ++reference) {
//         for (int neighbor = 0; neighbor < template->minutiae_count; ++neighbor) {
//             if (reference != neighbor) {
//                 IndexedEdge* edge = (IndexedEdge*)malloc(sizeof(IndexedEdge));
//                 IndexedEdge_init(edge, template->minutiae, reference, neighbor);

//                 int hash_count;
//                 int* hashes = coverage(edge->shape, &hash_count);  // You already have this

//                 // for(int i = 0; i < hash_count; ++i) {
//                 //     printf("hash: %d for edge (%d, %d)\n", hashes[i], reference, neighbor);
//                 // }

//                 for (int i = 0; i < hash_count; ++i) {
//                     printf("hash: %d for edge (%d, %d)\n", hashes[i], reference, neighbor);
//                     // extract k corresponding to hash index from map
//                     // kh_get() returns an iterator k to the map location, or kh_end(map) if not found.
//                     khiter_t k = kh_get(edge_map, map, hashes[i]); // Use hashes[i] instead of hash
//                     IndexedEdgeList* list;

//                     if (k == kh_end(map)) {
//                         // Not found, create new list
//                         list = malloc(sizeof(IndexedEdgeList));
//                         list->data = malloc(4 * sizeof(IndexedEdge)); // initial capacity
//                         list->size = 0;
//                         list->capacity = 4;

//                         // putting empty initialized list into the map
//                         int ret;
//                         k = kh_put(edge_map, map, hashes[i], &ret);
//                         kh_value(map, k) = list;
//                         printf("Created new list for hash %d\n", hashes[i]);
//                         for(int j=0;j<list->size;j++)
//                         {
//                             printf("list[%d] = (%d, %d)\n", j, list->data[j].reference, list->data[j].neighbor);
//                         }
//                     } else {
//                         // Found
//                         list = kh_value(map, k);
//                         printf("Got list for hash %d\n", hashes[i]);
//                         for(int j=0;j<list->size;j++)
//                         {
//                             printf("list[%d] = (%d, %d)\n", j, list->data[j].reference, list->data[j].neighbor);
//                         }
//                     }

//                     // Append edge to list
//                     if (list->size == list->capacity) {
//                         list->capacity *= 2;
//                         // list->capacity = list->capacity * 3 / 2 + 1; // Grow by 1.5x
//                         list->data = realloc(list->data, list->capacity * sizeof(IndexedEdge));
//                     }

//                     // list->data[list->size++] = *edge;

//                     IndexedEdge* dest = &list->data[list->size++]; // 
//                     memcpy(dest, edge, sizeof(IndexedEdge));  // copy value (shallow first)

//                     if (edge->shape) {
//                         dest->shape = malloc(sizeof(EdgeShape));  // allocate new EdgeShape
//                         if (!dest->shape) {
//                             fprintf(stderr, "Failed to allocate EdgeShape\n");
//                             exit(1);
//                         }
//                         memcpy(dest->shape, edge->shape, sizeof(EdgeShape));  // deep copy contents
//                     } else {
//                         dest->shape = NULL;
//                     }

//                     printf("Appended edge (%d, %d) to list for hash %d\n", dest->reference, dest->neighbor, hashes[i]);
//                     printf("List after append: ");
//                     for(int j=0;j<list->size;j++)
//                     {
//                         printf("(%d, %d) ", list->data[j].reference, list->data[j].neighbor);
//                     }
//                     printf("\n");

//                 }

//                 free(hashes);
//                 printf("--------------------------------\n");
//             }
//         }
//     }

//     // for (khiter_t k = kh_begin(map); k != kh_end(map); ++k) {
//     //     // printf("Key: %d\n", kh_key(map, k));
//     //     if (kh_exist(map, k)) {
//     //         int hash = kh_key(map, k);
//     //         IndexedEdgeList* list = kh_value(map, k);

//     //         printf("Hash: %d\n", hash);
//     //         for (int i = 0; i < list->size; ++i) {
//     //             IndexedEdge* edge = &list->data[i];
//     //             printf("  → Ref: %d, Nbr: %d, Distance: %d, RefAngle: %.2f, NbrAngle: %.2f\n",
//     //                    edge->reference,
//     //                    edge->neighbor,
//     //                    edge->shape->length,
//     //                    edge->shape->referenceAngle,
//     //                    edge->shape->neighborAngle);
//     //         }
//     //     }
//     // }

//     // TransparencySink.current().logEdgeHash(map); // optional logging
//     return map;
// }
// EdgeHashMap* build_edge_map(const SearchTemplate* template) {
//     EdgeHashMap* map = kh_init(edge_map);

//     for (int reference = 0; reference < template->minutiae_count; ++reference) {
//         for (int neighbor = 0; neighbor < template->minutiae_count; ++neighbor) {
//             if (reference != neighbor) {
//                 IndexedEdge* edge = (IndexedEdge*)malloc(sizeof(IndexedEdge));
//                 IndexedEdge_init(edge, template->minutiae, reference, neighbor);

//                 int hash_count;
//                 int* hashes = coverage(edge->shape, &hash_count);  // You already have this

//                 for (int i = 0; i < hash_count; ++i) {
//                     // extract k corresponding to hash index from map
//                     khiter_t k = kh_get(edge_map, map, hashes[i]); // Use hashes[i] instead of hash
//                     IndexedEdgeList* list;

//                     if (k == kh_end(map)) {
//                         // Not found, create new list
//                         list = malloc(sizeof(IndexedEdgeList));
//                         list->data = malloc(4 * sizeof(IndexedEdge)); // initial capacity
//                         list->size = 0;
//                         list->capacity = 4;

//                         // putting empty initialized list into the map
//                         int ret;
//                         k = kh_put(edge_map, map, hashes[i], &ret);
//                         kh_value(map, k) = list;
//                     } else {
//                         // Found
//                         list = kh_value(map, k);
//                     }

//                     // Append edge to list
//                     if (list->size == list->capacity) {
//                         list->capacity *= 2;
//                         list->data = realloc(list->data, list->capacity * sizeof(IndexedEdge));
//                     }

//                     list->data[list->size++] = *edge;
//                 }

//                 free(hashes);
//             }
//         }
//     }

//     // TransparencySink.current().logEdgeHash(map); // optional logging
//     return map;
// }


void free_edge_map(EdgeHashMap* map) {
    for (khiter_t k = kh_begin(map); k != kh_end(map); ++k) {
        if (kh_exist(map, k)) {
            IndexedEdgeList* list = kh_value(map, k);
            free(list->data);
            free(list);
        }
    }
    kh_destroy(edge_map, map);
}

typedef struct {
    int key;
    IndexedEdgeList* value;
} SortedEntry;

// Comparison function for qsort
int compare_keys(const void* a, const void* b) {
    const SortedEntry* ea = (const SortedEntry*)a;
    const SortedEntry* eb = (const SortedEntry*)b;
    return ea->key - eb->key;
}

void print_edge_hash_map(EdgeHashMap* map) {
    // printf("EdgeHashMap contents:\n");
    // if (kh_size(map) == 0) {
    //     printf("  (empty)\n");
    //     return;
    // }
    // for (khiter_t k = kh_begin(map); k != kh_end(map); ++k) {
    //     printf("Key: %d\n", kh_key(map, k));
    //     if (kh_exist(map, k)) {
    //         int hash = kh_key(map, k);
    //         IndexedEdgeList* list = kh_value(map, k);

    //         printf("Hash: %d\n", hash);
    //         for (int i = 0; i < list->size; ++i) {
    //             IndexedEdge* edge = &list->data[i];
    //             printf("  → Ref: %d, Nbr: %d, Distance: %d, RefAngle: %.2f, NbrAngle: %.2f\n",
    //                    edge->reference,
    //                    edge->neighbor,
    //                    edge->shape->length,
    //                    edge->shape->referenceAngle,
    //                    edge->shape->neighborAngle);
    //         }
    //     }
    // }

    int count = 0;
    // First count entries
    for (khiter_t k = kh_begin(map); k != kh_end(map); ++k) {
        if (kh_exist(map, k)) count++;
    }

    // Allocate array for sorting
    SortedEntry* entries = malloc(count * sizeof(SortedEntry));
    int i = 0;

    // Fill the array
    for (khiter_t k = kh_begin(map); k != kh_end(map); ++k) {
        if (kh_exist(map, k)) {
            entries[i].key = kh_key(map, k);
            entries[i].value = kh_value(map, k);
            i++;
        }
    }

    // Sort the entries by key
    qsort(entries, count, sizeof(SortedEntry), compare_keys);

    // FILE *file = fopen("hash_map_C.txt", "w");

    // fprintf(file, "EdgeHashMap - Size of keys: %d\n", count);
    // // Print sorted
    // for (int j = 0; j < count; ++j) {
    //     int hash = entries[j].key;
    //     IndexedEdgeList* list = entries[j].value;

    //     fprintf(file, "Hash: %d\n", hash);
    //     for (int i = 0; i < list->size; ++i) {
    //         IndexedEdge* edge = &list->data[i];
    //         fprintf(file, "  → Ref: %d, Nbr: %d, Distance: %d, RefAngle: %.3f, NbrAngle: %.3f\n",
    //                edge->reference,
    //                edge->neighbor,
    //                edge->shape->length,
    //                edge->shape->referenceAngle,
    //                edge->shape->neighborAngle);
    //     }
    // }

    // fclose(file);

    free(entries);
}

/////////// Probe ///////////////
// Placeholder EMPTY template (define properly)
SearchTemplate EMPTY_SearchTemplate = {0};

// ----- Probe struct -----
typedef struct {
    SearchTemplate template;
    EdgeHashMap* hash;
} Probe;

// ----- NULL static instance -----
Probe Probe_NULL;

void Probe_init_null() {
    Probe_NULL.template = EMPTY_SearchTemplate;
    Probe_NULL.hash = kh_init(edge_map);  // Initializes empty hash map
}

// ----- Constructor with parameters -----
void Probe_init(Probe* probe, const SearchTemplate* template, EdgeHashMap* edgeHash) {
    memcpy(&probe->template, template, sizeof(SearchTemplate));
    probe->hash = edgeHash;
}

static inline void Probe_destroy(Probe* p, int free_hash) {
    if (!p) return;
    if (free_hash && p->hash) {
        // EdgeHashMap_free(p->hash);
        p->hash = NULL;
    }
    // DO NOT free p->templ here unless Probe owns it.
    free(p);
}

#define MEMORY_ESTIMATES_REFERENCE 4
#define INT_BYTES sizeof(int)

// // ----- Memory estimator -----
// int Probe_memory(const Probe* probe) {
//     int size = 0;
//     MemoryEstimates* m = (MemoryEstimates*)(malloc(sizeof(MemoryEstimates)));

//     size += memory_estimates_object(m, 2 * MEMORY_ESTIMATES_REFERENCE, MEMORY_ESTIMATES_REFERENCE); // 'object(2ref, 1ref)'
//     size += SearchTemplate_memory(&probe->template);

//     size += memory_estimates_object(m, 10 * MEMORY_ESTIMATES_REFERENCE, MEMORY_ESTIMATES_REFERENCE);
//     int hash_size = kh_size(probe->hash);
//     size += memory_estimates_array(m, INT_BYTES, hash_size * 3 / 2);
//     size += memory_estimates_array(m, MEMORY_ESTIMATES_REFERENCE, hash_size * 3 / 2);

//     for (khiter_t k = kh_begin(probe->hash); k != kh_end(probe->hash); ++k) {
//         if (!kh_exist(probe->hash, k)) continue;
//         IndexedEdgeList* list = kh_value(probe->hash, k);
//         int list_size = list->size;

//         size += memory_estimates_object(m, INT_BYTES + MEMORY_ESTIMATES_REFERENCE, MEMORY_ESTIMATES_REFERENCE);
//         size += memory_estimates_array(m, MEMORY_ESTIMATES_REFERENCE, list_size * 3 / 2 > 10 ? list_size * 3 / 2 : 10);
//         size += list_size * IndexedEdge_memory();
//     }

//     return size;
// }

////////// Match /////////////

/// MInutiaPair ////
typedef struct MinutiaPair {
    int probe;
    int candidate;
    int probeRef;
    int candidateRef;
    int distance;
    int supportingEdges;
} MinutiaPair;

// To string representation (similar to Java's toString)
void minutia_pair_to_string(const MinutiaPair* pair, char* buffer, size_t buffer_size) {
    snprintf(buffer, buffer_size, "%d<->%d @ %d<->%d #%d",
             pair->probe, pair->candidate,
             pair->probeRef, pair->candidateRef,
             pair->supportingEdges);
}

/// MinutiaPairPool ////
typedef struct MinutiaPairPool{
    MinutiaPair** pool;
    int pooled;
    int capacity;
} MinutiaPairPool;

MinutiaPairPool* create_minutia_pair_pool() {
    MinutiaPairPool* pool = malloc(sizeof(MinutiaPairPool));
    pool->capacity = 1;
    pool->pooled = 0;
    pool->pool = malloc(pool->capacity * sizeof(MinutiaPair*));
    return pool;
}

MinutiaPair* allocate_minutia_pair(MinutiaPairPool* pool) {
    if (pool->pooled > 0) {
        // printf("pool->pooled>0: pool->pooled = %d, pool->capacity = %d\n", pool->pooled, pool->capacity);
        MinutiaPair* pair = pool->pool[--pool->pooled];  // Pop from pool
        pool->pool[pool->pooled] = NULL;  // Clear reference
        return pair;  // Reuse existing pair
    } else {
        // printf("pool->pooled = %d, pool->capacity = %d\n", pool->pooled, pool->capacity);
        MinutiaPair* new_pair = calloc(1, sizeof(MinutiaPair));  // New zero-initialized
        return new_pair;
    }
}

void release_minutia_pair(MinutiaPairPool* pool, MinutiaPair* pair) {
    // printf("In release_minutia_pair: pool->pooled = %d, pool->capacity = %d\n", pool->pooled, pool->capacity);
    // printf("pair: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d, supportingEdges=%d\n",pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance, pair->supportingEdges);
    if (pool->pooled >= pool->capacity) {
        // float the pool capacity
        pool->capacity *= 2;
        // pool->capacity = pool->capacity * 3 / 2 + 1; // Grow by 1.5x
        pool->pool = realloc(pool->pool, pool->capacity * sizeof(MinutiaPair*));
    }
    // Reset the fields
    memset(pair, 0, sizeof(MinutiaPair));
    pool->pool[pool->pooled++] = pair;
    //printf("MinutiaPair released and added back to pool. New pool size: %d\n", pool->pooled);
}

void free_minutia_pair_pool(MinutiaPairPool* pool) {
    for (int i = 0; i < pool->pooled; ++i) {
        free(pool->pool[i]);
    }
    free(pool->pool);
    free(pool);
}

///// RootList /////

#define MAX_TRIED_ROOTS 70  // Replace with Parameters.MAX_TRIED_ROOTS if defined
KHASH_INIT(intset, int, int, 0, kh_int_hash_func, kh_int_hash_equal)
typedef khash_t(intset) IntSet;

typedef struct {
    MinutiaPairPool* pool;
    int count;
    MinutiaPair* pairs[MAX_TRIED_ROOTS];
    khash_t(intset)* duplicates;
} RootList;

void RootList_init(RootList** list, MinutiaPairPool* pool) {
    *list = (RootList*)malloc(sizeof(RootList));
    (*list)->pool = pool;
    (*list)->count = 0;
    memset((*list)->pairs, 0, sizeof((*list)->pairs));
    (*list)->duplicates = kh_init(intset);
}

void RootList_add(RootList* list, MinutiaPair* pair) {
    if (list->count < MAX_TRIED_ROOTS) {
        list->pairs[list->count++] = pair;
    }
}

void release_minutia_pair(MinutiaPairPool* pool, MinutiaPair* pair);  // assume implemented

void RootList_discard(RootList* list) {
    for (int i = 0; i < list->count; ++i) {
        release_minutia_pair(list->pool, list->pairs[i]);
        list->pairs[i] = NULL;
    }
    list->count = 0;
    kh_clear(intset, list->duplicates);
}

void RootList_destroy(RootList* list) {
    RootList_discard(list);
    kh_destroy(intset, list->duplicates);
}

////// RootENumerator ///////
void RootEnumerator_enumerate(Probe* probe, const SearchTemplate* candidate, RootList* roots) {
    // printf("Inside RootEnumerator_enumerate: roots->pooled = %d, roots->capacity = %d\n", roots->pool->pooled, roots->pool->capacity);
    // cminutiae are list of minutiae in the candidate template
    const SearchMinutia* cminutiae = candidate->minutiae;
    int minutia_count = candidate->minutiae_count;
    // lookups is counter ot limit number of hash lookups
    int lookups = 0;
    // counter to limit number of potential roots tried
    int tried = 0;

    // Two passes:
    // shortEdges = 0: long edges (length ≥ MIN_ROOT_EDGE_LENGTH)
    // shortEdges = 1: short edges (length < MIN_ROOT_EDGE_LENGTH)
    // Purpose: try more reliable long edges first.
    for (int shortEdges = 0; shortEdges <= 1; ++shortEdges) {
        printf("shortEdges = %d\n", shortEdges);

        // Loops generate diverse edge pairs:
        // creference: the reference minutia
        // cneighbor: the neighbor minutia
        // Not all pairs are tested
        for (int period = 1; period < minutia_count; ++period) {
            printf("period = %d\n", period);
            for (int phase = 0; phase <= period; ++phase) {
                printf("phase = %d\n", phase);
                for (int creference = phase; creference < minutia_count; creference += period + 1) {
                    printf("creference = %d\n", creference);
                    int cneighbor = (creference + period) % minutia_count;

                    EdgeShape* cedge = create_edge_shape(cminutiae[creference], cminutiae[cneighbor]);

                    // Build the edge (angle, length, etc.).
                    // Only proceed if the edge fits the current pass (long/short) using XOR:
                    // If shortEdges = 0, accept only long edges.
                    // If shortEdges = 1, accept only short edges.
                    if ((cedge->length >= MIN_ROOT_EDGE_LENGTH) ^ shortEdges) {
                        // generate hash for this edge
                        int hash = hash_edge_shape(cedge);

                        // Lookup in hash table
                        // Try to find that hash in the probe hash table (map from int hash → list of probe edges(IndexedEdgeList*)).
                        EdgeHashMap* map = probe->hash;
                        khiter_t k = kh_get(edge_map, map, hash);

                        // If hash of this exists in probe hash table, get list of all other edges in probe with same hash
                        if (k != kh_end(map)) {
                            IndexedEdgeList* matches = kh_val(map, k);

                            for (int i = 0; i < matches->size; ++i) {
                                IndexedEdge* match = &matches->data[i];
                                printf("match reference = %d, neighbor = %d\n", match->reference, match->neighbor);
                                printf("match length = %d, referenceAngle = %.2f, neighborAngle = %.2f\n",
                                       match->shape->length, match->shape->referenceAngle, match->shape->neighborAngle);

                                // Check if edge shapes match despite same hash
                                if (matching(*(match->shape), *cedge)) {
                                    // Construct a unique duplicateKey from the current probe and candidate indices.
                                    // Use roots->duplicates (a khash_t(intset)) to avoid repeating the same pair.
                                    int duplicateKey = (match->reference << 16) | creference;

                                    khash_t(intset)* set = roots->duplicates;
                                    if (!set) {
                                        fprintf(stderr, "roots->duplicates is NULL!\n");
                                        exit(1);
                                    }

                                    int ret;
                                    khiter_t k = kh_put(intset, set, duplicateKey, &ret);
                                    if (ret < 0) { // insertion failed (likely OOM)
                                        fprintf(stderr, "kh_put failed (OOM?)\n");
                                        exit(1);
                                    }

                                    if (ret > 0) { // newly added -> equivalent to roots.duplicates.add(...) == true
                                        printf("duplicateKey = %d\n", duplicateKey);

                                        MinutiaPair* pair = allocate_minutia_pair(roots->pool);
                                        pair->probe = match->reference;
                                        pair->candidate = creference;
                                        RootList_add(roots, pair);
                                    }

                                    // Stop if too many roots have been tried
                                    ++tried;
                                    if (tried >= MAX_TRIED_ROOTS)
                                        return;
                                    // printf("duplicateKey = %d\n", duplicateKey);

                                    // khash_t(intset)* set = roots->duplicates;

                                    // if (!set) {
                                    //     printf("roots->duplicates is NULL!\n");
                                    //     exit(1);
                                    // }

                                    // khiter_t k = kh_get(intset, set, duplicateKey);
                                    // if (k == kh_end(set)) {
                                    //     int ret;
                                    //     // Insert the newly unique duplicateKey into the set
                                    //     k = kh_put(intset, set, duplicateKey, &ret);
                                    //     if (ret == -1) {
                                    //         printf("kh_put failed (OOM?)\n");
                                    //         exit(1);
                                    //     }

                                    //     // kh_val(set, k) = 1; // mark key as present

                                    //     // Create a new MinutiaPair and add it to the roots list
                                    //     MinutiaPair* pair = allocate_minutia_pair(roots->pool);
                                    //     pair->probe = match->reference;
                                    //     pair->candidate = creference;
                                    //     RootList_add(roots, pair);
                                    // }

                                    // // Stop if too many roots have been tried
                                    // ++tried;
                                    // if (tried >= MAX_TRIED_ROOTS)
                                    //     return;
                                }
                            }
                        }

                        // Stop if too many lookups have been performed
                        ++lookups;
                        if (lookups >= MAX_ROOT_EDGE_LOOKUPS)
                            return;
                    }
                }
            }
        }
    }
}

///// PairingGraph //////

typedef struct {
    MinutiaPairPool* pool;
    int count;

    MinutiaPair** tree; int tree_length;
    MinutiaPair** byProbe; int byProbe_length;
    MinutiaPair** byCandidate; int byCandidate_length;

    MinutiaPair** support;
    int support_size;
    int support_capacity;

    bool support_enabled;
} PairingGraph;

#define INITIAL_CAPACITY 1

PairingGraph* create_pairing_graph(MinutiaPairPool* pool) {
    PairingGraph* graph = calloc(1, sizeof(PairingGraph));
    graph->pool = pool;
    graph->tree = calloc(INITIAL_CAPACITY, sizeof(MinutiaPair*));
    graph->byProbe = calloc(INITIAL_CAPACITY, sizeof(MinutiaPair*));
    graph->byCandidate = calloc(INITIAL_CAPACITY, sizeof(MinutiaPair*));
    graph->support = NULL;
    graph->support_size = 0;
    graph->support_capacity = 0;
    graph->support_enabled = false;
    graph->tree_length = 1;
    graph->byCandidate_length = 1;
    graph->byProbe_length = 1;

    for(int i=0;i<graph->byProbe_length;i++)
    {
        graph->byProbe[i] = NULL;
    }

    for(int i=0;i<graph->byCandidate_length;i++)
    {
        graph->byCandidate[i] = NULL;
    }
    
    return graph;
}

void reserve_probe(PairingGraph* graph, const Probe* probe) {
    int capacity = probe->template.minutiae_count;
    if (capacity > graph->tree_length) {
        graph->tree = realloc(graph->tree, capacity * sizeof(MinutiaPair*));
        graph->byProbe = realloc(graph->byProbe, capacity * sizeof(MinutiaPair*));
        for(int i=0;i<capacity;i++)
        {
            graph->byProbe[i] = NULL; // Initialize to NULL
        }
        graph->tree_length = capacity;
        graph->byProbe_length = capacity;
    }
}

void reserve_candidate(PairingGraph* graph, const SearchTemplate* candidate) {
    int capacity = candidate->minutiae_count;
    if (capacity > graph->byCandidate_length) {
        graph->byCandidate = realloc(graph->byCandidate, capacity * sizeof(MinutiaPair*));
        for(int i=0;i<capacity;i++)
        {
            graph->byCandidate[i] = NULL; // Initialize to NULL
        }
        graph->byCandidate_length = capacity;
    }
}

void add_pair(PairingGraph* graph, MinutiaPair* pair) {
    printf("In add_pair - adding edge: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
           pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);
    graph->tree[graph->count] = pair;
    graph->byProbe[pair->probe] = pair;
    graph->byCandidate[pair->candidate] = pair;
    graph->count++;
}

void support_pair(PairingGraph* graph, MinutiaPair* pair) {
    printf("In support - supporting edge: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
           pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);
    printf("supportEnabled = %d\n", graph->support_enabled);
    MinutiaPair* existing = graph->byProbe[pair->probe];
    if (existing && existing->candidate == pair->candidate) {
        existing->supportingEdges++;
        graph->byProbe[pair->probeRef]->supportingEdges++;

        if (graph->support_enabled) {
            if (graph->support_size == graph->support_capacity) {
                graph->support_capacity = graph->support_capacity > 0 ? graph->support_capacity * 2 : 8;
                graph->support = realloc(graph->support, graph->support_capacity * sizeof(MinutiaPair*));
            }
            graph->support[graph->support_size++] = pair;
        } else {
            release_minutia_pair(graph->pool, pair);
        }
    } else {
        release_minutia_pair(graph->pool, pair);
    }
}

void clear_pairing_graph(PairingGraph* graph) {
    for (int i = 0; i < graph->count; ++i) {
        MinutiaPair* pair = graph->tree[i];
        graph->byProbe[pair->probe] = NULL;
        graph->byCandidate[pair->candidate] = NULL;

        if (i > 0)
            release_minutia_pair(graph->pool, pair);
        else
            pair->supportingEdges = 0;

        graph->tree[i] = NULL;
    }

    graph->count = 0;
    graph->byCandidate_length=0;
    graph->byProbe_length=0;
    graph->tree_length = 0;

    if (graph->support_enabled) {
        for (int i = 0; i < graph->support_size; ++i) {
            release_minutia_pair(graph->pool, graph->support[i]);
        }
        graph->support_size = 0;
    }
}

void free_pairing_graph(PairingGraph* graph) {
    free(graph->tree);
    free(graph->byProbe);
    free(graph->byCandidate);
    free(graph->support);
    free(graph);
}

//////////// 


///////// ScoringData //////////

#define MINUTIA_SCORE 0.032
#define MINUTIA_FRACTION_SCORE 8.98
#define MIN_SUPPORTING_EDGES 1
#define SUPPORTED_MINUTIA_SCORE 0.193
#define EDGE_SCORE 0.265
#define MINUTIA_TYPE_SCORE 0.629
#define DISTANCE_ERROR_FLATNESS 0.69
#define ANGLE_ERROR_FLATNESS 0.27
#define DISTANCE_ACCURACY_SCORE 9.9
#define ANGLE_ACCURACY_SCORE 2.79

#define THRESHOLD_FMR_MAX  8.48
#define THRESHOLD_FMR_2 11.12
#define THRESHOLD_FMR_10 14.15
#define THRESHOLD_FMR_100 18.22
#define THRESHOLD_FMR_1000 22.39
#define THRESHOLD_FMR_10_000 27.24
#define THRESHOLD_FMR_100_000 32.01


typedef struct {
	int minutiaCount;
	float minutiaScore;
	float minutiaFractionInProbe;
	float minutiaFractionInCandidate;
	float minutiaFraction;
	float minutiaFractionScore;
	int supportingEdgeSum;
	int edgeCount;
	float edgeScore;
	int supportedMinutiaCount;
	float supportedMinutiaScore;
	int minutiaTypeHits;
	float minutiaTypeScore;
	int distanceErrorSum;
	int distanceAccuracySum;
	float distanceAccuracyScore;
	float angleErrorSum;
	float angleAccuracySum;
	float angleAccuracyScore;
	float totalScore;
	float shapedScore;
} ScoringData;

float scoring_interpolate(float raw, float min, float max, float start, float length) {
    return (raw - min) / (max - min) * length + start;
}

float shape(float raw) {
    if (raw < THRESHOLD_FMR_MAX)
        return 0;
    if (raw < THRESHOLD_FMR_2)
        return scoring_interpolate(raw, THRESHOLD_FMR_MAX, THRESHOLD_FMR_2, 0, 3);
    if (raw < THRESHOLD_FMR_10)
        return scoring_interpolate(raw, THRESHOLD_FMR_2, THRESHOLD_FMR_10, 3, 7);
    if (raw < THRESHOLD_FMR_100)
        return scoring_interpolate(raw, THRESHOLD_FMR_10, THRESHOLD_FMR_100, 10, 10);
    if (raw < THRESHOLD_FMR_1000)
        return scoring_interpolate(raw, THRESHOLD_FMR_100, THRESHOLD_FMR_1000, 20, 10);
    if (raw < THRESHOLD_FMR_10_000)
        return scoring_interpolate(raw, THRESHOLD_FMR_1000, THRESHOLD_FMR_10_000, 30, 10);
    if (raw < THRESHOLD_FMR_100_000)
        return scoring_interpolate(raw, THRESHOLD_FMR_10_000, THRESHOLD_FMR_100_000, 40, 10);
    return (raw - THRESHOLD_FMR_100_000) / (THRESHOLD_FMR_100_000 - THRESHOLD_FMR_100) * 30 + 50;
}

int find_max(int a, int b) {
    return (a > b) ? a : b;
}

float find_max_f(float a, float b) {
    return (a > b) ? a : b;
}

void compute_score(const SearchTemplate* probe, const SearchTemplate* candidate, const PairingGraph* pairing, ScoringData* score) {
    const SearchMinutia* pminutiae = probe->minutiae;
    const SearchMinutia* cminutiae = candidate->minutiae;

    score->minutiaCount = pairing->count;
    score->minutiaScore = MINUTIA_SCORE * score->minutiaCount;
    score->minutiaFractionInProbe = (float)pairing->count / probe->minutiae_count;
    score->minutiaFractionInCandidate = (float)pairing->count / candidate->minutiae_count;
    score->minutiaFraction = 0.5 * (score->minutiaFractionInProbe + score->minutiaFractionInCandidate);
    score->minutiaFractionScore = MINUTIA_FRACTION_SCORE * score->minutiaFraction;
    score->supportingEdgeSum = 0;
    score->supportedMinutiaCount = 0;
    score->minutiaTypeHits = 0;

    for (int i = 0; i < pairing->count; ++i) {
        MinutiaPair* pair = pairing->tree[i];
        score->supportingEdgeSum += pair->supportingEdges;
        if (pair->supportingEdges >= MIN_SUPPORTING_EDGES)
            ++score->supportedMinutiaCount;
        if (pminutiae[pair->probe].type == cminutiae[pair->candidate].type)
            ++score->minutiaTypeHits;
    }

    score->edgeCount = pairing->count + score->supportingEdgeSum;
    score->edgeScore = EDGE_SCORE * score->edgeCount;
    score->supportedMinutiaScore = SUPPORTED_MINUTIA_SCORE * score->supportedMinutiaCount;
    score->minutiaTypeScore = MINUTIA_TYPE_SCORE * score->minutiaTypeHits;

    int innerDistanceRadius = (int)java_round(DISTANCE_ERROR_FLATNESS * MAX_DISTANCE_ERROR);
    float innerAngleRadius = (float)(ANGLE_ERROR_FLATNESS * MAX_ANGLE_ERROR);

    score->distanceErrorSum = 0;
    score->angleErrorSum = 0;

    for (int i = 1; i < pairing->count; ++i) {
        MinutiaPair* pair = pairing->tree[i];
        EdgeShape* probeEdge = create_edge_shape(pminutiae[pair->probeRef], pminutiae[pair->probe]);
        EdgeShape* candidateEdge = create_edge_shape(cminutiae[pair->candidateRef], cminutiae[pair->candidate]);

        printf("innerAngleRadius: %.3f\n",innerAngleRadius);
        printf("probeEdge.referenceAngle: %.3f, candidateEdge.referenceAngle: %.3f\n",
               probeEdge->referenceAngle, candidateEdge->referenceAngle);
        printf("probeEdge.neighborAngle: %.3f, candidateEdge.neighborAngle: %.3f\n",
               probeEdge->neighborAngle, candidateEdge->neighborAngle);

        score->distanceErrorSum += find_max(innerDistanceRadius, abs(probeEdge->length - candidateEdge->length));
        
        float f1 = float_angle_distance(probeEdge->referenceAngle, candidateEdge->referenceAngle);
        score->angleErrorSum += find_max_f(innerAngleRadius, f1);
        printf("First angleErrorSum: %.3f\n", score->angleErrorSum);
        float f2 = float_angle_distance(probeEdge->neighborAngle, candidateEdge->neighborAngle);
        score->angleErrorSum += find_max_f(innerAngleRadius, f2);
        printf("Second angleErrorSum: %.3f\n", score->angleErrorSum);
    }

    int distanceErrorPotential = MAX_DISTANCE_ERROR * find_max(0, pairing->count - 1);
    score->distanceAccuracySum = distanceErrorPotential - score->distanceErrorSum;
    score->distanceAccuracyScore = DISTANCE_ACCURACY_SCORE * (distanceErrorPotential > 0 ? (float)score->distanceAccuracySum / distanceErrorPotential : 0);

    float angleErrorPotential = MAX_ANGLE_ERROR * find_max(0, pairing->count - 1) * 2;
    score->angleAccuracySum = angleErrorPotential - score->angleErrorSum;
    score->angleAccuracyScore = ANGLE_ACCURACY_SCORE * (angleErrorPotential > 0 ? score->angleAccuracySum / angleErrorPotential : 0);

    score->totalScore = score->minutiaScore +
                        score->minutiaFractionScore +
                        score->supportedMinutiaScore +
                        score->edgeScore +
                        score->minutiaTypeScore +
                        score->distanceAccuracyScore +
                        score->angleAccuracyScore;

    score->shapedScore = shape(score->totalScore);

    printf("score->minutiaCount = %d\n", score->minutiaCount);
    printf("score->minutiaScore = %.3f\n", score->minutiaScore);
    printf("score->minutiaFractionInProbe = %.3f\n", score->minutiaFractionInProbe);
    printf("score->minutiaFractionInCandidate = %.3f\n", score->minutiaFractionInCandidate);
    printf("score->minutiaFraction = %.3f\n", score->minutiaFraction);
    printf("score->minutiaFractionScore = %.3f\n", score->minutiaFractionScore);
    printf("score->supportingEdgeSum = %d\n", score->supportingEdgeSum);
    printf("score->supportedMinutiaCount = %d\n", score->supportedMinutiaCount);
    printf("score->supportedMinutiaScore = %.3f\n", score->supportedMinutiaScore);
    printf("score->edgeCount = %d\n", score->edgeCount);
    printf("score->edgeScore = %.3f\n", score->edgeScore);
    printf("score->minutiaTypeHits = %d\n", score->minutiaTypeHits);
    printf("score->minutiaTypeScore = %.3f\n", score->minutiaTypeScore);
    printf("score->distanceErrorSum = %d\n", score->distanceErrorSum);
    printf("score->angleErrorSum = %.3f\n", score->angleErrorSum);
    printf("score->distanceAccuracySum = %d\n", score->distanceAccuracySum);
    printf("score->distanceAccuracyScore = %.3f\n", score->distanceAccuracyScore);
    printf("score->angleAccuracySum = %.3f\n", score->angleAccuracySum);
    printf("score->angleAccuracyScore = %.3f\n", score->angleAccuracyScore);
    printf("score->totalScore = %.3f\n", score->totalScore);
    printf("score->shapedScore = %.3f\n", score->shapedScore);

}

///// PriorityQueue /////

typedef struct {
    MinutiaPair** data;
    int size;
    int capacity;
} MinutiaPairQueue;

void swap(MinutiaPair** a, MinutiaPair** b) {
    MinutiaPair* tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify_up(MinutiaPairQueue* q, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (q->data[parent]->distance <= q->data[index]->distance)
            break;
        swap(&q->data[parent], &q->data[index]);
        index = parent;
    }
}

void heapify_down(MinutiaPairQueue* q, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < q->size && q->data[left]->distance < q->data[smallest]->distance)
            smallest = left;
        if (right < q->size && q->data[right]->distance < q->data[smallest]->distance)
            smallest = right;

        if (smallest == index)
            break;

        swap(&q->data[index], &q->data[smallest]);
        index = smallest;
    }
}

MinutiaPairQueue* queue_create(int capacity) {
    MinutiaPairQueue* q = malloc(sizeof(MinutiaPairQueue));
    q->data = malloc(capacity * sizeof(MinutiaPair*));
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void queue_push(MinutiaPairQueue* q, MinutiaPair* pair) {
    if (q->size >= q->capacity) {
        q->capacity *= 2;
        // q->capacity = q->capacity * 3 / 2 + 1; // Grow by 1.5x
        q->data = realloc(q->data, q->capacity * sizeof(MinutiaPair*));
    }
    q->data[q->size] = pair;
    heapify_up(q, q->size);
    q->size++;
}

MinutiaPair* queue_pop(MinutiaPairQueue* q) {
    if (q->size == 0)
        return NULL;

    MinutiaPair* top = q->data[0];
    q->data[0] = q->data[--q->size];
    heapify_down(q, 0);
    return top;
}

int queue_empty(MinutiaPairQueue* q) {
    return q->size == 0;
}

// void queue_free(MinutiaPairQueue* q) {
//     free(q->data);
//     free(q);
// }

///// MatcherThread ////////

typedef struct MatcherThread {
    MinutiaPairPool* pool;
    RootList* roots;
    PairingGraph* pairing;
    MinutiaPairQueue* queue; // Min-heap for MinutiaPair*
    ScoringData* score;
} MatcherThread;

// Singleton for now, not real thread-local yet


MatcherThread* matcher_thread_current(MatcherThread* thread_instance) {
    // if (!thread_instance) {
        thread_instance->pool = create_minutia_pair_pool(); 
        RootList_init(&thread_instance->roots, thread_instance->pool);

        thread_instance->pairing = create_pairing_graph(thread_instance->pool);

        thread_instance->queue = queue_create(16); // This is your MinutiaPairQueue*
        thread_instance->score = (ScoringData*)malloc(sizeof(ScoringData));
    // }
    return thread_instance;
}

void matcher_thread_kill(MatcherThread* thread_instance) {
    if (!thread_instance)
        return;

    // Free queue
    if (thread_instance->queue) {
        // If queue holds dynamically allocated MinutiaPair*, free them
        for (int i = 0; i < thread_instance->queue->size; ++i) {
            free(thread_instance->queue->data[i]);
        }
        free(thread_instance->queue->data);
        free(thread_instance->queue);
    }

    // Free pairing graph
    if (thread_instance->pairing) {
        free(thread_instance->pairing->tree); // assuming this is malloc'd
        free(thread_instance->pairing->byProbe); // assuming this is malloc'd
        free(thread_instance->pairing->byCandidate); // assuming this is malloc'd
        free(thread_instance->pairing);
    }

    // Free minutia pair po
    // Free pool
    if (thread_instance->pool) {
        free(thread_instance->pool);
    }

    // Free score
    free(thread_instance->score);

    // Finally free the thread object
    free(thread_instance);
    thread_instance = NULL;
}

//////// EdgeSpider //////////
// Match pairs

#define COMPLEMENTARY_MAX_ANGLE_ERROR complementary(MAX_ANGLE_ERROR)

MinutiaPair** match_pairs(NeighborEdge* pstar, int pcount, NeighborEdge* cstar, int ccount, MinutiaPairPool* pool, int* out_count) {
    MinutiaPair** results = malloc(sizeof(MinutiaPair*) * (pcount * ccount));
    int result_count = 0;

    int start = 0;
    int end = 0;
    for (int cindex = 0; cindex < ccount; ++cindex) {
        NeighborEdge cedge = cstar[cindex];
        printf("start: %d, end: %d, cedge.length: %d, cedge.referenceAngle: %.2f\n",
               start, end, cedge.shape->length, cedge.shape->referenceAngle);

        while (start < pcount && pstar[start].shape->length < cedge.shape->length - MAX_DISTANCE_ERROR)
            ++start;
        if (end < start)
            end = start;
        
        printf("start: %d, end: %d\n", start, end);
        printf("pstar: \n");
        for (int i = start; i < pcount; ++i) {
            printf("pstar[%d]: length = %d, referenceAngle = %.2f, neighborAngle = %.2f\n",
                   i, pstar[i].shape->length,pstar[i].shape->referenceAngle, pstar[i].shape->neighborAngle);
        
        }

        while (end < pcount && pstar[end].shape->length <= cedge.shape->length + MAX_DISTANCE_ERROR)
            ++end;

        for (int pindex = start; pindex < end; ++pindex) {
            NeighborEdge pedge = pstar[pindex];
            float rdiff = float_angle_difference(pedge.shape->referenceAngle, cedge.shape->referenceAngle);

            if (rdiff <= MAX_ANGLE_ERROR || rdiff >= COMPLEMENTARY_MAX_ANGLE_ERROR) {
                float ndiff = float_angle_difference(pedge.shape->neighborAngle, cedge.shape->neighborAngle);

                if (ndiff <= MAX_ANGLE_ERROR || ndiff >= COMPLEMENTARY_MAX_ANGLE_ERROR) {
                    MinutiaPair* pair = allocate_minutia_pair(pool);
                    printf("Pair returned: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
                           pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);
                    pair->probe = pedge.neighbor;
                    pair->candidate = cedge.neighbor;
                    pair->distance = cedge.shape->length;
                    results[result_count++] = pair;
                    printf("Adding to results: probe=%d, candidate=%d, distance=%d\n",
                           pair->probe, pair->candidate, pair->distance);
                }
            }
        }
    }

    printf("fin results: \n");
    for (int i = 0; i < result_count; ++i) {
        MinutiaPair* pair = results[i];
        printf("results[%d]: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
               i, pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);
    }

    *out_count = result_count;
    return results;
}

void collect_edges(NeighborEdge** pedges, NeighborEdge** cedges, int* pedges_count, int* cedges_count, PairingGraph* pairing, MinutiaPairQueue* queue) {
    MinutiaPair* reference = pairing->tree[pairing->count - 1];
    NeighborEdge* pstar = pedges[reference->probe];
    NeighborEdge* cstar = cedges[reference->candidate];
    // pstar.length==pcount, cstar.length=ccount
    int pcount = pedges_count[reference->probe];
    int ccount = cedges_count[reference->candidate];

    int match_count = 0;
    MinutiaPair** matches = match_pairs(pstar, pcount, cstar, ccount, pairing->pool, &match_count);
    // printf("Finnnn matches: \n"); // 
    // for(int i = 0; i < match_count; ++i) {
    //     MinutiaPair* pair = matches[i];
    //     printf("matches[%d]: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
    //            i, pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);
    // }

    for (int i = 0; i < match_count; ++i) {
        MinutiaPair* pair = matches[i];
        pair->probeRef = reference->probe;
        pair->candidateRef = reference->candidate;
        printf("---------------------- Adding pair: probe=%d, candidate=%d, probeRef=%d, candidateRef=%d, distance=%d\n",
               pair->probe, pair->candidate, pair->probeRef, pair->candidateRef, pair->distance);

        if (pairing->byCandidate[pair->candidate] == NULL && pairing->byProbe[pair->probe] == NULL) {
            printf("Adding to queue: \n");
            queue_push(queue, pair);
            printf("Queue size: %d\n",queue->size);
        } else {
            support_pair(pairing, pair);
        }
    }
    free(matches);
}

MinutiaPair* peek_pair(MinutiaPairQueue* queue) {
    if (queue->size == 0) {
        return NULL;
    }
    return queue->data[0]; // Root of min-heap
}

void skip_paired(PairingGraph* pairing, MinutiaPairQueue* queue) {
    while (queue_empty(queue)== false) {
        MinutiaPair* top = peek_pair(queue);
        if (pairing->byCandidate[top->candidate] == NULL && pairing->byProbe[top->probe] == NULL)
            break;
        support_pair(pairing, queue_pop(queue));
    }
}

void edge_spider_crawl(NeighborEdge** pedges, NeighborEdge** cedges, int* pedges_count, int* cedges_count, PairingGraph* pairing, MinutiaPair* root, MinutiaPairQueue* queue) {
    queue_push(queue, root);
    do {
        MinutiaPair* pair = queue_pop(queue);
        printf("probe=%d, candidate=%d, probeRef=%d\n", pair->probe, pair->candidate, pair->probeRef);
        add_pair(pairing, pair);
        collect_edges(pedges, cedges, pedges_count, cedges_count, pairing, queue);
        skip_paired(pairing, queue);
    } while (queue_empty(queue) == false);
}

////// MatcherENgine ///////

float matcher_engine_match(Probe* probe, SearchTemplate* candidate) {
    MatcherThread* thread = (MatcherThread*)malloc(sizeof(MatcherThread));
    matcher_thread_current(thread);
    // printf("At start, thread->pool->pooled = %d, thread->pool->capacity = %d\n", thread->pool->pooled, thread->pool->capacity);

    // reserve memory for probe and candidate minutiae edges
    reserve_probe(thread->pairing, probe); 
    reserve_candidate(thread->pairing, candidate);

    // set supportEnabled if transparency accepts pairing
    thread->pairing->support_enabled = false;

    ///// Creating counts ////////
    NeighborEdge** probe_edges = probe->template.edges;
    NeighborEdge** candidate_edges = candidate->edges;

    int* probe_counts = probe->template.edge_counts;
    int* candidate_counts = candidate->edge_counts;

    // int* probe_counts = malloc(probe->template.minutiae_count * sizeof(int));
    // int* candidate_counts = malloc(candidate->minutiae_count * sizeof(int));

    // for (int i = 0; i < probe->template.minutiae_count; ++i) {
    //     probe_counts[i] = probe_edges[i]->shape->length;
    // }
    // for (int i = 0; i < candidate->minutiae_count; ++i) {
    //     candidate_counts[i] = candidate_edges[i]->shape->length; // Updated to use shape->length
    // }
    //////////

    // enumerate root pairs between probe and candidate
    RootEnumerator_enumerate(probe, candidate, thread->roots);
    printf("Root enumeration completed\n");

    float high = 0.0;
    int best = -1;

    // void edge_spider_crawl(NeighborEdge** pedges, NeighborEdge** cedges, int* pedges_count, int* cedges_count, PairingGraph* pairing, MinutiaPair* root, MinutiaPairQueue* queue) {
    for (int i = 0; i < thread->roots->count; ++i) {
        edge_spider_crawl(
            probe->template.edges,
            candidate->edges,
            probe_counts,
            candidate_counts,
            thread->pairing,
            thread->roots->pairs[i],
            thread->queue
        );

        compute_score(&probe->template, candidate, thread->pairing, thread->score);

        float partial = thread->score->shapedScore;

        if (best < 0 || partial > high) {
            high = partial;
            best = i;
        }

        clear_pairing_graph(thread->pairing);
    }

    if (best >= 0) {
        thread->pairing->support_enabled = false;

        edge_spider_crawl(
            probe->template.edges,
            candidate->edges,
            probe_counts,
            candidate_counts,
            thread->pairing,
            thread->roots->pairs[best],
            thread->queue
        );

        compute_score(&probe->template, candidate, thread->pairing, thread->score);

        clear_pairing_graph(thread->pairing);
    }

    RootList_discard(thread->roots);

    return high;
}


//////////////////

DoubleMatrix read_decoded_bytes(char* filepath)
{
    DoubleMatrix d;

    FILE* file = fopen(filepath, "r");
    if (!file) {
        perror("fopen failed");
        return d;
    }

    float* values = malloc(MAX_LINES * sizeof(float));
    if (!values) {
        perror("malloc failed");
        fclose(file);
        return d;
    }

    int count = 0;
    while (fscanf(file, "%lf", &values[count]) == 1) {
        count++;
        if (count >= MAX_LINES) {
            fprintf(stderr, "Exceeded max lines\n");
            break;
        }
    }

    fclose(file);

    // Example: print first few
    for (int i = 0; i < count; ++i) {
        printf("Value[%d] = %f\n", i, values[i]);
    }

    d.width= (int)sqrt(count);
    d.height=(int)sqrt(count);
    d.data = (float*)malloc(d.width * d.height * sizeof(float));
    
    for(int i=0;i<d.width;i++)
    {
        for(int j=0;j<d.height;j++)
        {
            d.data[i*d.width+j]=values[i*d.width+j];
        }
    }

    free(values);


    return d;
}
////////////////////////

#define MAX_FILES 1000

#define PATHS_MAX 1000

int ends_with_png(const char *filename) {
    size_t len = strlen(filename);
    return len >= 4 && strcmp(filename + len - 4, ".png") == 0;
}

int is_regular_file(const char *path) {
    struct stat st;
    return stat(path, &st) == 0 && S_ISREG(st.st_mode);
}

int compare_filenames(const void *a, const void *b) {
    const char **fa = (const char **)a;
    const char **fb = (const char **)b;
    return strcmp(*fa, *fb); // Lexicographical order
}

int compare_strings(const void *a, const void *b) {
    const char **sa = (const char **)a;
    const char **sb = (const char **)b;
    return strcmp(*sa, *sb);
}

// void strip_png_extension(char *filename) {
//     size_t len = strlen(filename);
//     if (len >= 4 && strcmp(filename + len - 4, ".png") == 0) {
//         filename[len - 4] = '\0'; // Truncate the string
//     }
// }

#define MAX_CLASSES 100
#define MAX_CLASS_NAME 100

typedef struct {
    char name[MAX_CLASS_NAME];
    float score;
} ClassScore;

KHASH_MAP_INIT_STR(str_dbl, float);

void put_score(khash_t(str_dbl)* map, const char* key, float value) {
    int ret;
    khiter_t k = kh_put(str_dbl, map, key, &ret);  // key is copied
    kh_value(map, k) = value;
}

float* get_score(khash_t(str_dbl)* map, const char* key) {
    khiter_t k = kh_get(str_dbl, map, key);
    if (k == kh_end(map)) return NULL;
    return &kh_value(map, k);
}

// Returns pointer to last component of path
const char* basename(const char* path) {
    const char* base = strrchr(path, '/');
    return base ? base + 1 : path;
}

char* get_class_name(char* path_copy) {
    // Get the filename (e.g., "pixelsKshitjleftfinger_8.png")
    char* filename = basename(path_copy);

    // Duplicate to a temporary buffer so we can safely modify
    char temp[256];
    strncpy(temp, filename, sizeof(temp));
    temp[sizeof(temp) - 1] = '\0';

    // Remove the file extension
    char* dot = strrchr(temp, '.');
    if (dot) *dot = '\0';  // Now temp = "pixelsKshitjleftfinger_8"

    // Find the last underscore and shift the digits left
    char* underscore = strrchr(temp, '_');
    if (underscore && *(underscore + 1)) {
        // Move the digits after '_' over the underscore
        memmove(underscore, underscore + 1, strlen(underscore + 1) + 1); // include null terminator
    }

    // Allocate and return a copy of the final result
    return strdup(temp);  // Caller must free
}

typedef struct {
    char* key;
    float value;
} Entry;

int compare_entries_desc(const void* a, const void* b) {
    float diff = ((Entry*)b)->value - ((Entry*)a)->value;
    return (diff > 0) - (diff < 0);
}

void normalize_and_rank(khash_t(str_dbl)* classScores, khash_t(str_dbl)* countClass,
                        const char* queryClass,
                        float threshold, int* matchCount, int* passCount, int* false_positive_number) {
    
    // Normalize each class score by its count
    for (khiter_t k = kh_begin(classScores); k != kh_end(classScores); ++k) {
        if (kh_exist(classScores, k)) {
            const char* className = kh_key(classScores, k);
            float score = kh_value(classScores, k);

            khiter_t c = kh_get(str_dbl, countClass, className);
            float count = (c != kh_end(countClass)) ? kh_value(countClass, c) : 1.0;

            kh_value(classScores, k) = score / count;
        }
    }

    // Create a sortable list of entries
    int numEntries = kh_size(classScores);
    Entry* entries = malloc(sizeof(Entry) * numEntries);
    int index = 0;

    for (khiter_t k = kh_begin(classScores); k != kh_end(classScores); ++k) {
        if (kh_exist(classScores, k)) {
            entries[index].key = kh_key(classScores, k);
            entries[index].value = kh_value(classScores, k);
            index++;
        }
    }

    // Sort by score descending
    qsort(entries, index, sizeof(Entry), compare_entries_desc);

    // Print sorted entries
    for (int i = 0; i < index; ++i) {
        printf("Class: %s, Score: %.2f\n", entries[i].key, entries[i].value);
    }

    // Top match handling
    if (index > 0) {
        if (entries[0].value > threshold && strcmp(entries[0].key, queryClass) == 0) {
            (*matchCount)++;
        } else if (entries[0].value < threshold) {
            (*passCount)++;
        } else if (entries[0].value > threshold && strcmp(entries[0].key, queryClass) != 0) {
            (*false_positive_number)++;
        }

        printf("Query: %-35s  TopMatch: %-35s  Score: %.2f  MatchCount: %d  PassCount: %d  False_positive_number: %d\n",
            queryClass,
            entries[0].key,
            entries[0].value,
            *matchCount,
            *passCount,
            *false_positive_number);
    }

    printf("--------------------------------------------------\n");

    free(entries);
}

void print_stats(int matchCount, int passCount, int total) {
    float accuracy = (float) matchCount / total;
    float passRate = (float) passCount / total;

    printf("\n==============================\n");
    printf("Total images           : %d\n", total);
    printf("Correct matches        : %d\n", matchCount);
    printf("No-match (score < 40)  : %d\n", passCount);
    printf("Accuracy               : %.2f%%\n", accuracy * 100);
    printf("Pass (low-score) rate  : %.2f%%\n", passRate * 100);
}
 #include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

static void hexdump_tail(const char* s, size_t n) {
    fprintf(stderr, "path tail hex: ");
    size_t start = n > 16 ? n - 16 : 0;
    for (size_t i = start; i < n; i++) fprintf(stderr, "%02X ", (unsigned char)s[i]);
    fprintf(stderr, " | len=%zu\n", n);
}

// Pass in the errno you captured right after the failing call.
static void diagnose_path_issue(const char* where, const char* path, int saved_errno) {
    size_t len = strlen(path);
    fprintf(stderr, "[%s] path='%s'\n", where, path);
    hexdump_tail(path, len);

    fprintf(stderr, "errno(at open)=%d (%s)\n", saved_errno, strerror(saved_errno));

    struct stat st;
    if (stat(path, &st) != 0) {
        fprintf(stderr, "stat: %s (errno=%d)\n", strerror(errno), errno);
        return;
    }
    fprintf(stderr, "stat: ok size=%lld mode=%o\n", (long long)st.st_size, st.st_mode & 0777);

    if (access(path, R_OK) != 0)
        fprintf(stderr, "access(R_OK): %s (errno=%d)\n", strerror(errno), errno);
    else
        fprintf(stderr, "access(R_OK): ok\n");

    char canon[PATHS_MAX];
    if (realpath(path, canon))
        fprintf(stderr, "realpath: %s\n", canon);
    else
        fprintf(stderr, "realpath: %s (errno=%d)\n", strerror(errno), errno);
}

// Extract representation prefix: everything before the LAST '_' (ignores extension).
// e.g., "pixelsKshitijleftthumb_2.png" -> "pixelsKshitijleftthumb"
static void get_representation(const char *filename, char *out, size_t outsz) {
    if (!filename || !out || outsz == 0) return;

    // Make a writable copy
    char tmp[1024];
    strncpy(tmp, filename, sizeof(tmp) - 1);
    tmp[sizeof(tmp) - 1] = '\0';

    // Strip extension if present (find last '.')
    char *dot = strrchr(tmp, '.');
    if (dot) *dot = '\0';

    // Find last underscore
    char *us = strrchr(tmp, '_');
    if (!us) {
        // No underscore — treat the whole (no-ext) string as representation
        strncpy(out, tmp, outsz - 1);
        out[outsz - 1] = '\0';
        return;
    }

    // Everything before the underscore is the representation
    *us = '\0';
    strncpy(out, tmp, outsz - 1);
    out[outsz - 1] = '\0';
}

// Accumulator entry for a candidate representation
typedef struct {
    char rep[MAX_REP_LEN];
    double sumScore;
    int count;
} RepScore;

// Find index of representation in array; returns -1 if not found
static int find_rep_index(RepScore *arr, int count, const char *rep) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(arr[i].rep, rep) == 0) return i;
    }
    return -1;
}

// Extracts filename ending in .png from input string
static void get_filename_from_log(const char *input, char *out, size_t outsz) {
    const char *start = strrchr(input, '/');
    if (!start) start = input;  // No slash found, use full string
    else start++;               // Move past the '/'

    const char *end = strstr(start, ".png");
    if (!end) {
        strncpy(out, start, outsz - 1);
        out[outsz - 1] = '\0';
        return;
    }

    size_t len = (size_t)(end - start) + 4; // ".png" is 4 chars
    if (len >= outsz) len = outsz - 1;

    strncpy(out, start, len);
    out[len] = '\0';
}

float query_decoded_data[140*140];

int main()
{
    size_t size;
    FILE* file_o = fopen("output.txt", "w"); 

    // unsigned char* data = read_all_bytes("/home/kshitij/SecurSi/read-write-data-from-uart-by-client/pixels_dir/pixelsKshitijleftindexfinger_0.png", &size);

    // if (data != NULL) {
    //     // Use the bytes...
    //     free(data);
    // }

    // for(size_t i=0;i<size;i++)
    // {
    //     printf("%02x ",data[i]);
    //     if((i+1)%16==0)
    //     {
    //         printf("\n");
    //     }
    // }

    // DoubleMatrix decoded  = decode_image(data, size); 
    // printf("decoded.width: %d\n", decoded.width);
    // printf("decoded.height: %d\n", decoded.height);

    //////////////////////////////////////////////////

    // const char *dir_path = "/home/kshitij/SecurSi/read-write-data-from-uart-by-client/test_pixels_dir";
    const char *dir_path = "/home/kshitij/SecurSi/read-write-data-from-uart-by-client/check_encode_decode_png";
    // const char* dir_path = "/home/kshitij/SecurSi/read-write-data-from-uart-by-client/pixels_dir";
    // const char *dir_path = "/home/kshitij/SecurSi/read-write-data-from-uart-by-client/check_encode_decode_png";

    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("opendir failed");
        return 1;
    }

    struct dirent *entry;
    char *file_paths[MAX_FILES];
    int count = 0;

    while ((entry = readdir(dir)) != NULL && count < MAX_FILES) {
        if (entry->d_type != DT_REG && entry->d_type != DT_UNKNOWN)
            continue;

        if (!ends_with_png(entry->d_name))
            continue;

        char full_path[PATHS_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (!is_regular_file(full_path))
            continue;

        file_paths[count] = strdup(full_path);  // store full path
        if (!file_paths[count]) {
            perror("strdup failed");
            closedir(dir);
            return 1;
        }

        count++;
    }

    closedir(dir);

    if (count < 2) {
        fprintf(stderr, "Need at least 2 matching images.\n");
        return 1;
    }

    qsort(file_paths, count, sizeof(char *), compare_strings); // match Java sort order

    for (int i = 0; i < count; i++) {
        #undef printf
        #define printf printf
        printf("File %d: %s\n", i, file_paths[i]);
        // #define printf(...)
        // free(file_paths[i]);  // cleanup
    }

    ////////////////////////////////////////

    // char* path="/home/kshitij/SecurSi/read-write-data-from-uart-by-client/pixels_dir/pixelsKshitijleftindexfinger_0";
    
    int* matchCount = (int*)malloc(sizeof(int));
    int* passCount = (int*)malloc(sizeof(int));
    int* false_positive_number = (int*)malloc(sizeof(int));

    // for(int i=0;i<count;i++)
    // {
    //     strip_png_extension(file_paths[i]);
    // }

    // Open file for writing ("w" overwrites; use "a" to append)
    FILE *file_sc = fopen("scores_file_pico.txt", "a");
    if (file_sc == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int matching = 0;
    int false_positive = 0;
    int passcount = 0;

    char query_rep[MAX_REP_LEN];

    // // Write text to file
    // fprintf(file, "Hello, world!\n");
    // fprintf(file, "This is another line.\n");

    for(int i=0;i<count;i++)
    {
        // if(i<67)
        //     continue;

        // strip_png_extension(file_paths[i]);

        // Restore printf only for one case
        #undef printf
        #define printf printf
        printf("i: %d; DEcoding queryFile: %s\n", i, file_paths[i]);
        // #define printf(...)

        // // Get query representation once
        char clean_query_filename[512];
        get_filename_from_log(file_paths[i], clean_query_filename, sizeof(clean_query_filename));
        get_representation(clean_query_filename, query_rep, sizeof(query_rep));

        // --- Aggregate scores per candidate representation ---
        RepScore *repScores = (RepScore*)calloc((size_t)count-1, sizeof(RepScore));
        if (!repScores) {
            fprintf(stderr, "Memory allocation failed\n");
            return;
        }
        int repCount = 0;

        ArgbImage img = {0};
        int rc = decode_png_file_to_argb32_javaish(&img,i);
        if (rc != 0) {
            #undef printf
            #define printf printf
            printf("decode err=%d\n", rc);
            // #define printf(...)

            i--; continue;
        }

        printf("Decoded %dx%d (ARGB)\n", img.width, img.height);

        DoubleMatrix decoded;
        decoded.width = img.width;
        decoded.height = img.height;
        // decoded.data = (float*)malloc(decoded.width * decoded.height * sizeof(float));
        decoded.data = query_decoded_data;

        for (int y = 0; y < img.height; y++) {
            for (int x = 0; x < img.width; x++) {   
                // Fill matrix like in your Java code

                unsigned int pixel = img.argb[y * img.width + x];

                #undef printf
                #define printf printf
                printf("%d ", pixel);
                // #define printf(...)
            }
            #undef printf
            #define printf printf
            printf("\n");
            // #define printf(...) 
        }

        for (int y = 0; y < img.height; y++) {
            for (int x = 0; x < img.width; x++) {   
                // Fill matrix like in your Java code

                unsigned int pixel = img.argb[y * img.width + x];


                int r = (pixel >> 16) & 0xFF;
                int g = (pixel >> 8) & 0xFF;
                int b = (pixel) & 0xFF;
                int color = r + g + b;

                decoded.data[y * img.width + x] = 1.0 - (color / (3.0 * 255.0));
                #undef printf
                #define printf printf
                printf("%.2f ", decoded.data[y * decoded.width + x]);
                // #define printf(...)
            }
            #undef printf
            #define printf printf
            printf("\n");
            // #define printf(...) 
        }

        // printf("decoded.width: %d\n", decoded.width);
        // printf("decoded.height: %d\n", decoded.height);
        // DoubleMatrix resized_decoded_matrix = resize_dpi(decoded, 500);
        DoubleMatrix resized_decoded_matrix = decoded;
        FeatureTemplate* featureTemplate = extract(resized_decoded_matrix,500);

        SearchTemplate* inner = SearchTemplate_new(featureTemplate);
        print_search_template(inner);
        // free(featureTemplate->minutiae.data);
        // free(featureTemplate);

        //////////

        EdgeHashMap* edge_map = build_edge_map(inner);
        print_edge_hash_map(edge_map);
        printf("Matcher created\n");
        
        Probe* probe = (Probe*)malloc(sizeof(Probe));
        Probe_init(probe, inner, edge_map);

        khash_t(str_dbl) *classScores = kh_init(str_dbl);
        khash_t(str_dbl) *countClass = kh_init(str_dbl);

        char* queryClass = get_class_name(file_paths[i]);       

        for (int j = 0; j < count; j++) {
            if (i == j) continue; // Skip self-comparison

            // strip_png_extension(file_paths[i]);
            #undef printf
            #define printf printf
            printf("j: %d; DEcoding candidateFile: %s\n", j, file_paths[j]);
            // #define printf(...)

            unsigned char* png_2 = NULL; size_t pnglen_2 = 0;
            unsigned err = lodepng_load_file(&png_2, &pnglen_2, file_paths[j]);
            int saved_errno = errno;  
            if (err) { 
                #undef printf
                #define printf printf
                printf("load err=%u\n", err); 
                printf("load err=%u (%s) for %s\n", err, lodepng_error_text(err), file_paths[j]);
                diagnose_path_issue("candidate", file_paths[j], saved_errno);
                // #define printf(...)
                free(png_2);  // Free the allocated memory
                j--; continue; 
            }
            inspect_png_chunks(png_2, pnglen_2);
            free(png_2);

            ArgbImage img_2 = {0};
            int rc = decode_png_file_to_argb32_javaish(&img_2,j);
            if (rc != 0) {
                
                #undef printf
                #define printf printf
                printf("decode err=%d\n", rc); 
                // #define printf(...)
                j--; continue;
            }

            printf("Decoded %dx%d (ARGB)\n", img_2.width, img_2.height);

            DoubleMatrix candidate_decoded;
            candidate_decoded.width = img_2.width;
            candidate_decoded.height = img_2.height;
            candidate_decoded.data = (float*)malloc(candidate_decoded.width * candidate_decoded.height * sizeof(float));

            // for (int y = 0; y < img_2.height; y++) {
            //     for (int x = 0; x < img_2.width; x++) {   
            //         // Fill matrix like in your Java code
    
            //         unsigned int pixel = img_2.argb[y * img_2.width + x];
    
            //         #undef printf
            //         #define printf printf
            //         printf("%d ", pixel);
            //         // #define printf(...)
            //     }
            //     #undef printf
            //     #define printf printf
            //     printf("\n");
            //     // #define printf(...) 
            // }

            for (int y = 0; y < img_2.height; y++) {
                for (int x = 0; x < img_2.width; x++) {   
                    // Fill matrix like in your Java code

                    unsigned int pixel = img_2.argb[y * img_2.width + x];
                    int r = (pixel >> 16) & 0xFF;
                    int g = (pixel >> 8) & 0xFF;
                    int b = (pixel) & 0xFF;
                    int color = r + g + b;

                    candidate_decoded.data[y * candidate_decoded.width + x] = 1.0 - (color / (3.0 * 255.0));
                    
                    #undef printf
                    #define printf printf
                    printf("%.2f ", candidate_decoded.data[y * candidate_decoded.width + x]);    
                    // #define printf(...)                
                }
                #undef printf
                #define printf printf
                printf("\n");
                // #define printf(...)  
            }

            // DoubleMatrix candidate_decoded = read_decoded_bytes(file_paths[j]);
            printf("candidate_decoded.width: %d\n", candidate_decoded.width);
            printf("candidate_decoded.height: %d\n", candidate_decoded.height);
            // DoubleMatrix resized_candidate_matrix = resize_dpi(candidate_decoded, 500);
            DoubleMatrix resized_candidate_matrix = candidate_decoded;
            FeatureTemplate* candidate_feature_template = extract(resized_candidate_matrix, 500, 0);
            SearchTemplate* candidate = SearchTemplate_new(candidate_feature_template);
            print_search_template(candidate);

            double score = matcher_engine_match(probe, candidate);

            #undef printf
            #define printf printf
            printf("Score between %s and %s: %.2f\n", file_paths[i], file_paths[j], score);
            fprintf(file_o, "Score between %s and %s: %.2f\n", file_paths[i], file_paths[j], score);
         // #define printf(...)

            fprintf(file_sc, "Score between %s and %s: %.2f\n", file_paths[i], file_paths[j], score);
            fflush(file_sc);

            // free(candidate_decoded.data);
            SearchTemplate_free(candidate);
            FeatureTemplate_free(candidate_feature_template);
            // free_argb(img_2.argb);
            free(img_2.argb);
            resized_candidate_matrix.data=NULL;

            // Extract candidate representation
            char cand_rep[MAX_REP_LEN];
            char clean_cand_filename[512];
            get_filename_from_log(file_paths[j], clean_cand_filename, sizeof(clean_cand_filename));
            get_representation(clean_cand_filename, cand_rep, sizeof(cand_rep));


            // Add to that representation's running total
            int idx = find_rep_index(repScores, repCount, cand_rep);
            if (idx < 0) {
                // New representation bucket
                strncpy(repScores[repCount].rep, cand_rep, MAX_REP_LEN - 1);
                repScores[repCount].rep[MAX_REP_LEN - 1] = '\0';
                repScores[repCount].sumScore = score;
                repCount++;
            } else {
                repScores[idx].sumScore += score;
                repScores[idx].count += 1;
            }

            // char* currentMatchClass = get_class_name(file_paths[j]);

            // khint_t k = kh_get(str_dbl, classScores, currentMatchClass);
            // double old_score = 0.0;

            // if (k != kh_end(classScores)) {
            //     old_score = kh_val(classScores, k);
            // }

            // // Insert or update
            // int ret;
            // k = kh_put(str_dbl, classScores, strdup(currentMatchClass), &ret);
            // kh_val(classScores, k) = old_score + score;

            // // Update count
            // khint_t count_k = kh_get(str_dbl, countClass, currentMatchClass);
            // if (count_k == kh_end(countClass)) {
            //     k = kh_put(str_dbl, countClass, strdup(currentMatchClass), &ret);
            //     kh_val(countClass, k) = 1; // Initialize count to 1
            // } else {    
            //     kh_val(countClass, count_k) += 1; // Increment count
            // }

        }

        // free(decoded.data);
        SearchTemplate_free(inner);
        FeatureTemplate_free(featureTemplate);
        // free_argb(img.argb);
        // free(resized_decoded_matrix.data);
        resized_decoded_matrix.data = NULL;
        free(img.argb);

        Probe_destroy(probe, 0);                              // NEW (implement)
        // EdgeHashMap_free(edge_map); 
    
        // normalize_and_rank(classScores, countClass, queryClass, 1, &matchCount, &passCount, &false_positive_number);

        // --- Find the highest total score and its representation ---
        double bestScore = INT_MIN;
        int bestIdx = -1;
        for (int i = 0; i < repCount; ++i) {
            if (repScores[i].count > 0) {
                double normalizedScore = repScores[i].sumScore / (double)repScores[i].count;
                if (normalizedScore > bestScore) {
                    bestScore = normalizedScore;
                    bestIdx = i;
                }
            }
        }

        const char *pred_rep = (bestIdx >= 0) ? repScores[bestIdx].rep : "";

        // --- Metrics update per your rules ---
        // 1) Match if predicted representation == query representation (regardless of threshold)
        if (bestIdx >= 0 && strcmp(pred_rep, query_rep) == 0) {
            matching += 1;
        }

        // 2) If highest total score < threshold => pass
        if (bestIdx < 0 || bestScore < threshold) {
            passcount += 1;
        } else {
            // 3) Else, if they don't match and score > threshold => false positive
            if (strcmp(pred_rep, query_rep) != 0) {
                false_positive += 1;
            }
        }

        free(repScores);

    }

    // Close the file
    if (fclose(file_sc) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

     // --- Final metrics ---
    // Use double to avoid integer division
    double total = (double)count;
    double accuracy = (total > 0.0) ? ((double)matching) / total : 0.0;
    double false_positive_rate = (total > 0.0) ? ((double)false_positive) / total : 0.0;
    double pass_rate = (total > 0.0) ? ((double)passcount) / total : 0.0;

    #undef printf
    #define printf printf
    printf("Queries: %d\n", count);
    printf("Matches: %d, False Positives: %d, Passes: %d\n", matching, false_positive, passcount);
    printf("Accuracy: %.6f\n", accuracy);
    printf("False Positive Rate: %.6f\n", false_positive_rate);
    printf("Pass Rate: %.6f\n", pass_rate);
    // #define printf(...)

    fclose(file_o);

    // print_stats(*matchCount, *passCount, count);

    
}

