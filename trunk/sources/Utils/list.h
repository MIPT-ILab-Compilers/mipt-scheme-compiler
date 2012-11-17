/**
 * @file: list.h 
 * List-related functionality implementation
 * @defgroup List Two-way linked list
 *
 * Implementation of two-way linked list
 * @ingroup Utils
 */
/*
 * Utils library in scheme compiler project
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */
#ifndef LIST_H
#define LIST_H

/**
 * @brief Types of direction in lists.
 * @ingroup List  
 *
 * Lists are built from left to right by default.
 * That means if you take next in default direction - it will be element to the right.
 */
enum ListDir
{
    /** Right direction */
    LIST_DIR_RIGHT = 0,
    /** Default direction */
    LIST_DIR_DEFAULT = LIST_DIR_RIGHT,
    /** Left Direction */
    LIST_DIR_LEFT = 1,
    /** Direction reverse to default */
    LIST_DIR_RDEFAULT = LIST_DIR_LEFT,
    /** Number of directions */
    LIST_DIR_NUM = 2
};

/**
 * Return direction that is reverse to given one
 * @ingroup List
 */
inline ListDir
ListRDir( ListDir dir)
{
    UTILS_ASSERTD( LIST_DIR_NUM == 2);
    return ( dir == LIST_DIR_DEFAULT)? LIST_DIR_RDEFAULT: LIST_DIR_DEFAULT; 
}

/**
 * @brief Tagged list template. User class (e.g. class A) should
 *        inherit from ListItem (e.g. class A: public ListItem< A, AListClassTag>{})
 * @ingroup List
 */
template <class Data, typename tag> class ListItem
{
    Data * peer[ LIST_DIR_NUM];
    
    /** Get neighbour */
    inline Data * peerInDir( ListDir dir) const
    {
        return peer[ dir];
    }
    
    /** Set neighbour */
    inline void setPeerInDir( Data *p, ListDir dir)
    {
        peer[ dir] = p;
    }
	/** Set all pointeers to peeers to zero */
    inline void zeroLinks()
    {
        setPeerInDir( NULL, LIST_DIR_DEFAULT);
        setPeerInDir( NULL, LIST_DIR_RDEFAULT);
    }

	/** Set next peer */
    inline void setNext( Data *n)
    {
        setPeerInDir( n, LIST_DIR_DEFAULT);
    }
    /** Set previous peer */
    inline void setPrev( Data *p)
    {
        setPeerInDir( p, LIST_DIR_RDEFAULT);
    }
public:
        
    /* Default peers gets */
    /** Return next peer in default direction */
    inline Data *next() const
    {
        return peerInDir( LIST_DIR_DEFAULT);
    }
    /** Return prev peer in default direction */
    inline Data* prev() const
    {
        return peerInDir( LIST_DIR_RDEFAULT);
    }
       
    /** Attach this item to peeer in give direction */
    inline void attachInDir( Data* p, ListDir dir)
    {
        ListDir rdir = ListRDir( dir);
        setPeerInDir( p, dir);
        setPeerInDir( NULL, rdir);

		/* Type conversion here are needed for disambiguation */
        if ( isNotNullP( p))
        {
            Data* rdir_peer =  ((ListItem* )p)->peerInDir( rdir);
            if ( isNotNullP( rdir_peer))
            {
                ((ListItem*)rdir_peer)->setPeerInDir( static_cast< Data *>(this), dir);
            }
            ( (ListItem*)p)->setPeerInDir( static_cast< Data *>(this), rdir);
            setPeerInDir( rdir_peer, rdir);
        }
    }
    
    /** Attach in default direction */
    inline void attach( Data* peer)
    {
        attachInDir( peer, LIST_DIR_DEFAULT);
    }

    /** Detach from neighbours */
    inline void detach()
    {
        /* Correct links in peers */
        if ( isNotNullP( peer[ LIST_DIR_DEFAULT]))
        {
            ((ListItem *)peer[ LIST_DIR_DEFAULT])
				->setPeerInDir( peer[ LIST_DIR_RDEFAULT], LIST_DIR_RDEFAULT);
        }
        if ( isNotNullP( peer[ LIST_DIR_RDEFAULT]))
        {
            ((ListItem *)peer[ LIST_DIR_RDEFAULT])
				->setPeerInDir( peer[ LIST_DIR_DEFAULT], LIST_DIR_DEFAULT);
        }
        setPeerInDir( NULL, LIST_DIR_DEFAULT);
        setPeerInDir( NULL, LIST_DIR_RDEFAULT);
    }

    /** Default constructor */
    ListItem()
    {
        zeroLinks();
    };

    /** Insert element before the given one */
    ListItem( Data *peer)
    {
        zeroLinks();
        attachInDir( peer, LIST_DIR_DEFAULT);
    }

    /** Insert element in given direction */
    ListItem( Data *peer, ListDir dir)
    {
        zeroLinks();
        attachInDir( peer, dir);
    }

    /** Destructor */
    virtual ~ListItem()
    {
        detach();
    }
};


#endif
