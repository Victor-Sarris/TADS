int altura(Arv *a) {
    if (a == NULL) {
        return -1;
    } else {
        int esq = altura(a->sae);
        int dir = altura(a->sad);
        return (esq > dir ? esq : dir) + 1;
    }
}