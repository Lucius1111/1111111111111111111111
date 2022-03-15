#include "ordered_array.h"

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

// возвращает пустое множество для capacity элементов
ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity
    };
}

// возвращает позицию элемента в множестве, если
//элемент не будет найден, вернётся ближайший к нему
size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

// возвращает множество, состоящее из элементов массива a размера size
ordered_array_set ordered_array_set_create_from_array(const int *a, const size_t size) {
    int b[size];
    copyArray(b, a, size);
    qsort(b, size, sizeof(int), compare_ints);

    ordered_array_set set = ordered_array_set_create(size);
    if (size == 0)
        return (ordered_array_set) set;

    append(set.data, &set.size, b[0]);

    int i = 1;
    while (i < size) {
        if (b[i] != b[i - 1]) {
            append(set.data, &set.size, b[i]);
        }
        i++;
    }
    return (ordered_array_set) set;
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size)
        return false;

    for (size_t i = 0; i < set1.size; i++)
        if (set1.data[i] != set2.data[i])
            return false;

    return true;
}

// возвращает значение ’истина’, если элементы множеств subset являются
// подмножеством множества set, иначе - ’ложь’
bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    if (subset.size == 0)
        return true;

    for (size_t i = 0; i < subset.size; i++) {
        if (ordered_array_set_in(&set, subset.data[i]) == set.size)
            return 0;
    }

    return 1;
}

// вывод множества set
void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    bool isEmpty = true;
    for (size_t i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
        isEmpty = false;
    }
    if (isEmpty)
        printf("}");
    else
        printf("\b\b}\n");
}

// возвращает позицию последнего элемента меньшего или равного x
// (вернёт -1, если все числа больше x)
int binarySearchLessOrEqual(const int *a, const int n, const int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x)
            left = middle;
        else
            right = middle;
    }
    return left;
}

// добавляет элемент value в множество set
void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    if (ordered_array_set_in(set, value) == set->size) {
        int positionInsert = binarySearchLessOrEqual(set->data, set->size, value);
        if (positionInsert == -1)
            insert(set->data, &set->size, 0, value);
        else
            insert(set->data, &set->size, positionInsert + 1, value);
    }
}

//удаляет элемент массива a с ндексом pos, уменьшая размер на единицу
void deleteByPosSaveOrder(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];
    *n -= 1;
}

// удаляет элемент value из множества set
void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) != set->size) {
        size_t indexDelete = binarySearch_(set->data, set->size, value);
        deleteByPosSaveOrder(set->data, &set->size, indexDelete);
    }
}

// возвращает объединение множеств set1 и set2
ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    size_t capacity = set1.size + set2.size;
    ordered_array_set set3 = ordered_array_set_create(capacity);

    size_t i = 0;
    size_t j = 0;
    while (j < set2.size && i < set1.size) {
        if (set2.data[j] < set1.data[i]) {
            append(set3.data, &set3.size, set2.data[j]);
            j++;
        } else if (set2.data[j] > set1.data[i]) {
            append(set3.data, &set3.size, set1.data[i]);
            i++;
        } else {
            j++;
        }
    }

    while (j < set2.size) {
        append(set3.data, &set3.size, set2.data[j++]);
    }
    while (i < set1.size) {
        append(set3.data, &set3.size, set1.data[i++]);
    }

    return (ordered_array_set) set3;
}

// возвращает пересечение множеств set1 и set2
ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    size_t capacity = set1.size + set2.size;
    ordered_array_set set3 = ordered_array_set_create(capacity);

    size_t i = 0;
    size_t j = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] > set2.data[j]) {
            j++;
        } else if (set1.data[i] < set2.data[j]) {
            i++;
        } else {
            append(set3.data, &set3.size, set1.data[i++]);
            j++;
        }
    }
    return (ordered_array_set) set3;
}

// возвращает разность множеств set1 и set2
ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    size_t i = 0;
    size_t j = 0;
    int capacity = set1.size + set2.size;
    ordered_array_set set3 = ordered_array_set_create(capacity);

    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            append(set3.data, &set3.size, set1.data[i++]);
        } else if (set1.data[i] == set2.data[j]) {
            i++;
        } else {
            j++;
        }
    }

    for (size_t k = i; k < set1.size; k++) {
        append(set3.data, &set3.size, set1.data[k]);
    }

    return (ordered_array_set) set3;
}

// возвращает симметрическую разность множеств set1 и set2
ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set3 = ordered_array_set_union(ordered_array_set_difference(set1, set2),
                                                     ordered_array_set_difference(set2, set1));

    return (ordered_array_set) set3;
}

// возвращает дополнение до универсума множества set
ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    return (ordered_array_set) ordered_array_set_difference(universumSet, set);
}

// освобождает память, занимаемую множеством set
void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}