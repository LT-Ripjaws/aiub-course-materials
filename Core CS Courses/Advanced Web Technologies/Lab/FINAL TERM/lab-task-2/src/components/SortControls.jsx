import React from 'react'
import PropTypes from 'prop-types'

function SortControls({ sortPreference, onSortChange }) {
  const options = [
    { value: 'default', label: 'Default Order' },
    { value: 'name-asc', label: 'Name (A–Z)' },
    { value: 'gpa-desc', label: 'GPA (High → Low)' },
  ]

  return (
    <div style={{ marginBottom: '1.5rem', display: 'flex', alignItems: 'center', gap: '12px' }}>
      <label htmlFor="sort-select" className="sort-label">
        Sort by:
      </label>
      <select
        id="sort-select"
        value={sortPreference}
        onChange={(e) => onSortChange(e.target.value)}
        style={{
          padding: '8px 12px',
          fontSize: '0.9rem',
          border: '1px solid var(--color-border)',
          borderRadius: 'var(--radius-sm)',
          backgroundColor: 'var(--color-surface)',
          color: 'var(--color-text)',
          cursor: 'pointer',
        }}
      >
        {options.map((opt) => (
          <option key={opt.value} value={opt.value}>
            {opt.label}
          </option>
        ))}
      </select>
    </div>
  )
}

SortControls.propTypes = {
  sortPreference: PropTypes.oneOf(['default', 'name-asc', 'gpa-desc']).isRequired,
  onSortChange: PropTypes.func.isRequired,
}

export default SortControls
