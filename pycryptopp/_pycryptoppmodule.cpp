
#include <Python.h>

#include "publickey/ecdsamodule.hpp"
#include "publickey/rsamodule.hpp"
#include "hash/sha256module.hpp"
#include "cipher/aesmodule.hpp"

PyDoc_STRVAR(_pycryptopp__doc__,
"_pycryptopp -- Python wrappers for a few algorithms from Crypto++\n\
\n\
from pycryptopp import publickey\n\
from pycryptopp.publickey import ecdsa, rsa\n\
from pycryptopp import cipher\n\
from pycryptopp.cipher import aes\n\
from pycryptopp import hash\n\
from pycryptopp.hash import sha256");

static PyMethodDef _pycryptopp_functions[] = {
    {"rsa_generate", reinterpret_cast<PyCFunction>(rsa_generate), METH_KEYWORDS, rsa_generate__doc__},
    {"rsa_create_verifying_key_from_string", reinterpret_cast<PyCFunction>(rsa_create_verifying_key_from_string), METH_KEYWORDS, rsa_create_verifying_key_from_string__doc__},
    {"rsa_create_signing_key_from_string", reinterpret_cast<PyCFunction>(rsa_create_signing_key_from_string), METH_KEYWORDS, rsa_create_signing_key_from_string__doc__},
    {NULL, NULL, 0, NULL}  /* sentinel */
};

#ifndef PyMODINIT_FUNC /* declarations for DLL import/export */
#define PyMODINIT_FUNC void
#endif
PyMODINIT_FUNC
init_pycryptopp(void) {
    PyObject *module;

    module = Py_InitModule3("_pycryptopp", _pycryptopp_functions, _pycryptopp__doc__);
    if (!module)
      return;

    init_ecdsa(module);
    init_rsa(module);
    init_sha256(module);
    init_aes(module);
}
