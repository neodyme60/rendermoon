#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_CLASS__
#define __RENDERMOON_CORE_CLASS__

#include <string>

class Object;
class Stream;
class InstanceManager;

class Class {
public:
    Class(const std::string &name, bool abstract, const std::string &superClassName, void *instPtr = NULL, void *unSerPtr = NULL);

    /// Return the name of the represented class
    inline const std::string &getName() const { return m_name; }

    inline bool isAbstract() const { return m_abstract; }

    /// Does the class support instantiation over RTTI?
    inline bool isInstantiable() const { return m_instPtr != NULL; }

    /// Does the class support serialization?
    inline bool isSerializable() const { return m_unSerPtr != NULL; }

    /** \brief Return the Class Object associated with the parent
     * class of NULL if it does not have one.
     */
    inline const Class *getSuperClass() const { return m_superClass; }

    // Check whether this class derives from a theClass
    bool derivesFrom(const Class *theClass) const;

    // Look up a class by its name
    static const Class *forName(const std::string &name);

    /** \brief Look up a class by its name. Avoids allocating
     * heap space by taking a character array as parameter
     */
    static const Class *forName(const char *name);

    /** \brief Unserialize an instance of the class (if this is
     * supported).
     */
    Object *unserialize(Stream *stream = NULL, InstanceManager *manager = NULL) const;

    /// Generate an instance of this class (if this is supported)
    Object *instantiate() const;

    /// Check if the RTTI layer has been initialized
    static inline bool rttiIsInitialized() { return m_isInitialized; }

    /** \brief Initializes the built-in RTTI and creates
     * a list of all compiled classes
     */
    static void staticInitialization();

    /// Free the memory taken by staticInitialization()
    static void staticShutdown();
private:
    /** \brief Initialize a class - called by
     * staticInitialization()
     */
    static void initializeOnce(Class *theClass);
private:
    std::string m_name;
    bool m_abstract;
    Class *m_superClass;
    std::string m_superClassName;
    void *m_instPtr, *m_unSerPtr;
    static bool m_isInitialized;
};

#define MTS_CLASS(x) x::m_theClass

#define MTS_DECLARE_CLASS() \
	virtual const Class *getClass() const; \
public: \
	static Class *m_theClass;


#define MTS_IMPLEMENT_CLASS(name, abstract, super) \
	Class *name::m_theClass = new Class(#name, abstract, #super); \
	const Class *name::getClass() const { \
		return m_theClass;\
	}

#define MTS_IMPLEMENT_CLASS_I(name, abstract, super) \
	Object *__##name ##_inst() { \
		return new name(); \
	} \
	Class *name::m_theClass = new Class(#name, abstract, #super, (void *) &__##name ##_inst, NULL); \
	const Class *name::getClass() const { \
		return m_theClass;\
	}

#define MTS_IMPLEMENT_CLASS_S(name, abstract, super) \
	Object *__##name ##_unSer(Stream *stream, InstanceManager *manager) { \
		return new name(stream, manager); \
	} \
	Class *name::m_theClass = new Class(#name, abstract, #super, NULL, (void *) &__##name ##_unSer); \
	const Class *name::getClass() const { \
		return m_theClass;\
	}

#define MTS_IMPLEMENT_CLASS_IS(name, abstract, super) \
	Object *__##name ##_unSer(Stream *stream, InstanceManager *manager) { \
		return new name(stream, manager); \
	} \
	Object *__##name ##_inst() { \
		return new name(); \
	} \
	Class *name::m_theClass = new Class(#name, abstract, #super, (void *) &__##name ##_inst, (void *) &__##name ##_unSer); \
	const Class *name::getClass() const { \
		return m_theClass;\
	}


#endif
