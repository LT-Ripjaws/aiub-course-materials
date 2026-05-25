import React, { useState, useEffect, useMemo } from 'react'
import DashboardHeader from './components/DashboardHeader'
import StudentCard from './components/StudentCard'
import SearchBar from './components/SearchBar'
import SortControls from './components/SortControls'
import './index.css'

const RAW_STUDENTS = [
  { id: 'STD001', name: 'Alice Chen', gpa: 3.85, major: 'Computer Science', avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=Alice', courses: ['React Fundamentals', 'Data Structures', 'Algorithms'] },
  { id: 'STD002', name: 'Bob Martinez', gpa: 3.42, major: 'Software Engineering', avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=Bob', courses: ['Web Development', 'Database Systems', 'Software Design'] },
  { id: 'STD003', name: 'Carol Zhang', gpa: 3.96, major: 'Information Systems', avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=Carol', courses: ['Business Analytics', 'Project Management', 'Cloud Computing'] },
  { id: 'STD004', name: 'David Kim', gpa: 3.71, major: 'Cybersecurity', avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=David', courses: ['Network Security', 'Cryptography', 'Ethical Hacking'] },
]

function App() {
  const [students, setStudents] = useState([])
  const [isLoading, setIsLoading] = useState(true)
  const [searchQuery, setSearchQuery] = useState('')
  const [favorites, setFavorites] = useState(new Set())
  const [sortPreference, setSortPreference] = useState('default')

  // 1. Simulated API fetch (1.5s delay)
  useEffect(() => {
    setIsLoading(true)
    const timer = setTimeout(() => {
      setStudents(RAW_STUDENTS)
      setIsLoading(false)
    }, 1500)
    return () => clearTimeout(timer)
  }, [])

  // 2. Dynamic document title
  useEffect(() => {
    const filtered = students.filter((s) => {
      const q = searchQuery.toLowerCase()
      return s.name.toLowerCase().includes(q) || s.major.toLowerCase().includes(q)
    })
    document.title = filtered.length === 0 
      ? 'Student Dashboard — No Results'
      : `Student Dashboard — ${filtered.length} Student${filtered.length === 1 ? '' : 's'}`
  }, [students, searchQuery])

  // 3. Derived: filtered + sorted students
  const displayedStudents = useMemo(() => {
    let result = students.filter((s) => {
      const q = searchQuery.toLowerCase()
      return s.name.toLowerCase().includes(q) || s.major.toLowerCase().includes(q)
    })
    if (sortPreference === 'name-asc') result.sort((a, b) => a.name.localeCompare(b.name))
    else if (sortPreference === 'gpa-desc') result.sort((a, b) => b.gpa - a.gpa)
    return result
  }, [students, searchQuery, sortPreference])

  // Handlers
  const handleToggleFavorite = (studentId) => {
    setFavorites((prev) => {
      const next = new Set(prev)
      next.has(studentId) ? next.delete(studentId) : next.add(studentId)
      return next
    })
  }

  return (
    <div className="app">
      <DashboardHeader 
        title="Student Dashboard" 
        tagline="Track academic progress and course enrollments"
        extra={<div style={{ marginTop: '12px', fontSize: '0.9rem', color: 'rgba(255,255,255,0.85)' }}>
          ❤️ {favorites.size} favorite{favorites.size === 1 ? '' : 's'}
        </div>}
      />

      <main className="dashboard-grid" style={{ paddingTop: '2rem' }}>
        {isLoading ? (
          <div className="no-data" style={{ gridColumn: '1 / -1' }}>
            <div style={{ fontSize: '3rem', marginBottom: '1rem' }}>⏳</div>
            <h2>Loading student data...</h2>
            <p>Please wait while we fetch the latest information.</p>
          </div>
        ) : displayedStudents.length === 0 ? (
          <div className="no-data" style={{ gridColumn: '1 / -1' }}>
            <div style={{ fontSize: '3rem', marginBottom: '1rem' }}>🔍</div>
            <h2>No students found</h2>
            <p>Try adjusting your search query.</p>
          </div>
        ) : (
          displayedStudents.map((student) => (
            <StudentCard
              key={student.id}
              name={student.name}
              id={student.id}
              avatar={student.avatar}
              gpa={student.gpa}
              major={student.major}
              courses={student.courses}
              isFavorite={favorites.has(student.id)}
              onToggleFavorite={() => handleToggleFavorite(student.id)}
            />
          ))
        )}
      </main>

      {/* Fixed bottom controls */}
      <div style={{
        position: 'fixed', bottom: 0, left: 0, right: 0,
        backgroundColor: 'var(--color-surface)',
        borderTop: '1px solid var(--color-border)',
        padding: '16px 24px',
        display: 'flex', justifyContent: 'space-between', alignItems: 'center',
        flexWrap: 'wrap', gap: '12px',
        boxShadow: '0 -2px 8px rgba(0,0,0,0.08)', zIndex: 100,
      }}>
        <SearchBar searchQuery={searchQuery} onSearchChange={setSearchQuery} />
        <SortControls sortPreference={sortPreference} onSortChange={setSortPreference} />
      </div>

      {/* Spacer for fixed bar */}
      <div style={{ height: '120px' }} />
    </div>
  )
}

export default App
