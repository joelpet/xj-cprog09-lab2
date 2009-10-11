namespace lab2 {

    /* A note on 'public' before 'Date' below:
     * The public access specifier may be replaced by
     * any one of the other access specifiers
     * protected and private. This access specifier
     * limits the most accessible level for the
     * members inherited from the base class: The
     * members with a more accessible level are
     * inherited with this level instead, while the
     * members with an equal or more restrictive
     * access level keep their restrictive level in
     * the derived class. 
     */
    
    /**
     * DateCommon offers an extra layer between any class that
     * implements Date and the Date class itself. This is so that 
     * code that may be common to two or more implementing classes 
     * but does not fit in base class Date do not have to be
     * duplicated.
     */
    class DateCommon : public Date {
    
    }

}
