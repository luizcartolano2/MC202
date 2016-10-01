node *new_node(double value, node *prev, node *next) {
    node *new = malloc(sizeof(node));
    new->value = value;
    new->A = prev;
    new->B = next;
    return new;
}

void insert(node **list, int pos, double element) {

    // Cria uma nova lista
    if (*list == NULL) {
        *list = new_node(element, NULL, NULL);
        return;
    }

    // Altera o primeiro elemento da lista
    if (pos == 0) {
        node *new = new_node(element, NULL, *list);
        (*list)->A = new;
        *list = new;
        return;
    }

    node *cur = *list;
    while (--pos > 0) {
        cur = cur->B;
        pos--;
    }

    // Insere um novo nó entre cur e cur->B
    node *new = new_node(element, cur, cur->B);
    cur->B->A = new;
    cur->B = new;
}
