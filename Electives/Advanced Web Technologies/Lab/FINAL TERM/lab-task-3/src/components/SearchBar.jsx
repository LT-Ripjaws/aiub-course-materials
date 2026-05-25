import React from 'react'
import PropTypes from 'prop-types'
import { useStudents } from '../contexts/StudentContext'

function SearchBar() {
  const { searchQuery, setSearchQuery } = useStudents()

  return (
    <div style={{ marginBottom: '1.5rem' }}>
      <label htmlFor="search-input" className="sr-only">
        Search students
      </label>
      <input
        id="search-input"
        type="text"
        placeholder="Search students by name or major..."
        value={searchQuery}
        onChange={(e) => setSearchQuery(e.target.value)}
        className="search-bar"
        style={{
          width: '100%',
          maxWidth: '400px',
          padding: '12px 16px',
          fontSize: '0.95rem',
          border: '2px solid var(--color-border)',
          borderRadius: 'var(--radius-md)',
          outline: 'none',
          transition: 'border-color 0.2s',
        }}
        onFocus={(e) => e.target.style.borderColor = 'var(--color-primary)'}
        onBlur={(e) => e.target.style.borderColor = 'var(--color-border)'}
      />
    </div>
  )
}

SearchBar.propTypes = {}

export default SearchBar
