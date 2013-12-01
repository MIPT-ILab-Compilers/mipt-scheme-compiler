/**
  * @file:basic_block_inline.hpp
  * Implementation of basic block
  */
/**
  * Copyrigth (C) 2013 MIPT Scheme Compiler team
  */

namespace ir
{

/** Return basic block id */
inline BasicBlockUid BasicBlock::id() const
{
    return this->id_;
}

/** Get Prev basic block */
inline const BasicBlock* BasicBlock::prev() const
{
    return this->prev_;
}

/** Get Next basic Block */
inline const BasicBlock* BasicBlock::next() const
{
    return this->next_;
}

/** Return the last added operation */
inline const Operation BasicBlock::lastOperation()
{
    return *( operations_.end());
}

/** Set prev basic block */
inline void BasicBlock::setPrevBlock( BasicBlock& prev)
{
   prev_ = &prev;
}

/** Set next basic block */
inline void BasicBlock::setNextBlock( BasicBlock& next)
{
    next_ = &next;
}

/** Add an operation in basic block */
inline void BasicBlock::addOperation( const Operation& op)
{
    operations_.push_back( op);
}

/** Add the basic block in the output stream s */
inline void BasicBlock::toStream( ostream& s) const
{
    s << "Basic Block [" << id() << "]" << endl;
    s << "prev Block: [";
    if ( prev_ != NULL )
        s << prev_->id();
    else
        s << "none";
    s << "]; next Block: [";
    if ( next_ != NULL )
        s << next_->id();
    else
        s << "none";
    s << "];";
    for ( list<Operation>::const_iterator i = operations_.begin(); i != operations_.end(); ++i )
    {
        s << endl << *i;
    }
}

inline ostream& operator<<( ostream& s, const BasicBlock& bb)
{
    bb.toStream( s);
    return s;
}

}//namespace ir
