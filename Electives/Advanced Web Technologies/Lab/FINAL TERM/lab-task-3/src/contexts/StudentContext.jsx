import React, { createContext, useContext, useState, useMemo, useEffect } from 'react'

const StudentContext = createContext()

const RAW_STUDENTS = [
  {
    id: 'STD001',
    name: 'Alice Chen',
    gpa: 3.85,
    major: 'Computer Science',
    avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=Alice',
    courses: ['React Fundamentals', 'Data Structures', 'Algorithms'],
  },
  {
    id: 'STD002',
    name: 'Bob Martinez',
    gpa: 3.42,
    major: 'Software Engineering',
    avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=Bob',
    courses: ['Web Development', 'Database Systems', 'Software Design'],
  },
  {
    id: 'STD003',
    name: 'Carol Zhang',
    gpa: 3.96,
    major: 'Information Systems',
    avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=Carol',
    courses: ['Business Analytics', 'Project Management', 'Cloud Computing'],
  },
  {
    id: 'STD004',
    name: 'David Kim',
    gpa: 3.71,
    major: 'Cybersecurity',
    avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=David',
    courses: ['Network Security', 'Cryptography', 'Ethical Hacking'],
  },
]

export function StudentProvider({ children }) {
  // --- State ---
  const [allStudents, setAllStudents] = useState(() => {
    const saved = localStorage.getItem('students')
    return saved ? JSON.parse(saved) : RAW_STUDENTS
  })
  const [searchQuery, setSearchQuery] = useState('')
  const [sortPreference, setSortPreference] = useState('default')
  const [favorites, setFavorites] = useState(() => {
    const saved = localStorage.getItem('favorites')
    return saved ? new Set(JSON.parse(saved)) : new Set()
  })

  // --- Persistence ---
  useEffect(() => {
    localStorage.setItem('students', JSON.stringify(allStudents))
  }, [allStudents])

  useEffect(() => {
    localStorage.setItem('favorites', JSON.stringify([...favorites]))
  }, [favorites])

  // --- Derived: filtered & sorted ---
  const displayedStudents = useMemo(() => {
    let result = allStudents.filter((s) => {
      const q = searchQuery.toLowerCase()
      return s.name.toLowerCase().includes(q) || s.major.toLowerCase().includes(q)
    })
    if (sortPreference === 'name-asc') result.sort((a, b) => a.name.localeCompare(b.name))
    else if (sortPreference === 'gpa-desc') result.sort((a, b) => b.gpa - a.gpa)
    return result
  }, [allStudents, searchQuery, sortPreference])

  // --- Handlers ---
  const addStudent = (student) => {
    setAllStudents(prev => [...prev, student])
  }

  const removeStudent = (studentId) => {
    setAllStudents(prev => prev.filter(s => s.id !== studentId))
    setFavorites(prev => {
      const next = new Set(prev)
      next.delete(studentId)
      return next
    })
  }

  const toggleFavorite = (studentId) => {
    setFavorites(prev => {
      const next = new Set(prev)
      next.has(studentId) ? next.delete(studentId) : next.add(studentId)
      return next
    })
  }

  const value = {
    allStudents,
    displayedStudents,
    searchQuery,
    setSearchQuery,
    sortPreference,
    setSortPreference,
    favorites,
    addStudent,
    removeStudent,
    toggleFavorite,
  }

  return (
    <StudentContext.Provider value={value}>
      {children}
    </StudentContext.Provider>
  )
}

export const useStudents = () => {
  const ctx = useContext(StudentContext)
  if (!ctx) throw new Error('useStudents must be used within a StudentProvider')
  return ctx
}
