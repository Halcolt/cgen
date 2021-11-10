#include "tm.h"
#include "tests/base/utils.h"

#include <string.h>

void tm_bn_free_node(bn_node_t n) {
  free(n);
}

int main() {
  tmt t = tm_create(gtype_cmp_s);
  char *s1 = "1111111111",
       *s2 = "2222222222",
       *s3 = "3333333333",
       *s5 = "5555555555",
       *s6 = "6666666666",
       *s7 = "7777777777",
       *sa = "Nguyen Van A",
       *sb = "Nguyen Van B",
       *sc = "Nguyen Van C",
       *sd = "Nguyen Van D",
       *se = "Nguyen Van E",
       *sf = "Nguyen Van F";
  tm_insert(t, gtype_s(sb), gtype_s(s2));
  tm_insert(t, gtype_s(sa), gtype_s(s1));
  tm_insert(t, gtype_s(sc), gtype_s(s3));
  tm_insert(t, gtype_s(sd), gtype_s(s5));
  tm_insert(t, gtype_s(se), gtype_s(s6));
  tm_insert(t, gtype_s(sf), gtype_s(s7));
  CHECK_MSG(strcmp(tm_value(t, gtype_s(sa))->s, s1) == 0, "Failed A Value");
  CHECK_MSG(strcmp(tm_value(t, gtype_s(sb))->s, s2) == 0, "Failed B Value");
  CHECK_MSG(strcmp(tm_value(t, gtype_s(sc))->s, s3) == 0, "Failed C Value");
  CHECK_MSG(strcmp(tm_value(t, gtype_s(sd))->s, s5) == 0, "Failed D Value");
  CHECK_MSG(strcmp(tm_value(t, gtype_s(se))->s, s6) == 0, "Failed E Value");
  CHECK_MSG(strcmp(tm_value(t, gtype_s(sf))->s, s7) == 0, "Failed F Value");
  tm_delete(t, gtype_s(sd));
  tm_delete(t, gtype_s(se));
  tm_delete(t, gtype_s(sf));
  gtype *value = NULL_PTR;
  gtype query = {.s = sd};
  CHECK_MSG(tm_value(t, query) == NULL_PTR, "Failed not found D");
  query = gtype_s(se);
  CHECK_MSG(tm_value(t, query) == NULL_PTR, "Failed not found E");
  query = gtype_s(sf);
  CHECK_MSG(tm_value(t, query) == NULL_PTR, "Failed not found F");
  bn_free_tree((bn_tree_t*)&t);
  printf("Treemap ut OK\n");
  return 0;
}
