#include <Python.h>
void print_python_list(PyObject *p) {
    if (!PyList_Check(p)) {
        printf("Error: Invalid Python list object.\n");
        return;
    }
    
    printf("[");
    Py_ssize_t size = PyList_Size(p);
    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PyList_GetItem(p, i);
        PyObject *repr = PyObject_Repr(item);
        char *str = PyUnicode_AsUTF8(repr);
        printf("%s", str);
        if (i < size - 1) {
            printf(", ");
        }
        Py_DECREF(repr);
    }
    printf("]\n");

#include <Python.h>
void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        printf("Error: Invalid Python bytes object.\n");
        return;
    }
    
    Py_ssize_t size = PyBytes_Size(p);
    printf("[");
    for (Py_ssize_t i = 0; i < size; i++) {
        unsigned char byte = (unsigned char)PyBytes_AsString(p)[i];
        printf("%u", byte);
        if (i < 9 && i < size - 1) {
            printf(", ");
        }
        else if (i == 9 && size > 10) {
            printf(", ...");
            break;
        }
    }
    printf("]\n");
}}
