<?php

namespace it\icosaedro\containers;

require_once __DIR__ . '/../../../autoload.php';

/**
	Objects that may be compared for equality and that may be hashed
	should implement this interface. Hashing allows to implement fast
	algorithms of data search, as the HashSet and the HashMap.
	@author Umberto Salsi <salsi@icosaedro.it>
	@version $Date: 2012/01/28 20:27:32 $
*/
interface Hashable extends Comparable {

	/**
		Returns the hash of the object.
		The hash value must be consistent with the equality test, that is if
		two distinct objects carries the same value, then the resulting hash
		must be the same: if <code>$a->equals($b)</code> then
		<code>$a->getHash() === $b->getHash()</code> must be true as well.
		Also remember that if two objects result to be equal to each other,
		then the hash value must be the same.
		Moreover, the objects, once defined, must be immutable, so that
		the hash of a given object never change.
		@return int The hash.
	*/
	function getHash();

}
