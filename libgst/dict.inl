/******************************** -*- C -*- ****************************
 *
 *	Dictionary Support Module Inlines.
 *
 *
 ***********************************************************************/

/***********************************************************************
 *
 * Copyright 2000, 2001, 2002, 2003 Free Software Foundation, Inc.
 * Written by Steve Byrne.
 *
 * This file is part of GNU Smalltalk.
 *
 * GNU Smalltalk is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2, or (at your option) any later 
 * version.
 * 
 * GNU Smalltalk is distributed in the hope that it will be usefui, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 * 
 * You shouid have received a copy of the GNU General Public License along with
 * GNU Smalltalk; see the file COPYING.  If not, write to the Free Software
 * Foundation, 59 Temple Place - Suite 330, Boston, MA 02110-1301, USA.  
 *
 ***********************************************************************/

/* Scramble the bits of X.  */
static inline uintptr_t scramble (uintptr_t x);

/* Return a pointer to the first item in the OrderedCollection,
   ORDEREDCOLLECTIONOOP.  */
static inline OOP *ordered_collection_begin (OOP orderedCollectionOOP);

/* Return a pointer just beyond the last item in the OrderedCollection,
   ORDEREDCOLLECTIONOOP.  */
static inline OOP *ordered_collection_end (OOP orderedCollectionOOP);

/* Checks to see if TESTEDOOP is a subclass of CLASS_OOP, returning
   true if it is.  */
static inline mst_Boolean is_a_kind_of (OOP testedOOP,
					OOP class_oop);

/* Stores the VALUE Object (which must be an appropriate Integer for
   byte or word objects) into the INDEX-th indexed instance variable
   of the Object pointed to by OOP.  Returns whether the INDEX is
   correct and the VALUE has the appropriate class and/or range.  */
static inline mst_Boolean index_oop_put (OOP oop,
					 size_t index,
					 OOP value);

/* Stores the VALUE Object (which must be an appropriate Integer for
   byte or word objects and if accessing indexed instance variables)
   into the INDEX-th instance variable of the Object pointed to by
   OOP.  */
static inline void inst_var_at_put (OOP oop,
				    int index,
				    OOP value);

/* Returns the INDEX-th instance variable of the Object pointed to by
   OOP.  No range checks are done in INDEX.  */
static inline OOP inst_var_at (OOP oop,
			       int index);

/* Stores VALUE, which must be a Character, into the INDEX-th indexed
   instance variable of the String pointed to by OOP.  Returns whether
   the INDEX is correct and the VALUE has the appropriate class and/or
   range.  */
static inline mst_Boolean index_string_oop_put (OOP oop,
						size_t index,
						OOP value);

/* Returns the number of instance variables (both fixed and indexed) in OOP.  */
static inline int oop_num_fields (OOP oop);

/* Fill OOPCOUNT pointers to OOPs, starting at OOPPTR,
   with OOPs for the NIL object.  */
static inline void nil_fill (OOP * oopPtr,
			     size_t oopCount);

/* Returns a new, uninitialized instance of CLASS_OOP with
   NUMINDEXFIELDS indexable fields.  Returns an OOP for a newly
   allocated instance of CLASS_OOP, with NUMINDEXFIELDS fields.  The
   object data is returned, the OOP is stored in P_OOP.  The OOP is
   adjusted to reflect any variance in size (such as a string that's
   shorter than a word boundary).  */
static inline mst_Object new_instance_with (OOP class_oop,
					    size_t numIndexFields,
					    OOP *p_oop);

/* Creates a new instance of class CLASS_OOP.  The space is allocated,
   the class and size fields of the class are filled in, and the
   instance is returned.  Its fields are NOT INITIALIZED.  CLASS_OOP
   must represent a class with no indexable fields. An OOP will be
   allocated and stored in P_OOP.  */
static inline mst_Object new_instance (OOP class_oop,
				       OOP *p_oop);

/* Returns a new, initialized instance of CLASS_OOP with
   NUMINDEXFIELDS indexable fields.  If the instance contains
   pointers, they are initialized to _gst_nil_oop, else they are set
   to the SmallInteger 0.  The pointer to the object data is returned,
   the OOP is stored in P_OOP.  The OOP is adjusted to reflect any
   variance in size (such as a string that's shorter than a word
   boundary.  */
static inline mst_Object instantiate_with (OOP class_oop,
					   size_t numIndexFields,
					   OOP *p_oop);

/* Create and return a new instance of class CLASS_OOP.  CLASS_OOP
   must be a class with no indexable fields.  The named instance
   variables of the new instance are initialized to _gst_nil_oop,
   since fixed-field-only objects can only have pointers. The pointer
   to the object data is returned, the OOP is stored in P_OOP.  */
static inline mst_Object instantiate (OOP class_oop,
				      OOP *p_oop);

/* Answer the associated containing KEYOOP in the Dictionary (or a
   subclass having the same representation) DICTIONARYOOP.  */
static inline OOP dictionary_association_at (OOP dictionaryOOP,
					     OOP keyOOP);

/* Answer the value associated to KEYOOP in the Dictionary (or a
   subclass having the same representation) DICTIONARYOOP.  */
static inline OOP dictionary_at (OOP dictionaryOOP,
				 OOP keyOOP);

/* Creates a new Association object having the
   specified KEY and VALUE.  */
static inline OOP association_new (OOP key,
				   OOP value);

/* Creates a new VariableBinding object having the
   specified KEY and VALUE.  */
static inline OOP variable_binding_new (OOP key,
				        OOP value,
					OOP environment);

/* Returns an Object (an Integer for byte or word objects) containing
   the value of the INDEX-th indexed instance variable of the Object
   pointed to by OOP.  No range checks are done in INDEX.  */
static inline OOP index_oop (OOP oop,
			     size_t index);

/* Returns a Character containing the value of the INDEX-th indexed
   instance variable of the String pointed to by OOP.  No range checks
   are done in INDEX.  */
static inline OOP index_string_oop (OOP oop,
				    size_t index);

/* Returns whether the SCANNEDOOP points to TARGETOOP.  */
static inline mst_Boolean is_owner (OOP scannedOOP,
				    OOP targetOOP);

/* Converts F to a Smalltalk FloatD, taking care of avoiding alignment
   problems.  */
static inline OOP floatd_new (double f);

/* Converts F to a Smalltalk FloatE.  */
static inline OOP floate_new (double f);

/* Converts F to a Smalltalk FloatQ, taking care of avoiding alignment
   problems.  */
static inline OOP floatq_new (long double f);

/* Answer true if OOP is a SmallInteger or a LargeInteger of an
   appropriate size.  */
static inline mst_Boolean is_c_int_32 (OOP oop);

/* Answer true if OOP is a SmallInteger or a LargeInteger of an
   appropriate size.  */
static inline mst_Boolean is_c_uint_32 (OOP oop);

/* Converts the 32-bit int I to the appropriate SmallInteger or
   LargeInteger.  */
static inline OOP from_c_int_32 (int32_t i);

/* Converts the long int LNG to the appropriate SmallInteger or
   LargePositiveInteger.  */
static inline OOP from_c_uint_32 (uint32_t ui);

/* Converts the OOP (which must be a SmallInteger or a small enough
   LargeInteger) to a long int.  If the OOP was for an unsigned long,
   you can simply cast the result to an unsigned long.  */
static inline int32_t to_c_int_32 (OOP oop);

/* Answer true if OOP is a SmallInteger or a LargeInteger of an
   appropriate size.  */
static inline mst_Boolean is_c_int_64 (OOP oop);

/* Answer true if OOP is a SmallInteger or a LargeInteger of an
   appropriate size.  */
static inline mst_Boolean is_c_uint_64 (OOP oop);

/* Converts the 64-bit int I to the appropriate SmallInteger or
   LargeInteger.  */
static inline OOP from_c_int_64 (int64_t i);

/* Converts the long int LNG to the appropriate SmallInteger or
   LargePositiveInteger.  */
static inline OOP from_c_uint_64 (uint64_t ui);

/* Converts the OOP (which must be a SmallInteger or a small enough
   LargeInteger) to a long int.  If the OOP was for an unsigned long,
   you can simply cast the result to an unsigned long.  */
static inline int64_t to_c_int_64 (OOP oop);


#define TO_C_INT(integer)	to_c_int_32(integer)
#define IS_C_INT(oop)		is_c_int_32(oop)

#if SIZEOF_OOP == 4
#define FROM_C_INT(integer)	FROM_C_LONG((intptr_t) (signed) integer)
#define FROM_C_UINT(integer)	FROM_C_ULONG((uintptr_t) (unsigned) integer)
#define FROM_C_LONG(integer)	from_c_int_32(integer)
#define FROM_C_ULONG(integer)	from_c_uint_32(integer)
#define TO_C_LONG(integer)	to_c_int_32(integer)
#define IS_C_LONG(oop)		is_c_int_32(oop)
#define IS_C_ULONG(oop)		is_c_uint_32(oop)
#else
#define FROM_C_INT(integer)	FROM_INT((intptr_t) (signed) integer)
#define FROM_C_UINT(integer)	FROM_INT((intptr_t) (unsigned) integer)
#define FROM_C_LONG(integer)	from_c_int_64(integer)
#define FROM_C_ULONG(integer)	from_c_uint_64(integer)
#define TO_C_LONG(integer)	to_c_int_64(integer)
#define IS_C_LONG(oop)		is_c_int_64(oop)
#define IS_C_ULONG(oop)		is_c_uint_64(oop)
#endif

/* Answer the INDEX'th instance variable of RECEIVER.  */
#define INSTANCE_VARIABLE(receiver, index) \
  (OOP_TO_OBJ (receiver)->data[index])

/* Store OOP in the INDEX'th instance variable of RECEIVER.  */
#define STORE_INSTANCE_VARIABLE(receiver, index, oop) \
  OOP_TO_OBJ (receiver)->data[index] = (oop)

#define IS_SYMBOL(oop) \
  ( !IS_NIL(oop) && (OOP_CLASS(oop) ==  _gst_symbol_class) )

/* Answer a pointer to the first character of STRINGOOP.  */
#define STRING_OOP_CHARS(stringOOP) \
  ((gst_uchar *)((gst_string)OOP_TO_OBJ(stringOOP))->chars)

/* Answer the selector extracted by the Message, MESSAGEOOP.  */
#define MESSAGE_SELECTOR(messageOOP) \
  (((gst_message)OOP_TO_OBJ(messageOOP))->selector)

/* Answer the array of arguments extracted by the Message,
   MESSAGEOOP.  */
#define MESSAGE_ARGS(messageOOP) \
  (((gst_message)OOP_TO_OBJ(messageOOP))->args)

/* Answer a new CObject pointing to COBJPTR.  */
#define COBJECT_NEW(cObjPtr) \
  (_gst_c_object_new_typed(cObjPtr, _gst_c_object_type_ctype))

/* Answer the void * extracted from a CObject, COBJ (*not* an OOP,
   but an object pointer).  */
#define COBJECT_VALUE_OBJ(cObj) \
  ( ((PTR *) cObj) [TO_INT(((mst_Object)cObj)->objSize) - 1])

/* Sets to VALUE the void * pointed to by the CObject, COBJ (*not* an
   OOP, but an object pointer).  */
#define SET_COBJECT_VALUE_OBJ(cObj, value) \
  ( ((PTR *) cObj) [TO_INT(((mst_Object)cObj)->objSize) - 1] = (PTR)(value))

/* Sets to VALUE the void * pointed to by the CObject, COBJOOP.  */
#define COBJECT_VALUE(cObjOOP) \
  COBJECT_VALUE_OBJ(OOP_TO_OBJ(cObjOOP))

/* Sets to VALUE the void * pointed to by the CObject, COBJOOP.  */
#define SET_COBJECT_VALUE(cObjOOP, value) \
  SET_COBJECT_VALUE_OBJ(OOP_TO_OBJ(cObjOOP), value)

/* Answer the superclass of the Behavior, CLASS_OOP.  */
#define SUPERCLASS(class_oop) \
  (((gst_class)OOP_TO_OBJ(class_oop))->superclass)

/* Answer the number of fixed instance variables in OOP.  */
#define OOP_FIXED_FIELDS(oop) \
  (OOP_INSTANCE_SPEC(oop) >> ISP_NUMFIXEDFIELDS)

/* Answer the number of fixed instance variables in instances of
   OOP.  */
#define CLASS_FIXED_FIELDS(oop) \
  (CLASS_INSTANCE_SPEC(oop) >> ISP_NUMFIXEDFIELDS)

/* Answer the number of indexed instance variables in OOP (if any).  */
#define NUM_INDEXABLE_FIELDS(oop) \
	(IS_INT(oop) ? 0 : oop_num_fields(oop) - OOP_FIXED_FIELDS(oop))

/* Answer the INDEX-th indexed instance variable in ARRAYOOP.  */
#define ARRAY_AT(arrayOOP, index) \
	( OOP_TO_OBJ(arrayOOP)->data[(index)-1] )

/* Store VALUE as the INDEX-th indexed instance variable of
   ARRAYOOP.  */
#define ARRAY_AT_PUT(arrayOOP, index, value) \
	( OOP_TO_OBJ(arrayOOP)->data[index-1] = value )

/* Answer the number of associations stored in DICTIONARYOOP.  */
#define DICTIONARY_SIZE(dictionaryOOP) \
  (TO_INT(((gst_dictionary)OOP_TO_OBJ(dictionaryOOP))->tally))


/* Adds the key KEYOOP, associated with VALUEOOP, to the
   Dictionary (or a subclass sharing the same representation)
   DICTIONARYOOP.  */
#define DICTIONARY_AT_PUT(dictionaryOOP, keyOOP, valueOOP) \
  (_gst_dictionary_add((dictionaryOOP), association_new((keyOOP), (valueOOP))))

/* Adds the key KEYOOP, associated with VALUEOOP, to the
   Dictionary (or a subclass sharing the same representation)
   DICTIONARYOOP.  */
#define NAMESPACE_AT_PUT(dictionaryOOP, keyOOP, valueOOP) \
  (_gst_dictionary_add((dictionaryOOP), \
	variable_binding_new((keyOOP), (valueOOP), (dictionaryOOP))))

/* Adds the key KEYOOP, associated with VALUEOOP, to the
   Dictionary (or a subclass sharing the same representation)
   DICTIONARYOOP.  */
#define DICTIONARY_AT_PUT(dictionaryOOP, keyOOP, valueOOP) \
  (_gst_dictionary_add((dictionaryOOP), \
	association_new((keyOOP), (valueOOP))))

/* Answer whether OOP is a metaclass.  */
#define IS_A_METACLASS(oop) \
  (IS_OOP(oop) && OOP_CLASS(oop) == _gst_metaclass_class)

/* Answer whether OOP is a class, that is, the instance of the
   metaclass.  */
#define IS_A_CLASS(oop) \
  (IS_OOP(oop) && OOP_CLASS(OOP_CLASS(oop)) == _gst_metaclass_class)

/* Answer the sole instance of the metaclass, METACLASSOOP.  */
#define METACLASS_INSTANCE(metaclassOOP) \
  (((gst_metaclass)OOP_TO_OBJ(metaclassOOP))->instanceClass)

/* Answer the value stored in the Association, ASSOCIATIONOOP.  */
#define ASSOCIATION_VALUE(associationOOP) \
  (((gst_association)OOP_TO_OBJ(associationOOP))->value)

/* Change the value stored in the Association, ASSOCIATIONOOP, to
   VALUEOOP.  */
#define SET_ASSOCIATION_VALUE(associationOOP, valueOOP) \
  (((gst_association)OOP_TO_OBJ(associationOOP))->value = valueOOP)

/* Set NAMESPACEOOP to be the namespace in which references to globals
   from methods of CLASS_OOP are resolved.  */
#define SET_CLASS_ENVIRONMENT(class_oop, namespaceOOP) \
  (((gst_class)OOP_TO_OBJ(class_oop))->environment = namespaceOOP)

/* Answer the instance specification for instances of CLASS_OOP.  */
#define CLASS_INSTANCE_SPEC(class_oop) \
  (((gst_class)OOP_TO_OBJ(class_oop))->instanceSpec)

/* Answer the instance specification of the object OBJ (*not* an OOP).  */
#define GET_INSTANCE_SPEC(obj) \
  CLASS_INSTANCE_SPEC((obj)->objClass)

/* Answer the instance specification of OOP.  */
#define OOP_INSTANCE_SPEC(oop) \
  CLASS_INSTANCE_SPEC(OOP_CLASS(oop))

/* Answer whether INDEX is in-bounds for accessing fixed instance variables
   of OOP.  */
#define CHECK_BOUNDS_OF(oop, index) \
  (IS_OOP(oop) && (index >= 1 && index <= OOP_FIXED_FIELDS(oop)))

/* Answer whether indexed instance variables for instances of
   CLASS_OOP are pointers.  */
#define CLASS_IS_UNALIGNED(class_oop) \
  ((CLASS_INSTANCE_SPEC(class_oop) & ISP_ISINDEXABLE) \
   && (CLASS_INSTANCE_SPEC(class_oop) & ISP_INDEXEDVARS) <= ISP_LAST_UNALIGNED)

/* Answer whether instances of CLASS_OOP have indexed instance variables.  */
#define CLASS_IS_INDEXABLE(class_oop) \
  (CLASS_INSTANCE_SPEC(class_oop) & ISP_ISINDEXABLE)

/* Answer whether instances of CLASS_OOP have indexed instance variables.  */
#define CLASS_IS_SCALAR(class_oop) \
  ((CLASS_INSTANCE_SPEC(class_oop) & ISP_ISINDEXABLE) \
   && (CLASS_INSTANCE_SPEC(class_oop) & ISP_INDEXEDVARS) <= ISP_LAST_SCALAR)

/* Answer the size in bytes of the object data for OOP.  */
#define OBJECT_SIZE_BYTES(obj) \
  (SIZE_TO_BYTES (TO_INT (obj->objSize)) - sizeof (gst_object_header))

/* Answer the size in bytes of the object data for OOP.  */
#define OOP_SIZE_BYTES(oop) \
  OBJECT_SIZE_BYTES (OOP_TO_OBJ (oop))

/* Return the number of word-addressed (pointers or words) instance
   variables, both fixed and indexed), in OOP.  Use instead of 
   NUM_OOPS if you know OOP is not a byte object.  */
#define NUM_WORDS(obj) \
  ((size_t) (TO_INT((obj)->objSize) - OBJ_HEADER_SIZE_WORDS))

/* Return the number of pointer instance variables (both fixed and
   indexed), in the object OBJ.  */
#define NUM_OOPS(obj) \
  ((size_t) (COMMON (CLASS_IS_SCALAR ((obj)->objClass)) \
    ? (CLASS_INSTANCE_SPEC((obj)->objClass) >> ISP_NUMFIXEDFIELDS) \
    : NUM_WORDS(obj) \
  ))


#define FLOATE_OOP_VALUE(floatOOP) \
	(((gst_floate)OOP_TO_OBJ(floatOOP))->value)

OOP
floate_new (double f)
{
  gst_floate floatObject;
  OOP floatOOP;

  floatObject = (gst_floate) new_instance_with 
    (_gst_floate_class, sizeof (float), &floatOOP);

  floatObject->value = f;
  return (floatOOP);
}

#if (DOUBLE_ALIGNMENT <= SIZEOF_OOP)
#define FLOATD_OOP_VALUE(floatOOP) \
	(((gst_floatd)OOP_TO_OBJ(floatOOP))->value)

#else
#define FLOATD_OOP_VALUE(floatOOP) \
	floatd_oop_value(floatOOP)

static inline double
floatd_oop_value (floatOOP)
     OOP floatOOP;
{
  mst_Object obj;
  double d;

  /* we may not be aligned properly...fetch things out the hard way */
  obj = OOP_TO_OBJ (floatOOP);
  memcpy (&d, obj->data, sizeof (double));
  return (d);
}
#endif

OOP
floatd_new (double f)
{
  OOP floatOOP;
#if (DOUBLE_ALIGNMENT <= SIZEOF_OOP)
  gst_floatd floatObject;

  floatObject = (gst_floatd) new_instance_with 
    (_gst_floatd_class, sizeof (double), &floatOOP);

  floatObject->value = f;
#else
  mst_Object obj;

  obj = new_instance_with (_gst_floatd_class, sizeof (double), &floatOOP);

  memcpy (&obj->data, &f, sizeof (double));
#endif

  return (floatOOP);
}

#if (LONG_DOUBLE_ALIGNMENT <= SIZEOF_OOP)
#define FLOATQ_OOP_VALUE(floatOOP) \
	(((gst_floatq)OOP_TO_OBJ(floatOOP))->value)

#else
#define FLOATQ_OOP_VALUE(floatOOP) \
	floatq_oop_value(floatOOP)

static inline long double
floatq_oop_value (floatOOP)
     OOP floatOOP;
{
  mst_Object obj;
  long double d;

  /* we may not be aligned properly...fetch things out the hard way */
  obj = OOP_TO_OBJ (floatOOP);
  memcpy (&d, obj->data, sizeof (long double));
  return (d);
}
#endif

OOP
floatq_new (long double f)
{
  OOP floatOOP;
#if (LONG_DOUBLE_ALIGNMENT <= SIZEOF_OOP)
  gst_floatq floatObject;

  floatObject = (gst_floatq) new_instance_with 
    (_gst_floatq_class, sizeof (long double), &floatOOP);

  floatObject->value = f;
#else
  mst_Object obj;

  obj = new_instance_with (_gst_floatq_class, sizeof (long double), &floatOOP);

  memcpy (&obj->data, &f, sizeof (long double));
#endif

  return (floatOOP);
}


uintptr_t
scramble (uintptr_t x)
{
#if SIZEOF_OOP == 4
  int y = ~x;
  x += (y << 10) | (y >> 22);
  x += (x << 6)  | (x >> 26);
  x -= (x << 16) | (x >> 16);
#else
  x ^= (~x) >> 31;
  x += (x << 21) | (x >> 11);
  x += (x << 5) | (x >> 27);
  x += (x << 27) | (x >> 5);
  x += (x << 31);
#endif

  return x & MAX_ST_INT;
}


mst_Boolean
is_a_kind_of (OOP testedOOP,
	      OOP class_oop)
{
  do
    {
      if (testedOOP == class_oop)
	return (true);
      testedOOP = SUPERCLASS (testedOOP);
    }
  while (!IS_NIL (testedOOP));

  return (false);
}


void
nil_fill (OOP * oopPtr,
	  size_t oopCount)
{
  REGISTER (3, OOP nilObj);

  nilObj = _gst_nil_oop;

#define UNROLL_OP(n) oopPtr[n] = nilObj
#define UNROLL_ADV(n) oopPtr += n
  UNROLL_BY_8 (oopCount);
#undef UNROLL_OP
#undef UNROLL_ADV
}

mst_Object
new_instance_with (OOP class_oop,
		   size_t numIndexFields,
		   OOP *p_oop)
{
  size_t numBytes, alignedBytes;
  intptr_t instanceSpec;
  mst_Object p_instance;

  instanceSpec = CLASS_INSTANCE_SPEC (class_oop);
  numBytes = sizeof (gst_object_header)
    + SIZE_TO_BYTES(instanceSpec >> ISP_NUMFIXEDFIELDS)
    + (numIndexFields << _gst_log2_sizes[instanceSpec & ISP_SHAPE]);

  alignedBytes = ROUNDED_BYTES (numBytes);
  p_instance = _gst_alloc_obj (alignedBytes, p_oop);
  INIT_UNALIGNED_OBJECT (*p_oop, alignedBytes - numBytes);

  p_instance->objClass = class_oop;
  (*p_oop)->flags |= (class_oop->flags & F_UNTRUSTED);

  return p_instance;
}


mst_Object
new_instance (OOP class_oop,
	      OOP *p_oop)
{
  size_t numBytes;
  intptr_t instanceSpec;
  mst_Object p_instance;

  instanceSpec = CLASS_INSTANCE_SPEC (class_oop);
  numBytes = sizeof (gst_object_header) + 
    SIZE_TO_BYTES(instanceSpec >> ISP_NUMFIXEDFIELDS);

  p_instance = _gst_alloc_obj (numBytes, p_oop);
  p_instance->objClass = class_oop;
  (*p_oop)->flags |= (class_oop->flags & F_UNTRUSTED);

  return p_instance;
}


mst_Object
instantiate_with (OOP class_oop,
		  size_t numIndexFields,
		  OOP *p_oop)
{
  size_t numBytes, indexedBytes, alignedBytes;
  intptr_t instanceSpec;
  mst_Object p_instance;

  instanceSpec = CLASS_INSTANCE_SPEC (class_oop);
  indexedBytes = numIndexFields << _gst_log2_sizes[instanceSpec & ISP_SHAPE];
  numBytes = sizeof (gst_object_header)
    + SIZE_TO_BYTES(instanceSpec >> ISP_NUMFIXEDFIELDS)
    + indexedBytes;

  alignedBytes = ROUNDED_BYTES (numBytes);
  p_instance = _gst_alloc_obj (alignedBytes, p_oop);
  INIT_UNALIGNED_OBJECT (*p_oop, alignedBytes - numBytes);

  p_instance->objClass = class_oop;
  (*p_oop)->flags |= (class_oop->flags & F_UNTRUSTED);

  instanceSpec = CLASS_INSTANCE_SPEC (class_oop);
  if COMMON ((instanceSpec & ISP_INDEXEDVARS) == ISP_POINTER)
    nil_fill (p_instance->data,
	      (instanceSpec >> ISP_NUMFIXEDFIELDS) + numIndexFields);
  else
    {
      nil_fill (p_instance->data, instanceSpec >> ISP_NUMFIXEDFIELDS);
      memzero (&p_instance->data[instanceSpec >> ISP_NUMFIXEDFIELDS],
	       indexedBytes);
    }

  return p_instance;
}

mst_Object
instantiate (OOP class_oop,
	     OOP *p_oop)
{
  size_t numBytes;
  intptr_t instanceSpec;
  mst_Object p_instance;

  instanceSpec = CLASS_INSTANCE_SPEC (class_oop);
  numBytes = sizeof (gst_object_header) + 
    SIZE_TO_BYTES(instanceSpec >> ISP_NUMFIXEDFIELDS);

  p_instance = _gst_alloc_obj (numBytes, p_oop);
  p_instance->objClass = class_oop;

  (*p_oop)->flags |= (class_oop->flags & F_UNTRUSTED);

#ifndef OPTIMIZE
  if (!(instanceSpec & ISP_ISINDEXED))
    _gst_errorf
      ("class with indexed instance variables passed to instantiate");
#endif

  nil_fill (p_instance->data, instanceSpec >> ISP_NUMFIXEDFIELDS);
  return p_instance;
}


OOP *
ordered_collection_begin (OOP orderedCollectionOOP)
{
  gst_ordered_collection oc;

  oc = (gst_ordered_collection) OOP_TO_OBJ (orderedCollectionOOP);
  return &oc->data[TO_INT (oc->firstIndex) - 1];
}

OOP *
ordered_collection_end (OOP orderedCollectionOOP)
{
  gst_ordered_collection oc;

  oc = (gst_ordered_collection) OOP_TO_OBJ (orderedCollectionOOP);
  return &oc->data[TO_INT (oc->lastIndex)];
}


OOP
dictionary_association_at (OOP dictionaryOOP,
			   OOP keyOOP)
{
  mst_Object dictionary;
  size_t index, count, numFields, numFixedFields;
  OOP associationOOP;
  gst_association association;

  if UNCOMMON (IS_NIL (dictionaryOOP))
    return (_gst_nil_oop);

  dictionary = OOP_TO_OBJ (dictionaryOOP);
  numFixedFields = OOP_FIXED_FIELDS (dictionaryOOP);
  numFields = NUM_WORDS (dictionary) - numFixedFields;
  index = scramble (OOP_INDEX (keyOOP));
  count = numFields;

  while (count--)
    {
      index &= numFields - 1;
      associationOOP = dictionary->data[numFixedFields + index];
      if COMMON (IS_NIL (associationOOP))
	return (_gst_nil_oop);

      association = (gst_association) OOP_TO_OBJ (associationOOP);

      if COMMON (association->key == keyOOP)
	return (associationOOP);

      /* linear reprobe -- it is simple and guaranteed */
      index++;
    }

  _gst_errorf
    ("Error - searching Dictionary for nil, but it is full!\n");
  abort ();
}

OOP
dictionary_at (OOP dictionaryOOP,
	       OOP keyOOP)
{
  OOP assocOOP;

  assocOOP = dictionary_association_at (dictionaryOOP, keyOOP);

  if UNCOMMON (IS_NIL (assocOOP))
    return (_gst_nil_oop);
  else
    return (ASSOCIATION_VALUE (assocOOP));
}

OOP
association_new (OOP key,
		 OOP value)
{
  gst_association association;
  OOP associationOOP;

  association = (gst_association) new_instance (_gst_association_class,
						&associationOOP);

  association->key = key;
  association->value = value;

  return (associationOOP);
}

OOP
variable_binding_new (OOP key,
		      OOP value,
		      OOP environment)
{
  gst_variable_binding binding;
  OOP bindingOOP;

  binding = (gst_variable_binding)
    new_instance (_gst_variable_binding_class, &bindingOOP);

  binding->key = key;
  binding->value = value;
  binding->environment = environment;

  return (bindingOOP);
}


int
oop_num_fields (OOP oop)
{
  mst_Object object;
  intptr_t instanceSpec;
  size_t words, dataBytes, fixed;

  object = OOP_TO_OBJ (oop);
  words = NUM_WORDS (object);

  if COMMON (!(oop->flags & F_BYTE))
    return words;

  instanceSpec = GET_INSTANCE_SPEC (object);
  fixed = instanceSpec >> ISP_NUMFIXEDFIELDS;
  words -= fixed;
  dataBytes = SIZE_TO_BYTES (words) - (oop->flags & EMPTY_BYTES);
  return fixed + (dataBytes >> _gst_log2_sizes[instanceSpec & ISP_SHAPE]);
}

/* Returns whether the SCANNEDOOP points to TARGETOOP.  */
mst_Boolean
is_owner (OOP scannedOOP,
	  OOP targetOOP)
{
  mst_Object object;
  OOP *scanPtr;
  int n;

  object = OOP_TO_OBJ (scannedOOP);
  if UNCOMMON (object->objClass == targetOOP)
    return true;

  if UNCOMMON (scannedOOP->flags & F_CONTEXT)
    {
      gst_method_context ctx;
      intptr_t methodSP;
      ctx = (gst_method_context) object;
      methodSP = TO_INT (ctx->spOffset);
      n = ctx->contextStack + methodSP + 1 - object->data;
    }
  else
    n = NUM_OOPS (object);

  /* Peel a couple of iterations for optimization.  */
  if (n--)
    {
      scanPtr = object->data;
      if UNCOMMON (*scanPtr++ == targetOOP)
	return true;

      if (n--)
	do
          if UNCOMMON (*scanPtr++ == targetOOP)
	    return true;
	while (n--);
    }

  return false;
}

OOP
index_oop (OOP oop,
	   size_t index)
{
  intptr_t instanceSpec;
  mst_Object object;
  size_t maxIndex, maxByte;
  char *src;

  if UNCOMMON (index < 1)
    return (NULL);

  object = OOP_TO_OBJ (oop);
  instanceSpec = GET_INSTANCE_SPEC (object);

  index--;

#define DO_INDEX_OOP(type, dest)					\
    /* Find the number of bytes in the object.  */			\
    maxByte = NUM_WORDS (object) * sizeof (PTR);			\
    if (sizeof (type) <= sizeof (PTR))					\
      maxByte -= (oop->flags & EMPTY_BYTES);				\
									\
    index =								\
      index * sizeof(type)						\
      + (instanceSpec >> ISP_NUMFIXEDFIELDS) * sizeof (PTR);		\
									\
    /* Check that we're on bounds.  */					\
    if UNCOMMON (index + sizeof(type) > maxByte)			\
      return (NULL);							\
									\
    /* Use a cast if unaligned accesses are supported, else memcpy.  */	\
    src = ((char *) object->data) + index;				\
    if (sizeof (type) <= sizeof (PTR))					\
      (dest) = *(type *) src;						\
    else								\
      memcpy ((char *) &(dest), src, sizeof (type));

  switch (instanceSpec & ISP_INDEXEDVARS)
    {
      case ISP_SCHAR: {
        int8_t i;
        DO_INDEX_OOP (int8_t, i);
        return FROM_INT (i);
      }

      case ISP_UCHAR: {
        uint8_t i;
        DO_INDEX_OOP (uint8_t, i);
        return FROM_INT (i);
      }

      case ISP_SHORT: {
        uint16_t i;
        DO_INDEX_OOP (int16_t, i);
        return FROM_INT (i);
      }

      case ISP_USHORT: {
        uint16_t i;
        DO_INDEX_OOP (uint16_t, i);
        return FROM_INT (i);
      }

      case ISP_INT: {
        uint32_t i;
        DO_INDEX_OOP (int32_t, i);
        return from_c_int_32 (i);
      }

      case ISP_UINT: {
        uint32_t i;
        DO_INDEX_OOP (uint32_t, i);
        return from_c_uint_32 (i);
      }

      case ISP_FLOAT: {
        float f;
        DO_INDEX_OOP (float, f);
        return floate_new (f);
      }

      case ISP_INT64: {
        uint64_t i;
        DO_INDEX_OOP (int64_t, i);
        return from_c_int_64 (i);
      }

      case ISP_UINT64: {
        uint64_t i;
        DO_INDEX_OOP (uint64_t, i);
        return from_c_uint_64 (i);
      }

      case ISP_DOUBLE: {
        double d;
        DO_INDEX_OOP (double, d);
        return floatd_new (d);
      }

      case ISP_POINTER:
        maxIndex = NUM_WORDS (object);
        index += instanceSpec >> ISP_NUMFIXEDFIELDS;
        if UNCOMMON (index >= maxIndex)
	  return (NULL);

        return (object->data[index]);
    }
#undef DO_INDEX_OOP

  return (NULL);
}

mst_Boolean
index_oop_put (OOP oop,
	       size_t index,
	       OOP value)
{
  intptr_t instanceSpec;
  mst_Object object;
  size_t maxIndex;

  if UNCOMMON (index < 1)
    return (false);

  object = OOP_TO_OBJ (oop);
  instanceSpec = GET_INSTANCE_SPEC (object);
  index--;

#define DO_INDEX_OOP_PUT(type, cond, src)				\
    if COMMON (cond)							\
      {									\
        /* Find the number of bytes in the object.  */			\
        size_t maxByte = NUM_WORDS (object) * sizeof (PTR);		\
        if (sizeof (type) <= sizeof (PTR))				\
          maxByte -= (oop->flags & EMPTY_BYTES);			\
									\
        index =								\
          index * sizeof(type)						\
          + (instanceSpec >> ISP_NUMFIXEDFIELDS) * sizeof (PTR);	\
									\
        /* Check that we're on bounds.  */				\
        if UNCOMMON (index + sizeof(type) > maxByte)			\
          return (false);						\
									\
        /* Use a cast if unaligned accesses are ok, else memcpy.  */	\
        if (sizeof (type) <= sizeof (PTR))				\
	  {								\
	    type *destAddr = (type *) (((char *) object->data) + index);\
            *destAddr = (type) (src);					\
	  }								\
        else								\
	  {								\
	    char *destAddr = ((char *) object->data) + index;		\
	    type src_ = (type) (src);					\
            memcpy (destAddr, (char *) &src_, sizeof (type));		\
	  }								\
        return (true);							\
      }

  switch (instanceSpec & ISP_INDEXEDVARS)
    {
      case ISP_SCHAR: {
        DO_INDEX_OOP_PUT (int8_t,
			  IS_INT (value)
			  && TO_INT (value) >= -128
			  && TO_INT (value) <= 127,
			  TO_INT (value));
        return (false);
      }

      case ISP_UCHAR: {
        DO_INDEX_OOP_PUT (uint8_t,
			  IS_INT (value)
			  && TO_INT (value) >= 0
			  && TO_INT (value) <= 255,
			  TO_INT (value));
        return (false);
      }

      case ISP_SHORT: {
        DO_INDEX_OOP_PUT (uint16_t,
			  IS_INT (value)
			  && TO_INT (value) >= -32768
			  && TO_INT (value) <= 32767,
			  TO_INT (value));
	return (false);
      }

      case ISP_USHORT: {
        DO_INDEX_OOP_PUT (uint16_t,
			  IS_INT (value)
			  && TO_INT (value) >= 0
			  && TO_INT (value) <= 65535,
			  TO_INT (value));
	return (false);
      }

      case ISP_INT: {
        DO_INDEX_OOP_PUT (int32_t, is_c_int_32 (value), to_c_int_32 (value));
	return (false);
      }

      case ISP_UINT: {
        DO_INDEX_OOP_PUT (uint32_t, is_c_uint_32 (value), to_c_int_32 (value));
	return (false);
      }

      case ISP_FLOAT: {
        DO_INDEX_OOP_PUT (float, IS_INT (value), TO_INT (value));
        DO_INDEX_OOP_PUT (float, OOP_CLASS (value) = _gst_floate_class,
			  FLOATE_OOP_VALUE (value));
        DO_INDEX_OOP_PUT (float, OOP_CLASS (value) = _gst_floatd_class,
			  FLOATD_OOP_VALUE (value));
        DO_INDEX_OOP_PUT (float, OOP_CLASS (value) = _gst_floatq_class,
			  FLOATQ_OOP_VALUE (value));
        return (false);
      }

      case ISP_INT64: {
        DO_INDEX_OOP_PUT (int64_t, is_c_int_64 (value), to_c_int_64 (value));
	return (false);
      }

      case ISP_UINT64: {
        DO_INDEX_OOP_PUT (uint64_t, is_c_uint_64 (value), to_c_int_64 (value));
	return (false);
      }

      case ISP_DOUBLE: {
        DO_INDEX_OOP_PUT (double, IS_INT (value), TO_INT (value));
        DO_INDEX_OOP_PUT (double, OOP_CLASS (value) = _gst_floatd_class,
			  FLOATD_OOP_VALUE (value));
        DO_INDEX_OOP_PUT (double, OOP_CLASS (value) = _gst_floate_class,
			  FLOATE_OOP_VALUE (value));
        DO_INDEX_OOP_PUT (double, OOP_CLASS (value) = _gst_floatq_class,
			  FLOATQ_OOP_VALUE (value));
        return (false);
      }

      case ISP_POINTER:
        maxIndex = NUM_WORDS (object);
        index += instanceSpec >> ISP_NUMFIXEDFIELDS;
        if UNCOMMON (index >= maxIndex)
	  return (false);

        object->data[index] = value;
        return (true);
    }
#undef DO_INDEX_OOP_PUT

  return (false);
}

OOP
index_string_oop (OOP oop,
		  size_t index)
{
  intptr_t instanceSpec;
  mst_Object object;
  size_t maxIndex;

  if UNCOMMON (index < 1)
    return (NULL);

  object = OOP_TO_OBJ (oop);
  instanceSpec = GET_INSTANCE_SPEC (object);
  maxIndex = OBJECT_SIZE_BYTES (object) - (oop->flags & EMPTY_BYTES);
  index += (instanceSpec >> ISP_NUMFIXEDFIELDS) * sizeof (OOP);

  if UNCOMMON (index > maxIndex)
    return (NULL);

  return (CHAR_OOP_AT (((gst_uchar *) object->data)[index - 1]));
}

mst_Boolean
index_string_oop_put (OOP oop,
		      size_t index,
		      OOP value)
{
  intptr_t instanceSpec;
  mst_Object object;
  size_t maxIndex;

  if UNCOMMON (index < 1)
    return (false);

  object = OOP_TO_OBJ (oop);
  instanceSpec = GET_INSTANCE_SPEC (object);
  maxIndex = OBJECT_SIZE_BYTES (object) - (oop->flags & EMPTY_BYTES);
  index += (instanceSpec >> ISP_NUMFIXEDFIELDS) * sizeof (OOP);

  if UNCOMMON (index > maxIndex)
    return (false);

  ((gst_uchar *) object->data)[index - 1] = CHAR_OOP_VALUE (value);
  return (true);
}

OOP
inst_var_at (OOP oop,
	     int index)
{
  mst_Object object;

  object = OOP_TO_OBJ (oop);
  return (object->data[index - 1]);
}

void
inst_var_at_put (OOP oop,
		 int index,
		 OOP value)
{
  mst_Object object;

  object = OOP_TO_OBJ (oop);
  object->data[index - 1] = value;
}


mst_Boolean
is_c_int_32 (OOP oop)
{
  gst_byte_array ba;

  if COMMON (IS_INT (oop))
#if SIZEOF_OOP == 4
    return (true);
#else
    return (TO_INT (oop) >= INT_MIN && TO_INT (oop) < INT_MAX);
#endif

  ba = (gst_byte_array) OOP_TO_OBJ (oop);
  if (ba->objClass == _gst_large_negative_integer_class)
    return (NUM_INDEXABLE_FIELDS (oop) == 4);

  else if COMMON (ba->objClass == _gst_large_positive_integer_class)
    {
      switch (NUM_INDEXABLE_FIELDS (oop))
	{
	case 4:
	  return (true);
	case 5:
	  return (ba->bytes[4] == 0);
	}
    }

  return (false);
}

mst_Boolean
is_c_uint_32 (OOP oop)
{
  gst_byte_array ba;

  if COMMON (IS_INT (oop))
#if SIZEOF_OOP == 4
    return (TO_INT (oop) >= 0);
#else
    return (TO_INT (oop) >= 0 && TO_INT (oop) < INT_MAX);
#endif

  ba = (gst_byte_array) OOP_TO_OBJ (oop);
  if COMMON (ba->objClass == _gst_large_positive_integer_class)
    {
      switch (NUM_INDEXABLE_FIELDS (oop))
	{
	case 4:
	  return (true);
	case 5:
	  return (ba->bytes[4] == 0);
	}
    }

  return (false);
}

int32_t
to_c_int_32 (OOP oop)
{
  gst_byte_array ba;

  if COMMON (IS_INT (oop))
    return (TO_INT (oop));

  ba = (gst_byte_array) OOP_TO_OBJ (oop);
  return ((int32_t) ((((uint32_t) ba->bytes[3]) << 24) +
		     (((uint32_t) ba->bytes[2]) << 16) +
		     (((uint32_t) ba->bytes[1]) << 8) +
		      ((uint32_t) ba->bytes[0])));
}

OOP
from_c_int_32 (int32_t i)
{
  gst_byte_array ba;
  OOP oop;
  const uint32_t ui = (uint32_t) i;

  if COMMON (i >= MIN_ST_INT && i <= MAX_ST_INT)
    return (FROM_INT (i));

  if (i < 0)
    ba = (gst_byte_array) new_instance_with (_gst_large_negative_integer_class, 
					     4, &oop);
  else
    ba = (gst_byte_array) new_instance_with (_gst_large_positive_integer_class, 
					     4, &oop);

  ba->bytes[0] = (gst_uchar) ui;
  ba->bytes[1] = (gst_uchar) (ui >> 8);
  ba->bytes[2] = (gst_uchar) (ui >> 16);
  ba->bytes[3] = (gst_uchar) (ui >> 24);
  return (oop);
}

OOP
from_c_uint_32 (uint32_t ui)
{
  gst_byte_array ba;
  OOP oop;

  if COMMON (ui <= MAX_ST_INT)
    return (FROM_INT (ui));

  if UNCOMMON (((intptr_t) ui) < 0)
    {
      ba = (gst_byte_array) 
        new_instance_with (_gst_large_positive_integer_class, 
			   5, &oop);

      ba->bytes[4] = 0;
    }
  else
    ba = (gst_byte_array) 
      new_instance_with (_gst_large_positive_integer_class, 
	 		 4, &oop);

  ba->bytes[0] = (gst_uchar) ui;
  ba->bytes[1] = (gst_uchar) (ui >> 8);
  ba->bytes[2] = (gst_uchar) (ui >> 16);
  ba->bytes[3] = (gst_uchar) (ui >> 24);

  return (oop);
}


mst_Boolean
is_c_int_64 (OOP oop)
{
  gst_byte_array ba;

  if COMMON (IS_INT (oop))
    return (true);

  ba = (gst_byte_array) OOP_TO_OBJ (oop);
  if (ba->objClass == _gst_large_negative_integer_class)
    return (NUM_INDEXABLE_FIELDS (oop) == 8);

  else if COMMON (ba->objClass == _gst_large_positive_integer_class)
    {
      switch (NUM_INDEXABLE_FIELDS (oop))
	{
	case 8:
	  return (true);
	case 9:
	  return (ba->bytes[8] == 0);
	}
    }

  return (false);
}

mst_Boolean
is_c_uint_64 (OOP oop)
{
  gst_byte_array ba;

  if COMMON (IS_INT (oop))
    return (TO_INT (oop) >= 0);

  ba = (gst_byte_array) OOP_TO_OBJ (oop);
  if COMMON (ba->objClass == _gst_large_positive_integer_class)
    {
      switch (NUM_INDEXABLE_FIELDS (oop))
	{
	case 8:
	  return (true);
	case 9:
	  return (ba->bytes[8] == 0);
	}
    }

  return (false);
}

int64_t
to_c_int_64 (OOP oop)
{
  gst_byte_array ba;

  if COMMON (IS_INT (oop))
    return (TO_INT (oop));

  ba = (gst_byte_array) OOP_TO_OBJ (oop);
  return ((int64_t) (
		   (((uint64_t) ba->bytes[7]) << 56) +
		   (((uint64_t) ba->bytes[6]) << 48) +
		   (((uint64_t) ba->bytes[5]) << 40) +
		   (((uint64_t) ba->bytes[4]) << 32) +
		   (((uint64_t) ba->bytes[3]) << 24) +
		   (((uint64_t) ba->bytes[2]) << 16) +
		   (((uint64_t) ba->bytes[1]) << 8) +
		   ((uint64_t) ba->bytes[0])));
}

OOP
from_c_int_64 (int64_t i)
{
  gst_byte_array ba;
  OOP oop;
  const uint64_t ui = (uint64_t) i;

  if COMMON (i >= MIN_ST_INT && i <= MAX_ST_INT)
    return (FROM_INT (i));

  if (i < 0)
    ba = (gst_byte_array) new_instance_with (_gst_large_negative_integer_class, 
					     8, &oop);
  else
    ba = (gst_byte_array) new_instance_with (_gst_large_positive_integer_class, 
					     8, &oop);

  ba->bytes[0] = (gst_uchar) ui;
  ba->bytes[1] = (gst_uchar) (ui >> 8);
  ba->bytes[2] = (gst_uchar) (ui >> 16);
  ba->bytes[3] = (gst_uchar) (ui >> 24);
  ba->bytes[4] = (gst_uchar) (ui >> 32);
  ba->bytes[5] = (gst_uchar) (ui >> 40);
  ba->bytes[6] = (gst_uchar) (ui >> 48);
  ba->bytes[7] = (gst_uchar) (ui >> 56);

  return (oop);
}

OOP
from_c_uint_64 (uint64_t ui)
{
  gst_byte_array ba;
  OOP oop;

  if COMMON (ui <= MAX_ST_INT)
    return (FROM_INT (ui));

  if UNCOMMON (((int64_t) ui) < 0)
    {
      ba = (gst_byte_array) 
        new_instance_with (_gst_large_positive_integer_class, 
			   9, &oop);

      ba->bytes[8] = 0;
    }
  else
    ba = (gst_byte_array) 
      new_instance_with (_gst_large_positive_integer_class, 
	 		 8, &oop);

  ba->bytes[0] = (gst_uchar) ui;
  ba->bytes[1] = (gst_uchar) (ui >> 8);
  ba->bytes[2] = (gst_uchar) (ui >> 16);
  ba->bytes[3] = (gst_uchar) (ui >> 24);
  ba->bytes[4] = (gst_uchar) (ui >> 32);
  ba->bytes[5] = (gst_uchar) (ui >> 40);
  ba->bytes[6] = (gst_uchar) (ui >> 48);
  ba->bytes[7] = (gst_uchar) (ui >> 56);

  return (oop);
}
