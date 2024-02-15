#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct SV{
  size_t size;
  char *chars;
};

struct SV sv_new(char *new_string){
  struct SV new_sv = {
    .size = strlen(new_string),
    .chars = (char *)malloc(strlen(new_string)+1),
  };
  strcpy(new_sv.chars,new_string);
  return new_sv;
}

char *sv_to_string(struct SV view){
  char *str;
  str = view.chars;
  return str;
}

void sv_insert_sv_at_index(struct SV* view1,struct SV* view2,int index){
  if (index < 0 || index > view1->size) return;
  if (realloc(view1->chars,view1->size+view2->size) == NULL){
    printf("realloc failed!!!");
    return;
  }
  memmove(view1->chars + index + view2->size , view1->chars + index,(view1->size - index));
  memcpy(view1->chars+index,view2->chars,view2->size);
  view1->size = view1->size + view2->size+1;
  
}

int main(){
  struct SV new_view = sv_new("Vamshi krishna");
  sv_insert_sv_at_index(&new_view,&new_view,66);
  printf("%s",sv_to_string(new_view));
  char *s = "emacs";
  free(new_view.chars);
  return 0;
}
