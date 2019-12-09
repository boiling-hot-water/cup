#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Element {
    char* key;
    int value;
    Element* next;
};

Element* insert_list(Element* head, char* key, int value, bool *res) {
    *res = false;
    if (head == NULL) {
        Element* p = (Element*)malloc(sizeof(Element));
        p->key = key;
        p->value = value;
        p->next = NULL;
        *res = true;
        return p;
    }
    Element* it = head;
    Element* end = NULL;
    while (it != NULL && strcmp(it->key, key) != 0) {
        if (it->next == NULL) {
            end = it;
        }
        it = it->next;
    }
    if (it != NULL) {
        it->value = value;
        *res = false;
    } else {
        Element* p = (Element*)malloc(sizeof(Element));
        p->key = key;
        p->value = value;
        end->next = p;
        *res = true;
    }
    return head;
}

int find_list(Element* head, char* key) {
    Element* it = head;
    while (it != NULL && strcmp(it->key, key) != 0) {
        it = it->next;
    }
    if (it != NULL) {
        return it->value;
    } else return -1;
}

Element* remove(Element* head, char* key) {
    Element* tmp;
    if (head == NULL) {
        return head;
    }
    if (head != NULL && strcmp(head->key, key) ) {
        tmp = head->next;
            free(head);
            return tmp;
    }
    Element* it = head;

    while (it->next != NULL && strcmp(it->next->key, key) != 0) {
            it = it->next;
    }
    tmp = it->next;
    if (tmp != NULL) {
        tmp->next = it->next;
        free(tmp);
    }
    return head;
}

struct HashTable {
    Element** table;
    int n;
};

HashTable* create_table(int n) {
    struct HashTable* h = (HashTable*) malloc(sizeof(struct HashTable));
    h->table = (Element**) malloc(n * sizeof(Element*));
    for (int i; i < n; ++i) {
        h->table[i] = NULL;
    }
    h->n = n;
}

int hash(char* key, int n) {
    int result = 0;
    int p = 7;
    for (int i = 0; i < strlen(key); ++i) {
        result = (result * p + (int)key[i] + 1) % n;
    }
    return result;
}

void insert_ht(HashTable* h, char* key, int value, bool *res) {
    int index = hash(key, h->n);
    h->table[index] = insert_list(h->table[index], key, value, res);
}

int find_ht(HashTable* h, char* key) {
    return find_list(h->table[hash(key, h->n)], key);
}

int main() {
    int n;
    char* command = (char*)malloc(255 * sizeof(char));
    char* name = (char*)malloc(255 * sizeof(char));
    int number;
    scanf("%d", &n);
    HashTable* h = create_table(500);
    for (int i = 0; i < n; ++i) {
        scanf("%s %s", command, name);
        if (strcmp(command, "INSERT") == 0) {
            scanf("%d", &number);
        }
        if (strcmp(command, "INSERT") == 0) {
            bool res = false;
            insert_ht(h, name, number, &res);
            if (res)
                printf("%s", "OK");
        }
        else if (strcmp(command, "FIND") == 0) {
            int number = find_ht(h, name);
            if (number != -1)
              printf("%d", number);
            else printf("%s", "NO");
        }
    }
    return 0;
}
