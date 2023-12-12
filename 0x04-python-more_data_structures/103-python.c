<<<<<<< HEAD
103-python.c
#include <stdio.h>
#include <python.h>

/**
 * print_python_bytes - Prints bytes information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_bytes(PyObject *p)
{
	char *string;
	long int size, i, limit;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	string = ((PyBytesObject *)p)->ob_sval;

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", string);

	if (size >= 10)
		limit = 10;
	else
		limit = size + 1;

	printf("  first %ld bytes:", limit);

	for (i = 0; i < limit; i++)
		if (string[i] >= 0)
			printf(" %02x", string[i]);
		else
			printf(" %02x", 256 + string[i]);

	printf("\n");
}

/**
 * print_python_list - Prints list information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_list(PyObject *p)
{
	long int size, i;
	PyListObject *list;
	PyObject *obj;

	size = ((PyVarObject *)(p))->ob_size;
	list = (PyListObject *)p;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", list->allocated);

	for (i = 0; i < size; i++)
	{
		obj = ((PyListObject *)p)->ob_item[i];
		printf("Element %ld: %s\n", i, ((obj)->ob_type)->tp_name);
		if (PyBytes_Check(obj))
			print_python_bytes(obj);
	}
=======
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
>>>>>>> 4d4f3abda57081b2a0ed44623919ae14e96b5650
