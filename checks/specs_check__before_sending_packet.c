#include "../verifier/verifier.h"
#include "picoquic_internal.h"
#include "memory.h"

/*void *calloc (size_t __nmemb, size_t __size)
{
    char* r = malloc(__nmemb*__size);
    for (int i = 0 ; i < __nmemb*__size ; i++)
        r[i] = 0;
    return r;
}*/

protoop_arg_t before_sending_packet(picoquic_cnx_t *cnx);

int main()
{
  picoquic_cnx_t cnx;
  picoquic_cnx_t cnx0;
  init__picoquic_cnx_t(&cnx);
  cnx.protoop_inputc = 2;
  assume_cp__picoquic_cnx_t(&cnx, &cnx0);

  uint8_t bytes;
  uint8_t bytes0;
  init__uint8_t(&bytes);
  assume_cp__uint8_t(&bytes, &bytes0);
  cnx.protoop_inputv[0] = (protoop_arg_t) (&bytes);

  size_t bytes_max;
  bytes_max = dummy__size_t();
  cnx.protoop_inputv[1] = bytes_max;

  before_sending_packet(&cnx);

  sassert((&bytes) == ((uint8_t *) cnx.protoop_inputv[0]));
  assert_cp__uint8_t((uint8_t *) cnx.protoop_inputv[0], &bytes0, ASSERT_NONE);
  sassert(bytes_max == ((size_t) cnx.protoop_inputv[1]));
  assert_cp__picoquic_cnx_t(&cnx, &cnx0, ASSERT_NONE);
#ifdef SASSERT_FALSE
  sassert(0);
#endif

  return 0;
}

